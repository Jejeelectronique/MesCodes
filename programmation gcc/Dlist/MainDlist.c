#include "Dlist.h"

/*
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
*/

int main(void)
{
	printf("Creation d'une Dlist\n");
	Dlist Maliste = new_dlist();
	print_Dlist(Maliste);
	print_Dlist_Length(Maliste);
	printf("--------------------------------------------------------------\n");


	printf("ajouts elements par pushback\n");
	Maliste = push_back_dlist(Maliste,14);
	Maliste = push_back_dlist(Maliste,28);
	Maliste = push_back_dlist(Maliste,36);
	Maliste = push_back_dlist(Maliste,51);
	Maliste = push_back_dlist(Maliste,80);
	Maliste = push_back_dlist(Maliste,2);
	print_Dlist(Maliste);
	print_Dlist_Length(Maliste);
	printf("--------------------------------------------------------------\n");

	printf("ajouts elements par pushfront\n");
	Maliste = push_front_dlist(Maliste,6);
	Maliste = push_front_dlist(Maliste,22);
	Maliste = push_front_dlist(Maliste,15);
	Maliste = push_front_dlist(Maliste,30);
	Maliste = push_front_dlist(Maliste,44);
	Maliste = push_front_dlist(Maliste,4);
	print_Dlist(Maliste);
	print_Dlist_Length(Maliste);
	printf("--------------------------------------------------------------\n");

	printf("Test fonctions pop front\n");
	Maliste = pop_front_dlist(Maliste);
	print_Dlist(Maliste);
	print_Dlist_Length(Maliste);
	printf("--------------------------------------------------------------\n");

	printf("Test fonctions pop back\n");
	Maliste = pop_back_dlist(Maliste);
	print_Dlist(Maliste);
	print_Dlist_Length(Maliste);
	printf("--------------------------------------------------------------\n");

	printf("Test fonctions clean\n");
	Maliste = clean_dlist(Maliste);
	print_Dlist(Maliste);
	print_Dlist_Length(Maliste);
	printf("--------------------------------------------------------------\n");





return 0;}