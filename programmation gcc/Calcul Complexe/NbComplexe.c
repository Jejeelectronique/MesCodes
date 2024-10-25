#include <stdio.h>
#include <math.h>

#define RadSec (180 / 3.1415927)

//Calculer Le module (Partie réelle de l'impédance éxprimé en ohms) et le module (déphasage Courant/Tension) d'un nombres complexes algébriques (a + Jb)

float Re, Im;

float Module, Arg;

double ConvRadDeg = RadSec;

int main (void)
{
    printf("Rentrer la partie reelle du nombre complexe : \n");
    scanf("%f", &Re);

    printf("Rentrer la partie imaginaire du nombre complexe : \n");
    scanf("%f", &Im);

    Module = sqrt((pow(Re,2) + pow(Im,2)));
    printf("Module du nombre complexe : %2.f \n" , Module);

    Arg = atan2f(Im,Re);
    printf("Argument en Radiant du nombre complexe : %.2f\n" , Arg);

    ConvRadDeg *= Arg;
    printf("Argument en Degres du nombre complexe : %.2f\n" , ConvRadDeg);

    printf("Saisir une touche pour quitter");
    scanf("%d");

}