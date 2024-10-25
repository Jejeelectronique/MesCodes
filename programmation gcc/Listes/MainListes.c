#include "Listes.h"
/*
new_list()
bool is_empty_list(List li)
list_length(List li)
print_list(List li)
push_back_list(List li, int x)
push_front_list(List li, int x)
pop_back_list(List li)
pop_front_list(List li)
*/

int main(void)
{
	List Maliste = new_list();
	print_list(Maliste);

	Maliste = push_back_list(Maliste,36);
	print_list(Maliste);

	Maliste = push_front_list(Maliste,87);
	Maliste = push_back_list(Maliste,-4);
	print_list(Maliste);
	printf("Nombre d'elements dans la liste : %d\n", list_length(Maliste));

	Maliste = clear_list(Maliste);
	print_list(Maliste);
	printf("Nombre d'elements dans la liste : %d\n", list_length(Maliste));

return 0;}