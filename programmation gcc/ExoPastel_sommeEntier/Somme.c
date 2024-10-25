#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


int main (void)
{
    fpos_t *pos;
	FILE *fic = fopen("ElementTab.txt","r");
    if(!fic){printf("Erreur ouverture du fichier\n"); exit(EXIT_FAILURE);}
    int ligne = 1;

  	do
	{
        if(fgetc(fic) == '\n')
		    ligne++;
	}while(!feof(fic));

    *pos = 0;
    fsetpos(fic,pos);
    printf("Nombre de lignes du fichier %d\n" , ligne);


    int *tab = malloc(sizeof(int) * ligne);
    if(!tab){printf("Erreur d'allocation memoire \n"); exit(EXIT_FAILURE);}

    
    int i = 1;
    int Total = 0;
    int NbElements = ligne;
    char *tabc;

    do
    {
        fgets(tabc,2,fic);
        tab[i] = *tabc;
        // *tabc = 0;
        printf("Valeur du buffer %c\n" , *tabc);
        i++;
        NbElements--;
        // Total += tab[i];

    } while(NbElements);
    

    printf("Somme des elements du tableau : %d\n" , Total);


    free(tab);if(!tab){printf("Liberation memoire du tableau reussi\n");}
    fclose(fic);if(!fic){printf("Liberation memoire du flux fichier reussi\n");}
    return 0;
}