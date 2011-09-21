/*
	This file contains the necessary data structures.
*/
#ifndef _DATA_STRUCTURES_H
#define _DATA_STRUCTURES_H

#include "queue.h"
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

typedef struct
{
	int* free_frame_nos;
	int free_frame_count;
}free_frame_list_t;

typedef struct
{
	int** IO_req_table;
	int front,rear;
	int count_req;
}IO_table_t;

struct _VirtualMemory
{
	int*** global_page_table;
	int page_ref_time_stamp;
	pthread_mutex_t global_page_table_mutex;

	free_frame_list_t* free_frame_list;
	pthread_mutex_t free_frame_list_mutex;

	int* swap_page_map;
	pthread_mutex_t swap_page_map_mutex;

	IO_table_t* IO_table;
	pthread_mutex_t IO_table_mutex;
};
typedef struct _VirtualMemory VirtualMemory;

struct _FileSystem
{
	unsigned dummy;
	// Page table, free frame table
};
typedef struct _FileSystem FileSystem;

struct _VirtualMachine
{
	int internal_id_pid_map[MAXNUMPROCESS];
	
	VirtualMemory* virtualMemory;
	Scheduler* scheduler;
	FileSystem* fileSystem;
	unsigned cur_running_pid;
};
typedef struct _VirtualMachine VirtualMachine;

#endif
