#include "Listes.h"



List new_list()
{
	return NULL;
}

bool is_empty_list(List li)
{
	if(li == NULL)
		return true;
	return false;
}

int list_length(List li)
{
	int size = 0;

	if(!is_empty_list(li))
		while(li != NULL)
		{
			++size;
			li = li->next;
		}

	return size;
}


void print_list(List li)
{
	if(is_empty_list(li))
	{
		printf("liste vide, rien a afficher \n\n");
		return;
	}

	while(!is_empty_list(li))
	{
		printf("[%d]", li->value);
		li = li->next;
	}
	printf("\n");
}



List push_back_list(List li, int x)
{
	ListeElement *element;

	element = malloc(sizeof(*element));
	if(element == NULL)	{fprintf(stderr, "Erreur probleme d'allocation memeoire \n"); exit(EXIT_FAILURE);}

	element->value = x;
	element->next = NULL;

	if(is_empty_list(li))
		return element;

	ListeElement *temp;
	temp = li;

	while(temp->next != NULL)
		temp = temp->next;
	temp->next = element;

	return li;
}


List push_front_list(List li, int x)
{
	ListeElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
		{
			fprintf(stderr, "Erreur probleme d'allocation memeoire \n");
			exit(EXIT_FAILURE);
		}

	element->value = x;

	if(is_empty_list(li))
		element->next = NULL;
	else
		element->next = li;

	return element;
}



List pop_back_list(List li)
{
	if(is_empty_list(li))
		return new_list();
	if(li->next == NULL)
	{
		free(li);
		li = NULL;

		return new_list();
	}

	ListeElement *temp = li;
	ListeElement *before = li;

	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}

	before->next = NULL;
	free(temp);
	temp = NULL;

	return li;
}



List pop_front_list(List li)
{
	if(is_empty_list(li))
		return new_list();

	ListeElement *element;

	element = malloc(sizeof(*element));
	if(element == NULL)	{fprintf(stderr, "Erreur probleme d'allocation memeoire \n"); exit(EXIT_FAILURE);}
	element = li->next;

	free(li);
	li = NULL;

	return element;
}



List clear_list(List li)
{
	if(is_empty_list(li))
	return new_list();

	ListeElement *element;

	element = malloc(sizeof(*element));
	if(element == NULL)
		{
			fprintf(stderr, "Erreur probleme d'allocation memeoire \n");
			exit(EXIT_FAILURE);
		}
		while(li != NULL)
		{
			li = pop_front_list(li);
		}

}