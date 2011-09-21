#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

node* init_node ()
{
	int errsv;
	node* n = (node*) malloc (sizeof (node));
	if (n==NULL)
	{
		errsv = errno;
		printf("malloc failed");
    puts(strerror(errsv));
	}
	n->data = NULL;
	n->next = NULL;
}
queue* init_queue ()
{
	int errsv;
	queue *q = (queue*) malloc (sizeof (struct _queue));
	if (q==NULL)
	{
		errsv = errno;
		puts("malloc failed");
    puts(strerror(errsv));
	}
	q->front = init_node();
	q->rear = init_node();
	q->size = 0;
	return q;
}
void push(queue** q, void* data)
{
	node* new_node = init_node();
	new_node->data = data; // Shallow copy.
	if ((*q)->rear != NULL) //This is NOT the first node.
	{
		(*q)->rear->next = new_node;		
	}
	(*q)->rear = new_node;
	if ((*q)->size == 0) //This is the first node
	{
		(*q)->front = (*q)->rear;
	}
	(*q)->size++;
	//printf ("Pushed. size:%d, front:%d, rear:%d\n",(*q)->size,*(int*)((*q)->front->data),*(int*)((*q)->rear->data));
}

void* front(queue** q)
{
	if (is_empty(*q))
	{
		printf ("QUEUE EMPTY\n");
		return NULL;
	}
	node* cur_front = (*q)->front;
	void* ret_data = cur_front->data; //Shallow copy.
	(*q)->front = (*q)->front->next;
	free (cur_front);
	(*q)->size--;
	return ret_data;
}

void* pick_front (queue *q)
{
	if (is_empty(q))
	{
		printf ("QUEUE EMPTY\n");
		return NULL;
	}
	node* cur_front = q->front;
	void* ret_data = cur_front->data; //Shallow copy.
	return ret_data;
}
int is_empty(queue *q)
{
	if (size(q)>0)
		return 0;
	return 1;
}
unsigned size(queue *q)
{
	return q->size;
}
void display_queue (queue *q)
{
	if (q==NULL)
	{
		printf ("Queue empty\n");
	}
	node* p = q->front;
	while (p)
	{
		printf ("%d, ",*((int*)p->data));
		p = p->next;
	}
}
