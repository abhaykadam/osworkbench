/*
	File Implements the Virtual Memory related functions
*/
#include "includes.h"

void page_fault_handler (VirtualMemory** VMptr, Process* p, int opcode, int page_no);

VirtualMemory* init_VirtualMemory ()
{
	int i;
	VirtualMemory* VMem = (VirtualMemory*) malloc (sizeof (VirtualMemory));
	//allocate the space for the page table. When a process is created then the process page table is pointer from this.
	VMem->global_page_table = (int***) malloc (MAXFRAMENO*sizeof (int**));
	VMem->page_ref_time_stamp = 0; //No page reference has been made till now
	pthread_mutex_init (&VMem->global_page_table_mutex,NULL);
	VMem->free_frame_list = (free_frame_list_t*) malloc (sizeof (free_frame_list_t));
	VMem->free_frame_list->free_frame_nos = (int*) malloc (sizeof (int)*MAXFRAMENO);
	for (i=0;i<MAXFRAMENO;i++)
		VMem->free_frame_list->free_frame_nos[i] = i;	
	VMem->free_frame_list->free_frame_count = MAXFRAMENO-1;
	pthread_mutex_init (&VMem->free_frame_list_mutex,NULL);
	VMem->swap_page_map = (int*) malloc (sizeof (int)*MAXFRAMENO);
	pthread_mutex_init (&VMem->swap_page_map_mutex,NULL);
	
	VMem->IO_table = (IO_table_t*) malloc  (sizeof (IO_table_t));
	VMem->IO_table->IO_req_table = (int**) malloc (sizeof (int*)*MAXIOBUFFER);
	for (i=0;i<MAXIOBUFFER;i++)
	{
		VMem->IO_table->IO_req_table[i] = (int*) malloc (sizeof (int)*5);
	}
	VMem->IO_table->front = VMem->IO_table->rear = 0;
	VMem->IO_table->count_req = 0; //There is no request till now.
	pthread_mutex_init (&VMem->IO_table_mutex,NULL);
	printf ("VIRTUAL MEMORY INITIALIZED\n");
	return VMem;
}

int get_free_frame (VirtualMemory** VMptr)
{
	int frame_no;
	VirtualMemory* VM = *VMptr;
	pthread_mutex_lock (&VM->free_frame_list_mutex);
		if (VM->free_frame_list->free_frame_count > 0)
		{
			frame_no = VM->free_frame_list->free_frame_nos[VM->free_frame_list->free_frame_count];
//			printf ("GET FREE FRAME :: count:%d free_frame:%d\n",VM->free_frame_list->free_frame_count,frame_no);
			VM->free_frame_list->free_frame_nos[VM->free_frame_list->free_frame_count] = 0;
			VM->free_frame_list->free_frame_count--;
		}
		else
		{
			printf ("No Frame is free now.\n");
			frame_no = -1;
		}
	pthread_mutex_unlock (&VM->free_frame_list_mutex);
	return frame_no;
}

void init_VirtualMemory_process (VirtualMemory** VMem_ptr, Process* p, int process_size, int page_frames_allocated)
{
	VirtualMemory* VM = *VMem_ptr;
	int i, free_frame;
	int internal_id = p->internal_id;
	pthread_mutex_lock (&VM->global_page_table_mutex);
		VM->global_page_table[p->internal_id] = (int**) malloc (sizeof (int*)*(process_size+2));
		for (i=1;i<=process_size;i++)
		{
			VM->global_page_table[p->internal_id][i] = (int*) malloc (4*sizeof (int));
		}
		//printf ("page table allocated for process:%d\n",p->internal_id);
		for (i=1;i<=page_frames_allocated;i++)
		{
			free_frame = get_free_frame(VMem_ptr);
			//printf ("PROC:%d frame:%d\n",p->internal_id,free_frame);
			VM->global_page_table[internal_id][i][0] = free_frame;
			VM->global_page_table[internal_id][i][1] = 1; //VALID bit
			VM->global_page_table[internal_id][i][2] = 0; //DIRTY bit
			VM->global_page_table[internal_id][i][3] = 0; //TIMESTAMP of last access
		}
		VM->global_page_table[p->internal_id][process_size+1] = (int*) malloc (sizeof (int));
		VM->global_page_table[internal_id][process_size+1][0] = -1;
	pthread_mutex_unlock (&VM->global_page_table_mutex);
	//printf ("page table init completed for process:%d\n",p->internal_id);
	pthread_mutex_lock (&VM->swap_page_map_mutex);
		VM->swap_page_map[p->internal_id]= p->internal_id;
	pthread_mutex_unlock (&VM->swap_page_map_mutex);
	//printf ("swap space allocated for process:%d\n",p->internal_id);
}

void display_page_table_for_process (VirtualMemory*VM, Process* p)
{
	int i, len = p->process_size;
	unsigned internal_id = p->internal_id;
	printf ("PAGE TABLE FOR: %d\n",internal_id);
	printf (" PAGE# | Frame# |Valid|Dirty|time\n------------------------------------------\n");
	pthread_mutex_lock (&VM->global_page_table_mutex);
		for (i=1;i<=len;i++)
		{
			printf ("%d |%d | %d |  %d  |  %d  |\n",i,VM->global_page_table[p->internal_id][i][0],VM->global_page_table[p->internal_id][i][1],VM->global_page_table[p->internal_id][i][2],VM->global_page_table[p->internal_id][i][3]);
		}
	pthread_mutex_unlock (&VM->global_page_table_mutex);
}

/*
	Works as Memory Management Unit. 
	Returns 1: Page number not available
	Returns 2: successfully accessed
	Returns 3: Page fault occured and handled
*/
int MMU (VirtualMemory** VMptr,Process* p,int page_no,int word_no,int accessbit)
{
	int valid_bit;
	int ret_val;
	VirtualMemory* VM = *VMptr;
	if (page_no > p->process_size || p->process_size <= 0)
	{
		ret_val = 1;
	}
	pthread_mutex_lock (&VM->global_page_table_mutex);
		valid_bit = VM->global_page_table[p->internal_id][page_no][1];
		if (valid_bit == 1)
		{
			//pthread_mutex_lock (&VM->global_page_table_mutex);
				VM->page_ref_time_stamp++;
			//pthread_mutex_unlock (&VM->global_page_table_mutex);
			ret_val = 2;
			if (accessbit == 1)
			{
				//pthread_mutex_lock (&VM->global_page_table_mutex);
					printf ("PROCESS:%d PAGE %d ACCESSED FROM MEMORY. FRAME: %d TimeStamp:%d free frame in memory:%d\n",p->internal_id, page_no, VM->global_page_table[p->internal_id][page_no][0],VM->page_ref_time_stamp,VM->free_frame_list->free_frame_count);
					VM->global_page_table[p->internal_id][page_no][3] = VM->page_ref_time_stamp; //Put the last referenced time stamp value
				//pthread_mutex_unlock (&VM->global_page_table_mutex);
			}
			else if (accessbit == 2)
			{
				//pthread_mutex_lock (&VM->global_page_table_mutex);
					printf ("PROCESS:%d PAGE ACCESSED FROM MEMORY. FRAME: %d \n",p->internal_id,VM->global_page_table[p->internal_id][page_no][0]);
					VM->global_page_table[p->internal_id][page_no][3]=VM->page_ref_time_stamp; //Put the time stamp when it was last referenced
					VM->global_page_table[p->internal_id][page_no][2]=1; //dirty bit is set as the page is modified.
				//pthread_mutex_unlock (&VM->global_page_table_mutex);
			}
		}
		else if (valid_bit == 0)
		{
			ret_val = 3;
			printf ("PAGE FAULt from Proc:%d\n",p->internal_id);
			//pthread_mutex_unlock (&VM->global_page_table_mutex);
			page_fault_handler (&VM,p,1,page_no);
		}
	pthread_mutex_unlock (&VM->global_page_table_mutex);
	return ret_val;
}

void page_fault_handler (VirtualMemory** VMptr, Process* p, int opcode, int page_no)
{
	printf ("page_fault_handler(): \n");
	insert_IO_req (VMptr,p,opcode,page_no,0);
	printf ("IO REQ inserted in table. Proc:%d for Page:%d\n",p->internal_id,page_no);
	//blocks this process.
	io_start (p);
	pthread_mutex_unlock (&(*VMptr)->global_page_table_mutex);
	pthread_mutex_lock (&p->IO_mutex);
		pthread_cond_wait (&p->IO_cond_var,&p->IO_mutex);
	pthread_mutex_unlock (&p->IO_mutex);
	pthread_mutex_lock (&(*VMptr)->global_page_table_mutex);
	printf ("IO REQ served. Process:%d page_no:%d\n",p->internal_id,page_no);
	//display_page_table_for_process (*VMptr,p);
	pthread_mutex_lock (&mutex1); //In io_start this mutex1 was unlocked.
}
/*
Insert a IO request in the IO table
*/
void insert_IO_req (VirtualMemory** VMptr, Process* p, int opcode, int page_no, int frame_no)
{
	VirtualMemory* VM = *VMptr;
	pthread_mutex_lock (&VM->IO_table_mutex);
		VM->IO_table->IO_req_table[VM->IO_table->rear][0] = opcode;
		VM->IO_table->IO_req_table[VM->IO_table->rear][1] = 0;
		VM->IO_table->IO_req_table[VM->IO_table->rear][2] = p->internal_id;
		VM->IO_table->IO_req_table[VM->IO_table->rear][3] = page_no;
		VM->IO_table->IO_req_table[VM->IO_table->rear][4] = frame_no;
		VM->IO_table->rear = (VM->IO_table->rear + 1) % MAXIOBUFFER;
		VM->IO_table->count_req++;
	pthread_mutex_unlock (&VM->IO_table_mutex);
}

void perform_IO_req (VirtualMachine** VMptr)
{
	VirtualMemory* VM = (*VMptr)->virtualMemory;
	Scheduler* s = (*VMptr)->scheduler;
	int opcode;
	int internal_id;
	int page_no, frame_no, swap_area;
	
	//TIME DELAY TO PERFORM THE IO
	usleep (2*STMT_EXEC_TIME);
	
	pthread_mutex_lock (&VM->IO_table_mutex);
		if (VM->IO_table->IO_req_table[VM->IO_table->front][1] == 1)
		{
			printf ("ALL IO REQUESTS HAS BEEN SERVICED.\n");
			pthread_mutex_unlock (&VM->IO_table_mutex);
			return;
		}
		opcode = VM->IO_table->IO_req_table[VM->IO_table->front][0];
		internal_id = VM->IO_table->IO_req_table[VM->IO_table->front][2];
		page_no = VM->IO_table->IO_req_table[VM->IO_table->front][3];
		frame_no = VM->IO_table->IO_req_table[VM->IO_table->front][4]; //Not applicable for page check in req
		switch (opcode)
		{
			case 1:
				//printf ("In Perform_IO() Page Check in req from Process:%d page:%d\n",internal_id,page_no);
				//Get the page from the swap space.
				pthread_mutex_lock (&VM->swap_page_map_mutex);
					swap_area = VM->swap_page_map [internal_id];
				pthread_mutex_unlock (&VM->swap_page_map_mutex);
				//Get a free frame to load the page
				frame_no = get_free_frame (&VM);
				//printf ("In Process:%d Page:%d is to be inserted in frame:%d from SWAP AREA:%d\n",internal_id,page_no,frame_no,swap_area);
				//Load the page from the swap to frame. update the page table entry.
				pthread_mutex_lock (&VM->global_page_table_mutex);
					VM->global_page_table[internal_id][page_no][0]=frame_no;
					VM->global_page_table[internal_id][page_no][1]=1; //Mark as valid
					VM->global_page_table[internal_id][page_no][2]=0; //Not Dirty
					//VM->global_page_table[internal_id][page_no][3]=1; //One reference to this page.
				pthread_mutex_unlock (&VM->global_page_table_mutex);
				//printf ("About to find the process from the process id:%d\n",internal_id);
				//Signal the process which has been waiting for this IO operation to complete.
					Process* p = find_process_in_PCB_list (s,internal_id);
				//printf ("Successfully served the request from Proc:%d\n",p->internal_id);
				io_end(p);
				pthread_mutex_lock (&p->IO_mutex);
					pthread_cond_signal (&p->IO_cond_var);
				pthread_mutex_unlock (&p->IO_mutex);
				break;
			case 2:
				printf ("Page Check out req\n");
				break;
			default:
				printf ("Unknown IO req opcode.\n");
		}
	VM->IO_table->count_req--;
	pthread_mutex_unlock (&VM->IO_table_mutex);
}
/*
	This thread responses to IO requests for both page check in and page check out.
*/
void* IO_manager (void* ptr)
{
	VirtualMachine* VMachine = (VirtualMachine*) ptr;
	VirtualMemory* VM = VMachine->virtualMemory;
	int count_req;
	while (1)
	{
		pthread_mutex_lock (&VM->IO_table_mutex);
			count_req = VM->IO_table->count_req;
		pthread_mutex_unlock (&VM->IO_table_mutex);
		if (count_req==0) //There is no request to serve. Or queue condition
		{
			//reset the pointers
			pthread_mutex_lock (&VM->IO_table_mutex);
				VM->IO_table->front = VM->IO_table->rear = 0;
			pthread_mutex_unlock (&VM->IO_table_mutex);
		}
		else
		{
			perform_IO_req (&VMachine);
		}
	}
}

/*
	Returns the least recently used frame number.
	The frame with minimum value of the time stamp in the page table is to be returned.
	Return anything found with time stamp value 0! It has not been used once.
*/
int LRU (VirtualMemory* VM)
{
	int frame_to_free;
	int earliest_timestamp=-1; //Invalid : -1
	int proc_id,i, len;
	pthread_mutex_lock (&VM->global_page_table_mutex);
		//This should be the number of active process. This is too much conservative!
		//printf ("VM->global_page_table: %x\n",VM->global_page_table[1][1][0]);
		for (proc_id=1;proc_id<MAXNUMPROCESS;proc_id++)
		{
		//	printf ("CHECKING PROCESS:%d\n",proc_id);
			if (VM->global_page_table[proc_id]==NULL)
				continue;
			for (i=1;VM->global_page_table[proc_id][i][0]!=-1;i++)
			{
			//	printf ("\tCHECK i:%d VM->global_page_table[proc_id][i]:%x VM->global_page_table[proc_id][i][0]:%d\n",i,VM->global_page_table[proc_id][i],VM->global_page_table[proc_id][i][0]);
				//printf ("|%d | %d |  %d  |  %d  |\n",VM->global_page_table[p->internal_id][i][0]
				if (VM->global_page_table[proc_id][i][1]==1 && earliest_timestamp > VM->global_page_table[proc_id][i][3])
				{
					earliest_timestamp = VM->global_page_table[proc_id][i][3];
					frame_to_free = VM->global_page_table[proc_id][i][0];
				}
			}
		}
	pthread_mutex_unlock (&VM->global_page_table_mutex);
	return frame_to_free;
}
/*
	Monitors the number of free frames and call LRU to free frame when n > a threshold
	If the page is dirty then there is an IO request is put for writing it back in the swap space.
*/
void* free_frame_manager (void* ptr)
{
	VirtualMemory* VM = (VirtualMemory*) ptr;
	int no_of_free_frames=0;
	int frame_to_free;
	while (1)
	{
		pthread_mutex_lock (&VM->free_frame_list_mutex);
			no_of_free_frames = VM->free_frame_list->free_frame_count;
		pthread_mutex_unlock (&VM->free_frame_list_mutex);
		if (no_of_free_frames < MINFREEFRAMEBOUND)
		{
			frame_to_free = LRU (VM);
			//TODO: Free the frame from the page table. Make the valid bit 0. increase the counter value.
		}
	}
}
