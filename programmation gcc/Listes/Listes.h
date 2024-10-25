#ifndef __LISTES__H__
#define __LISTES__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool
{
	false,
	true
}bool;

typedef struct ListeElement
{
	int value;
	struct ListeElement *next;
}ListeElement, *List;

List new_list();
bool is_empty_list(List li);
int list_length(List li);
void print_list(List li);
List push_back_list(List li, int x);
List push_front_list(List li, int x);
List pop_back_list(List li);
List pop_front_list(List li);
List clear_list(List li);

#endif