#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define MasSizeInt 32760

typedef enum Jours
{
    lundi,
    mardi,
    mercredi,
    jeudi,
    vendredi
}Jours;


typedef enum Mois
{
    Janvier,
    Février,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Aout,
    Septembre,
    Octrobre,
    Novembre,
    Decembre
}Mois;


typedef struct budget{
    Mois mois;
    Jours jours;
    int Moyenne_Glissante;
    int Moyenne_Mobile;
    int Trimestre;
    int Somme_Mois[12];
}budget;

unsigned char StringAffichage[12][9] = {{"janvier"},{"fevrier"},{"mars"},{"avril"},{"mai"},{"juin"},{"juillet"},{"aout"},{"septembre"},{"octobre"},{"novembre"},{"decembre"}};

void Moyenne_Glissante(budget *Budget, Mois MoisRef);
void InitStruct(budget *Budget);

int main(void)
{
    srand((time( NULL )));
    budget Budget;
    InitStruct(&Budget);
    Moyenne_Glissante(&Budget, Mai);


    return 0;
}

void Moyenne_Glissante(budget *Budget, Mois MoisRef)
{
    Budget->Moyenne_Glissante = 0;
    for(int i = 0; i < 3; i++)
    {
        int a = i;
        if(a < 0)
            a == 12;
        else if(a > 12)
            a == 0;

        Budget->Moyenne_Glissante += Budget->Somme_Mois[MoisRef - i];
    }
    Budget->Trimestre = (Budget->Moyenne_Glissante / 3);
    printf("Moyenne glissante du trimestre de %s : %d\n" , StringAffichage[MoisRef] , Budget->Trimestre);
}

void InitStruct(budget *Budget)
{
    for(int i = 0; i < 12; i++)
    {
        Budget->Somme_Mois[i] = ((47 * rand()) % 5000);
        printf("Somme du mois de %s : [%d] \n" , StringAffichage[i] , Budget->Somme_Mois[i]);
    }
}

// void Moyenne_Mobile(budget *Budget, Mois MoisDebut, Mois MoisFin)
// {
//     Budget->Moyenne_Glissante = 0;
//     for(int i = 0; i < (MoisFin - MoisDebut); i++)
//     {
//         int a = i;
//         if(a < 0)
//             a == 12;
//         else if(a > 12)
//             a == 0;

//         Budget->Moyenne_Glissante += Budget->Somme_Mois[MoisRef - i];
//     }
//     Budget->Trimestre = (Budget->Moyenne_Glissante / 3);
//     printf("Moyenne glissante du trimestre de %s : %d\n" , StringAffichage[MoisRef] , Budget->Trimestre);
// }