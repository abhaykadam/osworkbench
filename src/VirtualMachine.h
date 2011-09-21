#ifndef _VIRTUALMACHINE_H
#define _VIRTUALMACHINE_H
#include "data_structures.h"

VirtualMachine* init_VirtualMachine(Scheduler* sched, VirtualMemory* Vmem, FileSystem* FS);
//Loads the program in the Virtual machine.
void LoadVirtualMachine (VirtualMachine*,char*,unsigned,unsigned,unsigned);
void LoadVirtualMachine_Instrumented (VirtualMachine* virtualMachine,unsigned proc_id);

#endif
