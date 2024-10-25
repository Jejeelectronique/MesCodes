#ifndef PILES_H
#define PILES_H
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum bool
{
	false,
	true
}bool;

typedef struct stackElement
{
	Player pp;
	struct stackElement *next;
}stackElement, *stack;


stack new_stack(void);
bool is_empty_stack(stack st);
stack push_stack(stack st, Player p);
stack clear_stack(stack st);
stack pop_stack(stack st);
Player top_stack(stack st);
int stack_lenght(stack st);

void print_stack(stack st);

#endif
