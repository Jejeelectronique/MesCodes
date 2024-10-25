#include <stdio.h>
#include <stdlib.h>
/*
	fopen(<fichier>, <mode_ouverture>) : r (lecture seule, doit exister)
										 w (écriture seule)
										 a (ajout fin fichier)
										 r+ (lecture/écriture, doit exister)
										 w+ (lecture/écriture, fin de fichier)
										 a+ (ajout lecture/écriture, fin de fichier)

	fclose(<fichier>) : fermer un fichuer
	feof(<fichier>)   : tester la fin d'un fichier

	[LECTURE]
	fgetc(<fichier>) : Lire un caractere

	[ECRITURE]
*/

int main(void)
{
	FILE *fic = fopen("Sauvegarde.txt", "r");
	int lettre = 0;

	if(fic == NULL)
		exit(1);

	while(1)
	{
		lettre = fgetc(fic);
		if(feof(fic))
			break;
		printf("%c" , lettre);
	}
/*
	// 2éme méthode de lecture utilisant EOF pour la fin de fichier
	while((lettre = fgetc(fic)) != EOF)			//EOF (End Of Files) est la valeur retourner par fgetc en fin de fichier
	{
		printf("%c" , lettre);
	}
*/
	fclose(fic);

	return 0;
}