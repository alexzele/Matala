#pragma once
#include <stdlib.h>

typedef int queue_type;

typedef struct queue_element
{
	queue_type data;
	struct queue_element *ptr_next;
}	queue_element;

typedef struct
{
	queue_element *front, *rear;
	int items_num;
}	queue;

void create_queue(queue *pq);

int enqueue(queue_type, queue *);

void dequeue(queue *, queue_type *);

int queue_front(queue *, queue_type *);

int queue_is_empty(queue *);

int queue_is_full(queue *);

int size_of_queue(queue *);
