#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum bool
{
	false,
	true
}bool;

typedef struct QueueElement
{
	int value;
	struct QueueElement *next;
}QueueElement, *Queue;

static QueueElement *first = NULL;
static QueueElement *last = NULL;
static int nb_elements = 0;

bool is_empty_queue();
int queue_length();
int queue_first();
int queue_last();
void print_queue();
void EnQueue(int x);
bool DeQueue();
void clearQueue();

#endif