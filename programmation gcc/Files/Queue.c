#include "Queue.h"

bool is_empty_queue()
{
	if(first == NULL && last == NULL)
	{
		printf("la file est vide\n");
		return true;	
	}
	return false;
}


int queue_length()
{
	return nb_elements;
}

int queue_first()
{
	if(is_empty_queue())
		exit(1);
	return first->value;
}


int queue_last()
{
	if(is_empty_queue())
		exit(1);
	return last->value;
}

void print_queue()
{
	if(is_empty_queue())
	{
		return;
	}
	QueueElement *temp = first;

	while(temp != NULL)
	{
		printf("[%d]" , temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void EnQueue(int x)
{
	QueueElement *element;
	element = malloc(sizeof(*element));
	if(element == NULL)
	{
		fprintf(stderr, "Erreur allocation memoire");
		exit(EXIT_FAILURE);
	} 

	element->value = x;
	element->next = NULL;

	if(is_empty_queue())
	{
		first = element;
		last = element;
	}
	else 
	{
		last->next = element;
		last = element;
	}

	nb_elements++;
}

bool DeQueue()
{
	if(is_empty_queue())
	{
		first == NULL;
		last = NULL;
		return true;
	}
	QueueElement *temp = first;

	first = first->next;
	free(temp);
	nb_elements--;
	return false;
}

void clearQueue()
{
	while(nb_elements)
		{
			DeQueue();
		}
}

