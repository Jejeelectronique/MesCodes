#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int chiffres(double a);

int main(void)
{
    double Nombres;
    printf("Saisisez un nombres\n");
    scanf("%lf", &Nombres);
    printf("nombres %lf\n" , Nombres);

    printf("nombres de decimal dans le nombres %d" , chiffres(Nombres));



    return 0;
}

int chiffres(double a)
{
    int i = 0;
    if(a < 0)
        a *= -1;
    while(a > 0)
    {
        a /= 10;
        i++;
    }
    return i;
}