#include <stdio.h>
#include <stdlib.h>

#define Nb_types_billets 9



int SommeApayer;

void comptageBillets(int somme);

int main (void)
{
    printf("Rentrer la somme a payer\n");
    scanf("%d" , &SommeApayer);
    comptageBillets(SommeApayer);
    return 0;
}

void comptageBillets(int somme)
{
    int ValBillets[Nb_types_billets] = {500 , 200 , 100 , 50 , 20 , 10 , 5 , 2 , 1};
    int Nb_billets;

    for(int i = 0; i < Nb_types_billets; i++)
    {
        while(somme >= ValBillets[i])
        {
            somme -= ValBillets[i];
            Nb_billets++;
        }
    printf("Nombre de billets de %d, : %d\n", ValBillets[i], Nb_billets);
    Nb_billets = 0;
    }
}