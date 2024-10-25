#include "Queue.h"

int main (void)
{
	EnQueue(51);
	EnQueue(5);
	EnQueue(6);
	EnQueue(77);
	EnQueue(21);
	EnQueue(61);
	

	printf("Taille de la file : %d\n" , queue_length());
	print_queue();

	clearQueue();

	printf("Taille de la file : %d\n" , queue_length());
	print_queue();

	
	printf("Taille de la file : %d\n" , queue_length());
	print_queue();

return 0;
}