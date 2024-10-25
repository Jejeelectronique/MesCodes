#include "Piles.h"


stack new_stack(void)
{
	return NULL;
}

bool is_empty_stack(stack st)
{
	if(st == NULL)
		return true;
	return false;
}

stack push_stack(stack st, Player p)
{
	stackElement *element;
	element = malloc(sizeof(*element));
	if(element == NULL)
		{
			fprintf(stderr,"Erreur allocation dynamique\n");
			exit(EXIT_FAILURE);
		}
	strcpy(element->pp.name, p.name);
	element->pp.level = p.level;
	element->next = st;

	return element;
}

stack pop_stack(stack st)
{
	if(is_empty_stack(st))
		return new_stack();

	stackElement *element;
	element = st->next;
	free(st);

	return element;
}


stack clear_stack(stack st)
{
	while(!is_empty_stack(st))
		st = pop_stack(st);
	return new_stack();
}

Player top_stack(stack st)
{
	if(is_empty_stack(st))
	{
		printf("Aucun sommet, la pile est vide\n");
	}
	else
		return st->pp;
}

int stack_lenght(stack st)
{
	unsigned int lenght = 0;
	while(!is_empty_stack(st))
	{
		lenght++;
		st = st->next;
	}
	return lenght;
}

void print_stack(stack st)
{
	if(is_empty_stack(st))
	{
		printf("Rien a afficher\n");
		printf("-----------------------------------------------------------\n");
		return;
	}

	while(!is_empty_stack(st))
	{
		printf("[%s - niveau %d]\n", st->pp.name, st->pp.level);
		st = st->next;
	}
	printf("-----------------------------------------------------------\n");
}

	


