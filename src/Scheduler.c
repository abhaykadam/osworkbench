#include "includes.h"

Process* find_process_in_PCB_list (Scheduler* s,unsigned internal_id)
{
	node* p = s->PCB_list->front;
	while (p)
	{
		PCB* pcb = (PCB*) p->data;
		if (pcb==NULL)
			printf ("NULL PCB!\n");
		else
		{
			if (pcb->p->internal_id == internal_id)
				return pcb->p;
		}
		p = p->next;
	}
	printf ("NOT FOUND id:%d\n",internal_id);
	return NULL;
}
Process* init_Process()
{
	int errsv;
	Process* p = (Process*) malloc (sizeof (Process));
	if (p==NULL)
	{
		errsv = errno;
		printf ("malloc failed.%s",strerror (errsv));
	}
	p->pid = INVALID_PID;
	last_internal_id++;
	p->internal_id = last_internal_id;
	p->state = BLOCKED;
	p->source_filename = NULL;
	pthread_cond_init (&p->cond,NULL);
	pthread_mutex_init (&p->mutex,NULL);
	pthread_mutex_init (&p->state_mutex,NULL);
	pthread_mutex_init (&p->IO_mutex,NULL);
	pthread_cond_init (&p->IO_cond_var,NULL);
	p->waiting = 0;
	return p;
}
PCB* init_PCB()
{
	int errsv;
	PCB* pcb = (PCB*) malloc (sizeof (PCB));
	if (pcb==NULL)
	{
		errsv = errno;
		printf ("malloc failed.%s\n",strerror (errsv));
	}
	pcb->p = NULL;
	//pcb->cur_line = 1;//Execution has not been yet started.
	return pcb;
}
Scheduler* init_Scheduler()
{
	int errsv;
	char log_data [100];
	Scheduler* Sched = (Scheduler*) malloc (sizeof (Scheduler));
	if (Sched==NULL)
	{
		errsv = errno;
		printf ("malloc failed.");
		strerror (errsv);
	}
	Sched->PCB_list = init_queue();
	Sched->cur_PCB = init_PCB();
	sprintf (log_data,"Scheduler INIT.\n");
	logging (log_data);
	return Sched;
}

void init_Scheduler_process (Scheduler *Sched,Process *p, char* filename)
{
	char log_data[100];
	PCB* pcb = init_PCB();
	//Critical region
	pthread_mutex_lock(&mutex1);
	{
		pcb->p = p;
		pcb->p->source_filename = filename;
		push (&Sched->PCB_list,pcb);
		//printf ("PROCESS %d PUSHED IN PCB LIST\n",p->internal_id);
		if (Sched->PCB_list->size == 1) //This is the only user process in the system.
		{
			//Set it as the current process. And make the status as READY.
			Sched->cur_PCB = pick_front(Sched->PCB_list);
			//current_process_line_number = Sched->cur_PCB->cur_line;
			pthread_mutex_lock  (& Sched->cur_PCB->p->state_mutex);
				Sched->cur_PCB->p->state = RUNNING;
			pthread_mutex_unlock  (&Sched->cur_PCB->p->state_mutex);
		}
		sprintf (log_data,"Scheduler process INIT for:%d file:%s\n",pcb->p->internal_id, pcb->p->source_filename);
		logging (log_data);
	}
	pthread_mutex_unlock(&mutex1);
}

void* reschedule (void* ptr)
{
	struct timespec ts;
	Scheduler* sched = (Scheduler*) (ptr);
	while (1)
	{
		pthread_mutex_lock (&mutex3);
			scheduling (sched); //Calls the scheduling algorithm function at regular interval
			//usleep(SCHED_PERIOD*QUANTUM);
			if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
				printf("clock_gettime");
			ts.tv_sec+=2;
			pthread_cond_timedwait (&cond,&mutex3,&ts);
			//if (pthread_cond_timedwait (&cond,&mutex3,&ts) == 110)printf ("TIMEOUT SCHEDULER\n");
			//else printf ("\tIO CALL EXIT\n");
		pthread_mutex_unlock (&mutex3);
	}
}
/*
	Function implements scheduling algorithm.
	This can be overloaded.
*/
void scheduling (Scheduler* sched)
{
	char log_data[100];
	PCB *prev_PCB,*temp_PCB;
	unsigned old_id,new_id;
	int state;

	//printf ("Scheduling about to start. mutex1:%x\n",mutex1);
	pthread_mutex_lock(&mutex1);
		printf ("SCHEDULING ");
		//printf ("SCHEDULING PCB_list length:%d ",size(sched->PCB_list));
		//display_queue (sched->PCB_list);
		fflush (stdout);
		//This if is for experimental purposes
		if (sched->PCB_list->size <= 1) //There is only one process in the system.
		{
			printf ("Nothing to schedule as only one process in the system.\n");
			pthread_mutex_unlock(&mutex1);
			return;
		}
		else
		{
			old_id = sched->cur_PCB->p->internal_id;
			
			//Simple round robin policy.
			prev_PCB = front (&sched->PCB_list);
//			printf ("SCHEDULE OLD->mutex:%x\n",prev_PCB->p->mutex);
			pthread_mutex_lock (&prev_PCB->p->state_mutex);
				if ( prev_PCB->p->state == RUNNING )
					prev_PCB->p->state = READY;
			pthread_mutex_unlock (&prev_PCB->p->state_mutex);
			
			push (&sched->PCB_list,prev_PCB);
			//printf ("WELL OLD IS GONE!!!!\n");
			//FIND NEW Scheduled process
			unsigned counter=0, PCB_list_size = size(sched->PCB_list);
			while (1)
			{
				counter++;
				sched->cur_PCB = pick_front (sched->PCB_list);
				
				new_id = sched->cur_PCB->p->internal_id;
				pthread_mutex_lock (&sched->cur_PCB->p->state_mutex);
					state = sched->cur_PCB->p->state;
				pthread_mutex_unlock (&sched->cur_PCB->p->state_mutex);
//				printf (" next p:%d state %d ",sched->cur_PCB->p->internal_id,sched->cur_PCB->p->state);
				if ( state == READY) //FOUND THE NEXT READY PROCESS
					break;
				temp_PCB = front (&sched->PCB_list);
				push (&sched->PCB_list,temp_PCB);
				if (counter >= PCB_list_size)
				{
					printf ("No process is in READY state. Nothing to schedule.\n");
					pthread_mutex_unlock(&mutex1);
					return;
				}
//				printf ("Looking for the next READY process. counter:%d\n",counter);
			}
			printf ("OLD:%u NEW:%u\n",old_id,new_id);

			pthread_mutex_lock (&sched->cur_PCB->p->mutex);
			if (sched->cur_PCB->p->waiting == 1)
						pthread_cond_signal (& sched->cur_PCB->p->cond);
//				printf ("SIGNALED\n");
				pthread_mutex_lock (&sched->cur_PCB->p->state_mutex);
					sched->cur_PCB->p->state = RUNNING;
				pthread_mutex_unlock (&sched->cur_PCB->p->state_mutex);
			pthread_mutex_unlock (&sched->cur_PCB->p->mutex);
		}
	pthread_mutex_unlock(&mutex1);
}

/*
	Function is called when there is a io operation.
*/
void io_start (Process* p)
{
	//Make the process state blocked.
	pthread_mutex_lock (&p->state_mutex);
		p->state = BLOCKED;
	pthread_mutex_unlock (&p->state_mutex);
	//CAll the scheduler
	pthread_mutex_unlock (&mutex1);
	pthread_mutex_lock (&mutex3);
		//printf ("IO START by process:%u  %x\n",p->internal_id,p);
		pthread_cond_signal (&cond);
	pthread_mutex_unlock (&mutex3);
}

void io_start_instrumented (Scheduler* s, unsigned proc_id)
{
	pthread_mutex_lock (&mutex1);
		Process* p = find_process_in_PCB_list(s,proc_id);
	pthread_mutex_unlock (&mutex1);
	//Make the process state blocked.
	pthread_mutex_lock (&p->state_mutex);
		p->state = BLOCKED;
	pthread_mutex_unlock (&p->state_mutex);
	//CAll the scheduler
	pthread_mutex_unlock (&mutex1);
	pthread_mutex_lock (&mutex3);
		//printf ("IO START by process:%u  %x\n",p->internal_id,p);
		pthread_cond_signal (&cond);
	pthread_mutex_unlock (&mutex3);
}

/*
	Function called when io ends.
*/ 
void io_end (Process* p)
{
	//Make the waiting process state READY.
	pthread_mutex_lock (&p->state_mutex);
		//printf ("IO END by process:%u  %x\n",p->internal_id,p);
		p->state = READY;
	pthread_mutex_unlock (&p->state_mutex);
}

void io_end_instrumented (Scheduler* s, unsigned proc_id)
{
	pthread_mutex_lock (&mutex1);
		Process* p = find_process_in_PCB_list(s,proc_id);
	pthread_mutex_unlock (&mutex1);
	//Make the waiting process state READY.
	pthread_mutex_lock (&p->state_mutex);
		//printf ("IO END by process:%u  %x\n",p->internal_id,p);
		p->state = READY;
	pthread_mutex_unlock (&p->state_mutex);
}

void end_of_process (Scheduler* s,unsigned p_internal_id)
{
	Process* p = find_process_in_PCB_list (s,p_internal_id);
	pthread_mutex_lock (&p->state_mutex);
		p->state = TERMINATED;
	pthread_mutex_unlock (&p->state_mutex);
	printf ("PROCESS %d state changed to TERMINATED.\n",p->internal_id);
	//PROCESS is to be excluded from PCB_list of Scheduler.
}
