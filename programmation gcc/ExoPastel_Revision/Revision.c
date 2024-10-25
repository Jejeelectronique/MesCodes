#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

    //La valeur de Mavariable : Mavariable
    //L'adresse de Mavariable : &Mavariable

    //La valeur du pointeur : *Monpointeur
    //L'adresse de la variable Pointer : Monpointeur
    //L'adresse du pointeur : &Monpointeur

int main(void)
{  
    int tailleTab;
    printf("Rentrer la taille du tableau a creer\n");
    scanf("%d", &tailleTab);

    char *tab;

    tab = malloc(sizeof(char) * tailleTab);
    
    for(int i = 0; i < tailleTab; i++)
    {
        tab[i] = i*2;
    }

    for(int i = 0; i < tailleTab; i++)
    {
        printf("Valeur du tableau dans l'index %d , : [%d]  \n" , (i + 1) , tab[i]);
    }

    free(tab);
    if(tab != NULL)
        {exit(EXIT_FAILURE); fprintf(stderr, "Erreur Liberation memoire");}
    return 0;
}

