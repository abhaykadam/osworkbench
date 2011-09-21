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
