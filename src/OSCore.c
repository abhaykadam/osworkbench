/*
	This file starts the OS excecution. Creates virtual machine, virtual memmory, scheduler, file system
	It creates process and loads it to appropriate virtual machine.
*/

#include "includes.h"

void ParseOSSpec (char* filename, VirtualMachine** VMachine, VirtualMemory** VMem, Scheduler** sched, FileSystem** FS)
{
	int errsv;
	char line [MAXLEN];
	char component[25], flag[25];
	int VMem_config=0, FS_config=0;
	FILE* fp = fopen (filename,"r");
	if (fp==NULL)
	{
		errsv = errno;
		printf ("Cannot open file:%s. %s\n",filename, strerror (errsv));
		exit (EXIT_FAILURE);
	}
	while (fgets(line,MAXLEN,fp)!=NULL)
	{
		sscanf (line,"%s %s",component,flag);
		if (strcmp(component,"VirtualMemory")==0 && VMem_config==0)
		{
			VMem_config=1;//Receives the first config mentioned in the file.
			if (strcmp(flag,"full")==0)
			{
				virtual_memory_present = 1;
				*VMem = init_VirtualMemory();
			}
			else if (strcmp(flag,"omit")==0)
			{
				virtual_memory_present = 0;
				printf ("Virtual Memory is omitted.\n");
			}
			else
			{
				printf ("Unknown status name for this component. Please refer to the manual.\n");
				exit (EXIT_FAILURE);
			}
		}
		else if (strcmp(component,"FileSystem")==0 && FS_config==0)
		{
			FS_config=1; //Receives the first config mentioned in the file.
			if (strcmp(flag,"full")==0)
				*FS = init_FileSystem();
			else if (strcmp(flag,"omit")==0)
				printf ("FieSystem is omitted.\n");
			else
			{
				printf ("Unknown status name for this component. Please refer to the manual.\n");
				*FS = init_FileSystem();
			}
		}
		else
		{
			printf ("Unknown component. Please refer to the manual.\n");
			exit (EXIT_FAILURE);
		}
	}
	fclose (fp);
	//Mandatory to have to drive a system.
	*sched = init_Scheduler();
	*VMachine = init_VirtualMachine(*sched, *VMem, *FS);
}

char* instrument_program (char* filename)
{
	//TODO: Instrumentation to be done.
	return filename;
}

void ParseInit (char* filename, VirtualMachine* VMachine)
{
	int errsv;
	char line [MAXLEN];
	FILE* fp = fopen (filename,"r");
	char* proc_fileName = (char*) malloc (MAXLEN);
	char command [20];
	char* instrumented_file;
	unsigned process_no, process_size, page_frame_allocated;
	if (fp==NULL)
	{
		errsv = errno;
		printf ("Cannot open file:%s. %s\n",filename, strerror (errsv));
		exit (EXIT_FAILURE);
	}
	while (fgets(line,MAXLEN,fp)!=NULL)
	{
		pthread_mutex_lock (&mutex2);
		bzero (command,20);
		sscanf (line,"%s %s %u %u %u",command, proc_fileName, &process_no, &process_size, &page_frame_allocated);
		if (strcmp (command,"create")==0)
		{
			//instrumented_file = instrument_program (proc_fileName);
			LoadVirtualMachine (VMachine,proc_fileName,process_no,process_size, page_frame_allocated);
		}
		else
		{
			printf ("Unknown Command. Please follow the manual. command:%s\n",command);
		}
	}
	fclose(fp);
}

void signal_handler_assign ()
{
	signal (SIGINT, kill_handler);
  signal (SIGHUP, kill_handler);
  signal (SIGTERM, kill_handler);
}

void init_global_vars ()
{
	//Init the value of last_internal_id as 0;
	last_internal_id = 0;
	pthread_cond_init (&cond,NULL);
	pthread_mutex_init (&mutex1,NULL);
	pthread_mutex_init (&mutex2,NULL);
	pthread_mutex_init (&mutex3,NULL);
}

int main (int argc, char* argv[])
{
	VirtualMachine *VMachine;
	Scheduler *Sched;
	VirtualMemory *VMem;
	FileSystem *FS;
	pthread_t scheduler_thread, IO_thread, free_frame_manager_thread;
	int iret, time_interval;
	int i;
	FILE *dummy;
	assert (argc > 3 && "USAGE: <outfile> <OSConfig_File> <OS_Init_file> <Type of execution>");
	
	printf ("PROGRAM EXECUTION TYPE: %s\n",argv[3]);
	
	//Initialize global variables.
	init_global_vars ();	
	
	if ((dummy=fopen ("LOG.txt","w"))==NULL)
	{
		printf("Log file Can not be created/erased. %s\n",strerror(errno));
	}

	signal_handler_assign ();
	
	ParseOSSpec (argv[1],&VMachine, &VMem, &Sched, &FS);
	
	//Start Scheduler Thread
	if (pthread_create(&scheduler_thread, NULL, reschedule, (void*)Sched)!=0)
	{
		printf ("pthread_create error. %s\n",strerror (errno));
		exit (EXIT_FAILURE);
	}
	
	if (strcmp (argv[3],"demo")==0)
	{
		if (pthread_create (&IO_thread,NULL,IO_manager,(void*)VMachine)!=0)
		{
			printf ("IO thread can not be created.\n");
			exit (EXIT_FAILURE);
		}
	
		if (pthread_create (&free_frame_manager_thread,NULL,free_frame_manager,(void*)VMem)!=0)
		{
			printf ("free frame manager thread can not be created.\n");
			exit (EXIT_FAILURE);
		}
		ParseInit (argv[2],VMachine);
	
		pthread_join (free_frame_manager_thread,NULL);
		pthread_join (IO_thread,NULL);
	}
	else if (strcmp (argv[3],"instrument")==0)
	{
		printf ("OS LOADING THE INSTRUMENTED PROGRAMS\n");
		fflush (stdout);
		for (i=1;i<=atoi(argv[4]);i++)
		{
			pthread_mutex_lock (&mutex2);
			printf ("Process To start with pid:%d and call function main_p%d()\n",i,i);
			LoadVirtualMachine_Instrumented (VMachine,i);
		}
	}
	pthread_join (scheduler_thread,NULL);

	exit (EXIT_SUCCESS);
}
