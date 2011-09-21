CC=gcc
CFLAGS=-c -Wall
LIBS=-lrt -lpthread


all: outfile

outfile : OSCore.o VirtualMachine.o VirtualMemory.o Scheduler.o FileSystem.o queue.o data_structures.h includes.h logging.o
	$(CC) OSCore.o VirtualMachine.o VirtualMemory.o Scheduler.o FileSystem.o queue.o logging.o -o outfile $(LIBS)

build_ar : OSCore.o VirtualMachine.o VirtualMemory.o Scheduler.o FileSystem.o queue.o data_structures.h includes.h logging.o
	ar cvq libworkbench.a OSCore.o VirtualMachine.o VirtualMemory.o Scheduler.o FileSystem.o queue.o logging.o

OScore.o : OSCore.c
	$(CC) $(CFLAGS) OSCore.c

VirtualMachine.o : VirtualMachine.h VirtualMachine.c
	$(CC) $(CFLAGS) VirtualMachine.c

VirtualMemory.o : VirtualMemory.h VirtualMemory.c
	$(CC) $(CFLAGS) VirtualMemory.c

Schedueler.o : Scheduler.h Scheduler.c
	$(CC) $(CFLAGS) Scheduler.c

FileSystem.o : FileSystem.h FileSystem.c
	$(CC) $(CFLAGS) FileSystem.c

queue.o : queue.h queue.c
	$(CC) $(CFLAGS) queue.c

logging.o : logging.c
	$(CC) $(CFLAGS) logging.c

clean :
	rm -rf *o
