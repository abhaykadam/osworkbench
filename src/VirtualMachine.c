#include "includes.h"
#include "C_process.h"
#include "C_process_init.h"
#include "C_process_main.h"

/*
	This structure is solely for local use to this file to combine the parameters of excecute(..)
*/
struct _dummy_args
{
	VirtualMachine* VMachine;
	Process* p;
};
typedef struct _dummy_args dummy_args;


VirtualMachine* init_VirtualMachine(Scheduler* sched, VirtualMemory* Vmem, FileSystem* FS)
{
	char log_data[100];
	VirtualMachine* VMachine = (VirtualMachine*) malloc (sizeof (VirtualMachine));
	if (VMachine==NULL)
	{
		printf ("malloc failed.%d\n",strerror (errno));
	}
	VMachine->scheduler = sched; //Shallow copy
	VMachine->virtualMemory = Vmem;
	VMachine->fileSystem = FS;
	VMachine->cur_running_pid = 0; //No user process is running.
	sprintf (log_data,"VirtualMachine INIT.\n");
	logging (log_data);
	return VMachine;
}

void cc (Scheduler* s, unsigned internal_id)
{
	//Process state is shared with scheduling thread also. It is to be guarded by mutex
	pthread_mutex_lock (&mutex1);
	Process* proc = find_process_in_PCB_list(s,internal_id);
	if (proc==NULL)
	{
		printf ("Invalid process number. Internal error.\n");
		exit (EXIT_FAILURE);
	}
	if (proc->state != RUNNING) //NOT RUNNING STATE
	{	
			//printf ("cc waiting :%d\n",proc->internal_id);
			proc->waiting = 1;
			pthread_mutex_unlock(&mutex1);
			pthread_mutex_lock (&proc->mutex);
				pthread_cond_wait (& proc->cond,& proc->mutex);
			pthread_mutex_unlock (&proc->mutex);
	}
	else
	{
		pthread_mutex_unlock (&mutex1);
	}
}

void* execute (void* ptr)
{
	char log_data[MAXLEN];
	char source_line[MAXLEN];
	char command[10];
	int page_no, word_no;
	int ret_val;
	dummy_args* args = (dummy_args*) (ptr);
	VirtualMachine* VMachine = args->VMachine;
	Process* p = args->p;
	FILE* file_ptr = fopen (p->source_filename,"r");
	if (file_ptr==NULL) {printf ("PROCESS EXITING. FILE CAN NOT BE OPENED. %s",strerror(errno));return;}
	int counter=0;
	p->state = READY;
	printf ("PROGRAM STARTED: %d READING FROM FILENAME:%s\n",p->internal_id,p->source_filename);
	pthread_mutex_unlock (&mutex2);


	while (fgets(source_line,MAXLEN,file_ptr))
	{
		cc (VMachine->scheduler,p->internal_id);
		pthread_mutex_lock (&mutex1);
		if (virtual_memory_present==0)
		{
			printf ("id:%d src_line:%s",p->internal_id,source_line);
			fflush (stdout);
		}
		else if (virtual_memory_present==1)
		{
			sscanf (source_line,"%s %d %d\n",command,&page_no,&word_no);
			//printf ("source_line:%s COMMAND:%s page_no:%d word_no:%d\n",source_line, command,page_no,word_no);
			if (strcmp (command,"access")==0)
				ret_val = MMU (&VMachine->virtualMemory,p,page_no, word_no,1);
			else if (strcmp (command,"modify")==0)
				ret_val = MMU (&VMachine->virtualMemory,p,page_no, word_no,2);
			else if (strcmp (command,"end")==0)
			{
				printf ("PROCESS:%d is ending\n",p->internal_id);
				end_of_process (VMachine->scheduler,p->internal_id);
				pthread_mutex_unlock (&mutex1);
				break;
			}
			else
			{
				ret_val = 100; //Invalid ret_val. To have NOP printed and the loop goes on.
			}
			switch (ret_val)
			{
				case 1:
					printf ("OS TRAP. Illigal page access. Exiting process.\n");
					end_of_process (VMachine->scheduler,p->internal_id);
					return;
				case 2:
					//printf ("Successfully accessed from memory page:%d word:%d\n",page_no,word_no);
					break;
				case 3:
						//Page fault handled successfully. Now access the page newly brought in memory.
						pthread_mutex_unlock (&mutex1);
						cc (VMachine->scheduler,p->internal_id);
						pthread_mutex_lock (&mutex1);
						if (strcmp (command,"access")==0)
							ret_val = MMU (&VMachine->virtualMemory,p,page_no, word_no,1);
						else if (strcmp (command,"modify")==0)
							ret_val = MMU (&VMachine->virtualMemory,p,page_no, word_no,2);
					//printf ("Page fault handled for accessing/modifying page:%d word:%d\n",page_no,word_no);
					break;
				default:
					printf ("NOP\n");
					break;
			}
		}
		pthread_mutex_unlock (&mutex1);
		usleep (STMT_EXEC_TIME);
	}
}
void LoadVirtualMachine (VirtualMachine *VMachine, char *proc_filename, unsigned proc_no,unsigned process_size,unsigned page_frame_allocated)
{
	char log_data[1000];
	Process* p;
	pthread_t process_thread;
	
	sprintf (log_data,"PROGRAM LOADING:%s:%u:%u:%u:\n",proc_filename,proc_no,process_size, page_frame_allocated);
	logging (log_data);
	p = init_Process();
	p->pid = proc_no;
	p->source_filename = proc_filename;
	VMachine->internal_id_pid_map[p->internal_id] = p->pid;
	p->state = BLOCKED;
	p->process_size = process_size;
	p->page_frame_allocated = page_frame_allocated;
	
	if (VMachine->virtualMemory!=NULL)
	{
		//Assign process_size, page_fram_allocated to specific fields.
		init_VirtualMemory_process (&VMachine->virtualMemory, p, process_size, page_frame_allocated);
		display_page_table_for_process (VMachine->virtualMemory, p);
	}
	//Associate scheduler to this process
	init_Scheduler_process (VMachine->scheduler,p,proc_filename);
	dummy_args* d = (dummy_args*) malloc (sizeof (dummy_args));
	d->VMachine = VMachine;
	d->p = p;

	//printf ("Number of proc : %d\n",VMachine->scheduler->num_process_running);
	if (pthread_create(&process_thread,NULL,execute,d)!=0)
	{
		printf ("cannot create thread. %s\n",strerror(errno));
	}
}

void* execute_Instrumented (void* ptr)
{
	dummy_args* args = (dummy_args*) (ptr);
	VirtualMachine* VMachine = args->VMachine;
	Process* p = args->p;
	unsigned proc_id = p->internal_id;
	p->state = READY;
	
	printf ("START EXECUTING %d\n",proc_id);
	printf ("-------------------------------------------\n");
	MAIN_PROCESS_C
	
	pthread_mutex_lock (&mutex1);
	end_of_process (VMachine->scheduler,p->internal_id);
	pthread_mutex_unlock (&mutex1);
}

/*
	This function loads the relevant variables for running instrumented code
*/
void LoadVirtualMachine_Instrumented (VirtualMachine* VMachine,unsigned proc_id)
{
	char log_data[1000];
	Process* p;
	pthread_t process_thread;
	
	printf ("-------------------------------------------\n");
	sprintf (log_data,"INSTRUMENTED PROGRAM LOADING: PROC_ID:%u\n",proc_id);
	logging (log_data);
	p = init_Process();
	p->pid = proc_id;
	p->source_filename = "dummy";
	VMachine->internal_id_pid_map[p->internal_id] = p->pid;
	p->state = BLOCKED;
	p->process_size = 0; //Irrelevant
	p->page_frame_allocated = 0; //Irrelevant
	
	printf ("process id:%d address:%x\n",p->pid,p);
	
	
	INIT_PROCESS_C
	/*switch (proc_id){
		case 1:
		init_p1 (VMachine->scheduler,p,proc_id);
		printf ("INIT_P1 is called\n");
		break;
		case 2:
		init_p2 (VMachine->scheduler,p,proc_id);
		printf ("INIT_P2 is called\n");
		break;
	}*/
	
	//Associate scheduler to this process
	init_Scheduler_process (VMachine->scheduler,p,p->source_filename);
	dummy_args* d = (dummy_args*) malloc (sizeof (dummy_args));
	d->VMachine = VMachine;
	d->p = p;
	if (pthread_create(&process_thread,NULL,execute_Instrumented,(void*)(d))!=0)
	{
		printf ("cannot create thread. %s\n",strerror(errno));
	}
}
