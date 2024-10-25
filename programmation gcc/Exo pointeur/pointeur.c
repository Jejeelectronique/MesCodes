#include <stdio.h>

/*

& = adresse
* = pointeur

%p permet d'afficher une adresse


[VARIABLES]
maVariable : Renvoie la valeur de la variable
&maVariable : Renvoie l'adresse de la variable

[POINTEURS]
*monPointeur = NULL ou *monPointeur = &maVariable
(déclaration et initialisation d'un pointeur)

monPointeur : renvoie l'addresse de la variable pointée
*monPointeur : renvoie la valeur de la variable pointé
&monPointeur : renvoie l'addresse du pointeur 

(NOTE)
un tableau est un pointeur qui pointe vers son premier élément

*/

//int monTab[] = {0,4,85,4,3};

void inverser_nombreP(int *nbA, int *nbB);
void inverser_nombre(int nb1, int nb2);

int Calc(int a, int b , int (*pf)(int,int));

int multiplication (int a, int b);
int division (int a, int b);

int main (void)
{


Calc(5,4,&multiplication);

int nombreA = 15;
int nombreB = 30;

int nbA = 10;
int nbB = 20;

int *Psur_nb_A = &nbA; 
int *Psur_nb_B = &nbB;

int tab[2] = {nbA ,nbB};

printf("Adresse de nombreA: %p\n" , &nombreA);

printf("ma fonction avec pointeur avant appelle: nombreA = %d et nombreB = %d\n" , nombreA , nombreB);
printf("ma fonction sans pointeur avant appelle : nbA = %d et nbB = %d\n" , nbA , nbB);

inverser_nombreP(&nombreA, &nombreB);
inverser_nombre(nbA, nbB);

printf("ma fonction avec pointeur apres appelle: nombreA = %d et nombreB = %d\n" , nombreA , nombreB);
printf("ma fonction sans pointeur apres appelle : nbA = %d et nbB = %d\n" , nbA , nbB);

inverser_nombreP(Psur_nb_A,Psur_nb_B); //l'adresse de la variable pointer est contenue dans
										// la variable du pointeur.

printf("fonction avec pointeur et tableau avant appelle : tab[0] = %d et tab[1] = %d\n" , tab[0] , tab[1]);						
inverser_nombreP(&tab[0] , &tab[1]);		

printf("fonction avec pointeur et tableau apres appelle : tab[0] = %d et tab[1] = %d\n" , tab[0] , tab[1]);

printf("création manuelle d'un pointeur pour nbA et nbB ,\n Valeur de nbA : %d et Valeur de nbB : %d\n " , nbA , nbB);

	return 0;
}


void inverser_nombreP(int *nbA, int *nbB)
{
int tempo = 0;

tempo = *nbA;
*nbA = *nbB;
*nbB = tempo;


}

void inverser_nombre(int nb1, int nb2)
{
int tempo = 0;

tempo = nb1;
nb1 = nb2;
nb2 = tempo;

}

int Calc(int a, int b , int (*pf)(int,int))
{
	printf("Resultat de l'opération : %d\n" , (*pf)(a,b));
	return (*pf)(a,b);
}

int multiplication (int a, int b)
{
	return (a * b);
}
int division (int a, int b)
{
	return (a / b);
}