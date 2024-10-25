#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void SwitchCarac(unsigned char *Caractere_Param_Fonction);

int main(void)
{
    unsigned char MonCarac = 0;
    unsigned char MonNouveauCarac = 0; 

    printf("Saisir un caractere \n");

    MonCarac = getche();

    SwitchCarac(&MonCarac);

    printf("\nValeur de ma variable dans mon programme [%c]\n" , MonCarac);


    return 0;
}

void SwitchCarac(unsigned char *Caractere_Param_Fonction)
{
    printf("\nMon caractere avant la fonction [%c] \n" , *Caractere_Param_Fonction);
    printf("Valeur ASCII du caractere avant la fonction : %d\n" , *Caractere_Param_Fonction);

    if(*Caractere_Param_Fonction >= 97)
        *Caractere_Param_Fonction -= 32;

    else 
        *Caractere_Param_Fonction += 32;

    
    printf("Mon caractere inverser [%c]\n" , *Caractere_Param_Fonction);
    printf("Valeur ASCII du caractere apres la fonction : %d\n" , *Caractere_Param_Fonction);
}