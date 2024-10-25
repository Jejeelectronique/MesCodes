#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void affichageTab(int *tab, unsigned int TailleTab);
void init_Tab(int *tab, unsigned int TailleTab);
void Somme_Tab(int *SmTab, int *tab, unsigned int TailleTab);


int main(void)
{
    printf("Quelle taille voulez vous allouer a votre tableau \n");
    unsigned int Taille_Tab;
    scanf("%d" , &Taille_Tab);

    int *Tab = malloc(sizeof(int) * Taille_Tab);    if(!Tab){fprintf(stderr , "Erreur d'allocation memoire"); exit(EXIT_FAILURE);}
    int *Tab_Somme = malloc(sizeof(int) * Taille_Tab);    if(!Tab_Somme){fprintf(stderr , "Erreur d'allocation memoire"); exit(EXIT_FAILURE);}

    init_Tab(Tab, Taille_Tab);
    printf("affichage du tableau :           ");
    affichageTab(Tab, Taille_Tab);

    Somme_Tab(Tab_Somme, Tab, Taille_Tab);
    printf("affichage du tableau de somme :  ");
    affichageTab(Tab_Somme, Taille_Tab);
    
    free(Tab);  
    free(Tab_Somme); 
    
    Tab = NULL;
    Tab_Somme = NULL;
    
    if(Tab != NULL){fprintf(stderr, "Erreur lors de la liberation de la memoire"); exit(EXIT_FAILURE);}   
    if(Tab != NULL){fprintf(stderr, "Erreur lors de la liberation de la memoire"); exit(EXIT_FAILURE);}
    return 0;
}



void affichageTab(int *tab, unsigned int TailleTab)
{
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


void Somme_Tab(int *SmTab, int *tab, unsigned int TailleTab)
{
    int var = 0;
    for(int i = 0; i < TailleTab; i++)
    {
        for(int a = 0; a < (i + 1); a++)
            var += tab[a];
        SmTab[i] = var;
        var = 0;
    }
}