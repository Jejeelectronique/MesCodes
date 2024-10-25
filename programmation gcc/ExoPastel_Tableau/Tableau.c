#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void ValAbsolu_Et_Affichage(int *tab, unsigned int TailleTab);
void affichageTab(int *tab, unsigned int TailleTab);
void init_Tab(int *tab, unsigned int TailleTab);


int main(void)
{
    printf("Quelle taille voulez vous allouer a votre tableau \n");
    unsigned int Taille_Tab;
    scanf("%d" , &Taille_Tab);

    int *Tab = malloc(sizeof(int) * Taille_Tab);
    if(Tab == NULL){fprintf(stderr , "Erreur d'allocation memoire"); exit(EXIT_FAILURE);}

    init_Tab(Tab, Taille_Tab);
    affichageTab(Tab, Taille_Tab);
    ValAbsolu_Et_Affichage(Tab, Taille_Tab);
    affichageTab(Tab, Taille_Tab);
    


    free(Tab);
    Tab = NULL;
    if(Tab != NULL){fprintf(stderr, "Erreur lors de la liberation de la memoire"); exit(EXIT_FAILURE);}
    return 0;
}

void ValAbsolu_Et_Affichage(int *tab, unsigned int TailleTab)
{
    for (int i = 0; i < TailleTab; i++)
    {
        if(tab[i] < 0)
            tab[i] *= -1;
    }
}

void affichageTab(int *tab, unsigned int TailleTab)
{
    printf("\n");
    for (int i = 0; i < TailleTab; i++)
    {
       printf("[%d] = %d  " , (i + 1) , tab[i]);
    }
    printf("\n");
}

void init_Tab(int *tab, unsigned int TailleTab)
{
    for(int i = 0; i < TailleTab; i++)
    {
        printf("saisir la valeur contenu a l'index [%d] du tableau\n" , (i + 1));
        scanf("%d" , &tab[i]);
    }
}