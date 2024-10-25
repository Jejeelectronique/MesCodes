#include <stdio.h>
#include <stdlib.h>

/*
sizeof(<Donnée>)  							: Renvoie la taille en octets des données
malloc(<TailleEnOctet>) 					: Alloue dynamiquement une zone mémoire

calloc(<Donnée>, <TailleEnOctet>) 			: Alloue et initialise tout à zero
realloc(<Donnée>, <NouvelleTailleOctet>) 	: Réalloue un espace mémoire
*/

int main(void)
{
	int nombresJoueurs = 0;
	int *ListeJoueurs = NULL;
	int *ListeJoueurs2 = NULL;
	int i;

	printf("Combien de joueurs ?");
	scanf("%d", &nombresJoueurs);
	
	ListeJoueurs = malloc(sizeof(int) * nombresJoueurs);	//malloc(<Taille en octet>)
	//ListeJoueurs = calloc(nombresJoueurs, sizeof(int));

	if(ListeJoueurs == NULL)	//Controle que l'allocation à bien fonctionnée
		exit(1);				//Si elle n'as pas fonctionnée alors on quitte le programme

	for(i=0; i < nombresJoueurs; i++)
	{
		printf("joueurs %d => Numero %d\n" , i + 1 , i * 3);
		ListeJoueurs[i] = i * 3;
	}

	for(i=0; i<nombresJoueurs;i++)
	{
		printf("[%d]\n" , ListeJoueurs[i]);
	}

	printf("Rentrer le nouveau nombres de joueurs \n");
	scanf("%d", &nombresJoueurs);
	 ListeJoueurs = realloc(ListeJoueurs, sizeof(int) * nombresJoueurs);

	if (ListeJoueurs == NULL)
		exit(1); 

	for(i=0; i < nombresJoueurs; i++)
	{
		printf("joueurs %d => Numero %d\n" , i + 1 , i * 3);
		ListeJoueurs[i] = i * 3;
	}

	free(ListeJoueurs);

	return 0;
}
