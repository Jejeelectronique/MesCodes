#include <stdio.h>
#include <string.h>

/*
(*monPointeur).unChamp = X;
monPointeur->unChamp = X;
*/

union nomntr
{
	int entier;
	float decimal;  // permet d'allouer un type en focntion du besoin
}

typedef enum MarqueDeVoiture
{
	ferrari,  //0
	lamborghini,	//1
	pagani,
	agusta,
	fiat,
	maserati,
	bugatti
}Marque;

typedef struct utilisateur
{
	signed char prenom[256];
	signed char sexe[256];
	int age;
}utilisateur;



struct player
{
	signed char username[256];
	int hp;
	int mana;
};

typedef struct composant
{
	signed char name[256];
	signed char uniteMesure[256];
	int valeur;
}composant;

void create_compo(composant *p)
{
	strcpy((*p).name , "resistance");
	strcpy((*p).uniteMesure , "ohms");
	(*p).valeur = 250;
}

int main (void)
{

	struct player joueur1 = {"jerry",100,200};

	printf ("nom du joueur : %s\n" , joueur1.username);
	printf ("-----------------------------------------------------------\n");


	utilisateur numero1 = {"jerry" , "homme" , 28};

	printf ("nom du l'utilisateur : %s\n" , numero1.prenom);
	printf ("-----------------------------------------------------------\n");


	strcpy(numero1.prenom,"sylvain");
	printf ("nouveau nom du l'utilisateur : %s\n" , numero1.prenom);
	printf ("-----------------------------------------------------------\n");


	composant resistance ={"" , "" , };
	create_compo(&resistance);
	printf ("Type de composant : %s\n" , resistance.name);
	printf ("Valeur du composant : %d" , resistance.valeur);
	printf (" %s\n" , resistance.uniteMesure);


	Marque maVoiture = bugatti;
	printf (" %d\n" , maVoiture);

	union nombre nb1;
	nb1.entier = 3;
	nb1.decimal = 3.14;

	return 0;
}




