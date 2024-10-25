#include "Piles.h"


int main(void)
{
	Player p1 = {"jerome",15};
	printf("%s [%d] vient de rejoindre la partie\n\n", p1.name, p1.level);

	Player p2 = {"mickeal",2};
	printf("%s [%d] vient de rejoindre la partie\n\n", p2.name, p2.level);

	Player p3 = {"lucien",46};
	printf("%s [%d] vient de rejoindre la partie\n\n", p3.name, p3.level);

	Player p4 = {"mike",70};
	printf("%s [%d] vient de rejoindre la partie\n\n", p4.name, p4.level);

	stack sta = new_stack();

	sta = push_stack(sta,p1);
	sta = push_stack(sta,p2);
	sta = push_stack(sta,p3);
	sta = push_stack(sta,p4);
	
	Player last = top_stack(sta);

	printf("Dernier joueurs a avoir rejoint la partie toujours connecter :  %s [%d]  \n\n", last.name, last.level);
	printf("Nombres de joueurs :  %d\n\n", stack_lenght(sta));

	print_stack(sta);

	sta = pop_stack(sta);
	print_stack(sta);

	printf("Nombres de joueurs :  %d\n", stack_lenght(sta));

	sta = clear_stack(sta);
	print_stack(sta);

	return 0;}
