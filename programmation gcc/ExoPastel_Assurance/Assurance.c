#include <stdio.h>
#include <stdint.h>

typedef enum Boolean{
    false,
    true
}Boolean;

typedef enum Tarifs{
    Tarif_Vert,
    Tarif_Orange,
    Tarif_Rouge,
    Refuse
}Tarifs;

typedef struct client{
    char nom[25];
    int age;
    int AnneePermis;
    int Sinistre;
    Tarifs Tarif;
    Boolean Age_Sup_25;
    Boolean Permis_Sup_2;
}client;

void GestionTarif(client *Monclient);

int main (void)
{
    client Monclient;
    client Num2;

    GestionTarif(&Monclient);
    GestionTarif(&Num2);

/* --------------------Cas inférieur à 25 ans -------------------------------------------------*/

    return 0;
}






void GestionTarif(client *Monclient)
{
    char TarifsString[4][15] = {
        {"Tarif Vert"},
        {"Tarif Orange"},
        {"Tarif Rouge"},
        {"Refuse"}
    };
    printf("Rentrer le nom du client \n");
    scanf("%s", Monclient->nom);

    printf("rentrer l'age du client \n");
    scanf("%d", &Monclient->age);

    printf("rentrer l'age de permis du client \n");
    scanf("%d" , &Monclient->AnneePermis);

    printf("rentrer le nombres d'accident du client \n");
    scanf("%d" , &Monclient->Sinistre);  


    if(Monclient->age >= 25)
        Monclient->Age_Sup_25 = true;
    else 
        Monclient->Age_Sup_25 = false;

    if(Monclient->AnneePermis >= 2)
        Monclient->Permis_Sup_2 = true;
    else
        Monclient->Permis_Sup_2 = false;





/* --------------------Cas Supérieur à 25 ans -------------------------------------------------*/
    switch (Monclient->Age_Sup_25)
    {
    case true :

        switch (Monclient->Permis_Sup_2)
        {
        case true:
            switch (Monclient->Sinistre)
            {
            case 0 :
                Monclient->Tarif = Tarif_Vert;
                break;

            case 1 :
                Monclient->Tarif = Tarif_Orange;
                break;
            
            case 2 :
                Monclient->Tarif = Tarif_Rouge;
                break;
            
            default:
                Monclient->Tarif = Refuse;
                break;
            }
        break;


        
        case false :

            switch (Monclient->Sinistre)
            {
            case 0 :
                Monclient->Tarif = Tarif_Orange;
                break;

            case 1 :
                Monclient->Tarif = Tarif_Rouge;
                break;
            
            default:
                Monclient->Tarif = Refuse;
                break;
            }
        break;
        }
        
    
/* --------------------Cas Supérieur à 25 ans -------------------------------------------------*/









    case false :
    /* --------------------Cas inférieur à 25 ans -------------------------------------------------*/

        switch (Monclient->Permis_Sup_2)
        {
        case true:
            switch (Monclient->Sinistre)
            {
            case 0 :
                Monclient->Tarif = Tarif_Orange;
                break;

            case 1 :
                Monclient->Tarif = Tarif_Rouge;
                break;
            
            default:
                Monclient->Tarif = Refuse;
                break;
            }  
        break;


        
        case false :

            switch (Monclient->Sinistre)
            {
            case 0 :
                Monclient->Tarif = Tarif_Rouge;
                break;

            default:
                Monclient->Tarif = Refuse;
                break;
            }
        break;

        }
        
    break;
    }

    printf("Le client %s, age de %d ans et titulaire du permis de conduire depuis %d ans, avec %d sinistre, est assigne au %s \n",
    Monclient->nom,
    Monclient->age,
    Monclient->AnneePermis,
    Monclient->Sinistre,
    TarifsString[Monclient->Tarif]
    );
}