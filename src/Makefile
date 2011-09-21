all: outfile

outfile : OSCore.o VirtualMachine.o VirtualMemory.o Scheduler.o FileSystem.o queue.o data_structures.h includes.h logging.o
	gcc OSCore.o VirtualMachine.o VirtualMemory.o Scheduler.o FileSystem.o queue.o logging.o -o outfile -Wall -lrt -lpthread -g 

build_ar : OSCore.o VirtualMachine.o VirtualMemory.o Scheduler.o FileSystem.o queue.o data_structures.h includes.h logging.o
	ar cvq libworkbench.a OSCore.o VirtualMachine.o VirtualMemory.o Scheduler.o FileSystem.o queue.o logging.o

OScore.o : OSCore.c
	gcc -c OSCore.c

VirtualMachine.o : VirtualMachine.h VirtualMachine.c
	gcc -c VirtualMachine.c

VirtualMemory.o : VirtualMemory.c VirtualMemory.h
	gcc -c VirtualMemory.c

Schedueler.o : Scheduler.h Scheduler.c
	gcc -c Scheduler.c

FileSystem.o : FileSystem.h FileSystem.c
	gcc -c FileSystem.c

queue.o : queue.h queue.c
	gcc -c queue.c

logging.o : logging.c
	gcc -c logging.c

clean :
	rm -rf *o
