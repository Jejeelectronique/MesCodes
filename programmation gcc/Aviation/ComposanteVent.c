#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define ConvRadDeg (PI/180)
#define ConvDegRad (180/PI)

int main(void)
{
    float Vitavi, VitVent, Resultante_Vitesse, Resultante_Derivee, AngVent;

    printf("Saisir la vitesse en noeud de l'appareil\n");
    scanf("%f", &Vitavi);

    printf("Saisir la vitesse du vent en noeud\n");
    scanf("%f", &VitVent);

    printf("Saisir l'angle entre l'appareil et le vent\n");
    scanf("%f",&AngVent);

    AngVent *= ConvRadDeg;
    Resultante_Vitesse = Vitavi + (VitVent * cosf(AngVent));
    Resultante_Derivee = ConvDegRad * (atan2f(VitVent , Vitavi));
    if(AngVent < PI)
        Resultante_Derivee *= -1;

    printf("Vitesse resultante de l'appareil [%.2f]\n" , Resultante_Vitesse);
    printf("Derive de l'appareil en degres [%.2f]\ncorriger votre route en augmentant votre cap de [%.2f]\n" , Resultante_Derivee, (Resultante_Derivee * -1));


}