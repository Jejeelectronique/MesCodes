#include <stdio.h>
#include <string.h>

int NbrNote = 0; // itérateur
int Note = 0;
float Somme = 0;
int Notes[]={0}; // Tableau [Nombres d'emplacement], (Valeurs des nombres du tableau)
char RecupNote[4]; 


int main(void)
{
	while (1)
	{
		printf("Entrez la note n : %d\n", (NbrNote+1));
		scanf("%d", &Notes[NbrNote]);
 
		if(Notes[NbrNote] < 0)
		{
			for (int i = 0; i<NbrNote; i++)
			{
				Somme += Notes[i];
			}
 
			Somme /= NbrNote;
 			printf("la moyenne est de  : %2.f\n", Somme);


 			printf("Voulez-vous recuperez une note : ?, 'yes/no'");
			scanf("%3s", RecupNote);
 
			if(strcmp(RecupNote, "yes")==0)
			{
				int choix;
 
				printf("Quelle note parmis les %d notes disponible, voulez vous affichez :\n", NbrNote);
				scanf("%d", &choix);
				printf("Voici la valeur de la note numero %d : %d", choix, Notes[(choix-1)]);
			}


			break;
		}
 	inverseur(varA , varB);

 	int inverseur (*Nba = &varA , *NbB = &varB)
 	{
 		NbA ^= NbB;
		NbB ^= NbA;
		NbA ^= NbB;

		return NbA;
 	}

		NbrNote++;
	}
}


void inverseur(int *NbA , int *NbB)
{
	*NbA ^= *NbB;
	*NbB ^= *NbA;
	*NbA ^= *NbB;
}


