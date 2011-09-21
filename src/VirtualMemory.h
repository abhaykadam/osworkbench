#ifndef _VIRTUALMEMORY_H
#define _VIRTUALMEMORY_H
#include "data_structures.h"

VirtualMemory* init_VirtualMemory ();
void init_VirtualMemory_process (VirtualMemory** VMem_ptr, Process* p, int process_size, int no_of_page_frame_allocated);
int get_free_frame (VirtualMemory** VMptr);
void display_page_table_for_process (VirtualMemory*VM, Process* p);
int MMU (VirtualMemory** VMptr,Process* p,int page_no,int word_no,int accessbit);
void insert_IO_req (VirtualMemory** VMptr, Process* p, int opcode, int page_no, int frame_no);

//IO thread to perform page and page out operation present in IO table.
void* IO_manager (void* ptr);

//Free frame manager checks the the number of free frame with a threshold.
void* free_frame_manager (void* ptr);
#endif
