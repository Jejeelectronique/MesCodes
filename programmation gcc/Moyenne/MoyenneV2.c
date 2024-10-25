#include <stdio.h>
#include <stdlib.h>
 
int NbrNote = 0; // itérateur
int Note = 0;
 
float Somme = 0;
 
int *Notes = NULL; 							// Tableau (pointeur) sans espace définie
 
 
int main(void)
{
	Notes = malloc((NbrNote + 1) * sizeof(int));				//Allocation dynamique de mémoire
	if (Notes == NULL)											//Controle du bon dérouler de l'allocation
		exit(1);


	while (1)
	{
		printf("Entrez la note n : %d\n", (NbrNote+1));
		scanf("%d", &Notes[NbrNote]);
 
		if(Notes[NbrNote] < 0)
		{
			for (int i = 0; i<NbrNote; i++)
			{
				Somme += Notes[i];
				printf("Valeur de la somme à l'iteration : %d\n", i);
			}
 
			Somme /= NbrNote;
			printf("La valeur de la moyenne est de : %.2f\n", (Somme));
 
			break;
		}
		NbrNote++;
		
		Notes = realloc(Notes, (NbrNote + 1) * sizeof(int));	//Réallocation de la mémoire
		if(Notes == NULL)
			exit(1);
	}
	free(Notes);												//Libération de la mémoire
}