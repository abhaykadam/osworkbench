#ifndef _QUEUE_H
#define _QUEUE_H

struct _node
{
	void* data;
	struct _node* next;
};
typedef struct _node node;
struct _queue
{
	node *front, *rear;
	unsigned size;
};
typedef struct _queue queue;

queue* init_queue ();
void push(queue**, void*);
void* pick_front (queue*); //Returns the front element;
void* front(queue**); //returns the front element and deletes the front element.
int is_empty(queue*); //returns 1 for an empty queue otherwise returns 0.
unsigned size(queue*); //returns the number of elements in the queue.

void display_queue (queue*);
#endif
/*
	This file contains the necessary data structures.
*/
#ifndef _DATA_STRUCTURES_H
#define _DATA_STRUCTURES_H

#include <stdio.h>
#include <pthread.h>

#define MAXNUMPROCESS 100

#define INVALID_PID -1
#define STMT_EXEC_TIME 1000000
#define MAXLEN 500

#define MAXFRAMENO 1000
#define MAXIOBUFFER (MAXNUMPROCESS+10)

#define MINFREEFRAMEBOUND 10


char log_buffer [10000];
void logging (char*);
void kill_handler (int);
unsigned last_internal_id;

//Global Mutexes and Condition Variables
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex3;
pthread_cond_t cond;

//this variable is 0 if virtual memory is not present
// is 1 if virtual memory is not present.
int virtual_memory_present;

//unsigned current_process_line_number;
enum BOOLEAN {FALSE,TRUE};

enum STATE 
{
	BLOCKED,
	READY,
	RUNNING,
	TERMINATED
};
	
struct _process
{
	unsigned pid;
	unsigned internal_id;
	enum STATE state;
	char* source_filename;
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	pthread_mutex_t state_mutex;
	int waiting;
	int process_size;
	int page_frame_allocated;
	
	pthread_mutex_t IO_mutex;
	pthread_cond_t IO_cond_var;
};
typedef struct _process Process;

struct _PCB
{
	Process* p;
	int priority;
	//unsigned cur_line;
//	FILE* file_ptr;
};
typedef struct _PCB PCB;

struct _Scheduler
{
	queue* PCB_list; //list of the PCBs in the system running.
	PCB* cur_PCB;
};
typedef struct _Scheduler Scheduler;

#endif
Scheduler* sched; unsigned pid; Process* p;
#include <stdio.h>

int main ()
{
	//while (1)
	{
		printf ("test2\n");
	}
	return 0;
}
