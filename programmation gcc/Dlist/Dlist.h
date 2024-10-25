#ifndef __DLIST__H__
#define __DLIST__H__

#include <stdio.h>
#include <stdlib.h>


typedef enum bool{
	false,
	true
}bool;


typedef struct DlistNode
{
	int value;
	struct DlistNode *back;
	struct DlistNode *next;
}DlistNode;


typedef struct Dlist
{
	int length;
	struct DlistNode *begin;
	struct DlistNode *end;
}*Dlist;

Dlist new_dlist();
bool is_empty_dlist(Dlist li);
int dlist_length(Dlist li);
int dlist_first(Dlist li);
int dlist_end(Dlist li);
Dlist push_back_dlist(Dlist li, int x);
Dlist push_front_dlist(Dlist li, int x);
Dlist pop_back_dlist(Dlist li);
Dlist pop_front_dlist(Dlist li);
void print_Dlist(Dlist li);
void print_Dlist_Length(Dlist li);
Dlist clean_dlist(Dlist li);


#endif
