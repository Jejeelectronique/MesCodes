#include <stdio.h>

int val1 = 8;
int val2 = 4;

void invert(int *a, int *b);

int main(void)
{
	printf("Valeur de la variable 1 avant opération %d\n" , val1);
	printf("Valeur de la variable 2 avant opération %d\n" , val2);

	val1 ^= val2;
	val2 ^= val1;
	val1 ^= val2;

	printf("Valeur de la variable 1 après opération %d\n" , val1);
	printf("Valeur de la variable 2 après opération %d\n" , val2);

	invert(&val1 , &val2);

	printf("Valeur de la variable 1 apres appel de la foncton invert %d\n" , val1);
	printf("Valeur de la variable 2 apres appel de la foncton invert %d\n" , val2);

	invert(&val1 , &val2);

	printf("Valeur de la variable 1 apres appel de la foncton invert %d\n" , val1);
	printf("Valeur de la variable 2 apres appel de la foncton invert %d\n" , val2);
}

void invert(int *a, int *b)
{
	(*a) ^= (*b);
	(*b) ^= (*a);
	(*a) ^= (*b);
}