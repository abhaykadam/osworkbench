#ifndef _SCHEDULER_H
#define _SCHEDULER_H
#include "data_structures.h"

Process* init_Process();
Scheduler* init_Scheduler();
void scheduling (Scheduler* ptr);
void init_Scheduler_process (Scheduler*,Process*,char*);

Process* find_process_in_PCB_list (Scheduler*,unsigned);

void io_start (Process*);
void io_end (Process*);
void* reschedule (void*);

void end_of_process (Scheduler*,unsigned);
#endif
