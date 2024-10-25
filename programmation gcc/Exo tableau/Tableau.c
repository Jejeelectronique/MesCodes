#include <stdio.h>

#define TAILLE_TABLEAU 10
#define NOMBRE_DE_LIGNES 3
#define NOMBRE_DE_COLONNES 2

/*
	[Déclaration tableau]
		<Type> <Nom_tableau>[X]; //Déclare avec valeur aléatoires

	[Initialisation]
		tableau[5] = {valeur1, valeur2, valeur3, valeur4, valeur5};
		tableau[5] = {0}; //toutes les cases valent 0
		tableau[5] = {4}: //Première case à 4, LE RESTE A 0 !

		[Accès au tableau]
			tableau[X] : élément d'indice X (X+1ème élément du tableau)

		(NOTE)
		un tableau est un pointeur donc pas besoin de mettre de "&" quand on veut pointer sont adresse.
		Tableau[X]; identique que : *(Tableau + X);
		Tableau[5]; identique que : *(Tableau + 5);


*/

void afficher_tableau(int tab[],int taille);
void afficher_tab(int *tabF,int size);


/*------------------------------------------------------------------------------------------------------------------------------------------------*/


int main (void)
{

	int damier[NOMBRE_DE_LIGNES][NOMBRE_DE_COLONNES] = 
	{
		{1,2},
		{3,4},
		{5,6}
	};

	int tableau[TAILLE_TABLEAU] = {0};
	int i = 0;
	int tabFonction[TAILLE_TABLEAU];

/*------------------------------------------------------------------------------------------------------------------------------------------------*/

	printf("Affichage double tableau : \n");

	int l , c;

	for(l = 0; l < NOMBRE_DE_LIGNES; l++)
	{
		for(c = 0; c < NOMBRE_DE_COLONNES; c++){
			printf("Element d'indice [%d] [%d] = %d\n" , l , c , damier[l][c]);
		}
	}

	printf("\n \n \n \n");



	printf("Valeur de mon tableau classique : \n");

	for(i = 0; i < TAILLE_TABLEAU; i++)
	{
	printf("[%d]", tableau[i]);
	}

	printf("\n \n \n \n");


	printf("Valeur de mon tableau en pointeur : \n");

	i = 0;

		for(i = 0; i < TAILLE_TABLEAU; i++)
	{
		printf("[%d]", *(tableau + i)); // ceci est équivalent à tableau[i2]
	}


	afficher_tableau(tabFonction,10);
	afficher_tab(tabFonction,10);


	return 0;
}


/*
	[NOTE] : 

	un tableau étant un pointeur nous pouvons stocker les valeurs qu'ils acquierts dans les fonctions
	sans return.
*/

// 2 méthodes de fonction pour prendre en compte un tableau, le fonctionnement est identique


/*------------------------------------------------------------------------------------------------------------------------------------------------*/

void afficher_tableau(int tabFonction[],int taille) // un tableau etant un pointeur vers sa premier adresse
{													// nous pouvons le mettre juste entre crochet
	int a;

printf("\n");
printf("fonction tableau 1 \n");
	for (a = 0; a < TAILLE_TABLEAU; a++)
	{
		printf("[%d]" , tabFonction[a]);
	}
	printf("\n");
}


/*------------------------------------------------------------------------------------------------------------------------------------------------*/

void afficher_tab(int *tabF,int size)			//un tableau étant un pointeur nous pouvons le mettre sous cette forme
{
	int a;

printf("\n");
printf("fonction tableau 2 \n");
	for (a = 0; a < TAILLE_TABLEAU; a++)
	{
		printf("[%d]" , tabF[a]);
	}
	printf("\n");
}

/*------------------------------------------------------------------------------------------------------------------------------------------------*/


