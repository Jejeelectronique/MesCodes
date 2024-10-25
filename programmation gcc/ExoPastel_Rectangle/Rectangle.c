#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define Pi 3.141592653589

typedef struct rectangle{

    double longueur;
    double largeur;
    double surface;
    double Longueur_Segment_losange;
    double SurfaceLosange;
    double SurfaceEllipse;
    
}rectangle;



int main(void)
{
    rectangle Monrectangle;

    printf("saisisez la longueur de votre rectangle en metres \n");
    scanf("%lf" , &Monrectangle.longueur);

    printf("saisisez la largeur de votre rectangle en metres \n");
    scanf("%lf" , &Monrectangle.largeur);

    Monrectangle.surface = (Monrectangle.largeur * Monrectangle.longueur);
    Monrectangle.Longueur_Segment_losange = sqrt( ((Monrectangle.longueur * Monrectangle.longueur)/4) + ((Monrectangle.largeur * Monrectangle.largeur)/4) );
    Monrectangle.SurfaceLosange = ( Monrectangle.largeur * (Monrectangle.longueur / 2) );
    Monrectangle.SurfaceEllipse = ((Monrectangle.largeur /2) * (Monrectangle.longueur/2) * Pi);

    printf("Longueur de mon rectangle en metres : %.3lf \n Largeur de mon rectangle metres  %.3lf \n Surface de mon rectangle en m2 %.3lf \n Surface de mon losange en m2 %.3lf \n Surface de mon ellipse en m2 %.3lf \n" , 
    Monrectangle.longueur,
    Monrectangle.largeur,
    Monrectangle.surface,
    Monrectangle.SurfaceLosange,
    Monrectangle.SurfaceEllipse
    );

    return 0;
}