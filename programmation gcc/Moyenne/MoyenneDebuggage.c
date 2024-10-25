#include <stdio.h>
#include <string.h>
 
//void debug ();
 
int NbrNote = 0; // itérateur
int Note = 0;
int i = 0;
int Notes[20]={0}; // Tableau [Nombres d'emplacement], (Valeurs des nombres du tableau) 
int cas = 0;
 
/*#define yes 1
#define no 0*/
 
float Somme = 0;
 
char RecupNote[4];
 
int main(void)
{
 
////////////////////////////////////////////////////////////////////////Itération/////////////////////////////////////////////////////////////////////////////////////
	/*while (1)
	{
		printf("Entrez la note n : %d\n", (NbrNote+1));
		scanf("%d", &Note);

 
		if (Note < 0)
		{
			Somme /= (NbrNote);
			printf("La valeur de la moyenne est de : %.2f\n", (Somme));
 
			break;
		}
 
		Somme += Note;
		NbrNote++;
	}*/
 
/*int NoteEnCour = 1;
 
	while (NoteEnCour)
	{
		if (Note == -1)
			NoteEnCour = 0;
 
	}*/
 
//////////////////////////////////////////////////////////////////////Tableau///////////////////////////////////////////////////////////////////////////////////////////
	while (1)
	{
		printf("Entrez la note n : %d\n", (NbrNote+1));
		scanf("%d", &Notes[NbrNote]);
 
		if(Notes[NbrNote] < 0)
 
		{
			Notes[NbrNote] = 0;
			// Calcul des notes
			for (int a = 0; a<NbrNote; a++)
 
			{
 				printf("la valeur de la somme est de  %2.f\n", Somme);
				Somme += Notes[a];

			}
 
			// Calcul de la moyenne
			Somme /= NbrNote;
 
			// Affichage de la moyenne
			printf("la moyenne est de  : %2.f\n", Somme);
			// Récuperation d'une note
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
 
		NbrNote++;
 
	}
 
}
 
 
////////////////////////////////////////////////////////////////////////Débugage////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
void debug ()
{
	printf("Valeur de la somme à l'iteration : %d\n", i); // Affichage valeur de la somme dans l'itération
	printf("Valeur stockée dans l'emplacement %d du tableau: %d\n", NbrNote, Notes[NbrNote]); // Valeur stockée dans l'emplacement du tableau
}
