#include "Dlist.h"


Dlist new_dlist()
{
	return NULL;
}


bool is_empty_dlist(Dlist li)
{
	if(li==NULL)
		return true;
	return false;
}

int dlist_length(Dlist li)
{
	if(is_empty_dlist(li))
		return 0;

	return li->length;
}

int dlist_first(Dlist li)
{
	if(is_empty_dlist(li))
		exit(1);
	return li->begin->value;
}


int dlist_end(Dlist li)
{
	if(is_empty_dlist(li))
		exit(1);
	return li->end->value;
}

Dlist push_back_dlist(Dlist li, int x)
{
	DlistNode *element;
	element = malloc(sizeof(*element));
	if(element == NULL)
	{
		fprintf(stderr, "Erreur d'allocation memeoire\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;
	element->back = NULL;



	if(is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));
		if(li == NULL)
		{
			fprintf(stderr, "Erreur d'allocation memeoire\n");
			exit(EXIT_FAILURE);
		}

		li->length = 0;
		li->begin = element;
		li->end = element;

	}
		else
		{
			li->end->next = element;
			element->back = li->end;
			li->end = element;
		}

		li->length++;

		return li;
	
}

Dlist push_front_dlist(Dlist li, int x)
{
	DlistNode *element;
	element = malloc(sizeof(*element));
	if(element == NULL)
	{
		fprintf(stderr, "Erreur d'allocation memeoire\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;
	element->back = NULL;



	if(is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));
		if(li == NULL)
		{
			fprintf(stderr, "Erreur d'allocation memeoire\n");
			exit(EXIT_FAILURE);
		}

		li->length = 0;
		li->begin = element;
		li->end = element;
	}

		else
		{
			li->begin->back = element;
			element->next = li->begin;
			li->begin = element;
		}

		li->length++;

		return li;
	
}



Dlist pop_back_dlist(Dlist li)
{
	if(is_empty_dlist(li))
		{
			printf("Liste vide\n");
			return new_dlist();
		}

	if(li->begin == li->end)
	{
		free(li);
		li = NULL;

		return new_dlist();
	}

	DlistNode *temp = li->end;

	li->end = li->end->back;
	li->end->next = NULL;
	temp->next = NULL;
	temp->back = NULL;

	free(temp);
	temp = NULL;

	li->length--;

	return li;
}




Dlist pop_front_dlist(Dlist li)
{
	if(is_empty_dlist(li))
		{
			printf("Liste vide\n");
			return new_dlist();
		}

	if(li->begin == li->end)
	{
		free(li);
		li = NULL;

		return new_dlist();
	}

	DlistNode *temp = li->begin;

	li->begin = li->begin->next;
	li->begin->back = NULL;
	temp->next = NULL;
	temp->back = NULL;

	free(temp);
	temp = NULL;

	li->length--;

	return li;
}

void print_Dlist(Dlist li)
{
	if(is_empty_dlist(li))
	{
		printf("Liste Vide\n");
		return;
	}

	DlistNode *temp = li->begin;

	while(temp != NULL)
	{
		printf("[%d]\n", temp->value);
		temp = temp->next;
	}
}

void print_Dlist_Length(Dlist li)
{
	printf("Taille de la Dlist : %d\n", dlist_length(li));
}


Dlist clean_dlist(Dlist li)
{
	while(!is_empty_dlist(li))
		li = pop_front_dlist(li);
	return li;
}