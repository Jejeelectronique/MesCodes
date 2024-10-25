#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float A , B , C , Delta, X;
float MaVarA, MaVarB, MaVarC;
void polynome2ndDeg();

//Delta = b² - 4ac
//Solutions si Delta > 0 ---> ( -b + Racine(Delta) ) / 2a  et   ( -b - Racine(Delta) ) / 2a 
//Solution si Delta == 0 --->  -b/2a
//Solution si Delta < 0 ----> Aucune solution dans les réelles



int main(void)
{

    polynome2ndDeg();
    return 0;
}



void polynome2ndDeg()
{  
    float A = 10;
    float B = 20;
    float C = 15;
    float Delta;

    printf("Saisir la valeur de A \n");
    scanf("%f", &A);

    printf("Saisir la valeur de B \n");
    scanf("%f", &B);

    printf("Saisir la valeur de C \n");
    scanf("%f", &C);



    printf("Valeur de A %c\n",A);
    printf("Valeur de A %d\n",A);



    Delta = ((B*B) - (4*(A*C)));

    if(Delta > 0)
        printf("Deux solutions : %.2f  et %.2f" , (((B * -1) + sqrt(Delta)) / 2*A) , (((B * -1) - sqrt(Delta)) / (2*A)));

    else if(!Delta)
        printf("Solution de l'équation : %.2f" , ((B * -1) / (2*A)));

    else
        printf("Aucune solution : %.2f");
}