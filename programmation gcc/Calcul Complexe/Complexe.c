#include <stdio.h>
#include <math.h>

float reel;
float im;

void calc(float *Real,float *complexe);

int main (void)
{
	printf ("Rentrer la partie des reel\n");
	scanf("%f" , &reel);
	printf ("Rentrer la partie des imaginaires\n");
	scanf("%f" , &im);
	calc(&reel,&im);
	printf("Rentrer un chiffre ou une lettre et appuyer sur entree pour quitter\n");
	scanf("%d");

}

void calc(float *Real,float *complexe)
{
	float amplitude = sqrt((pow(*Real,2)) + pow(*complexe,2));
	float phase = atan2(*complexe,*Real);

	printf("Amplitude : %f\n", amplitude);
    printf("Phase en radians: %f\n", phase);
    printf("Phase en degres: %f\n", phase * (180.0 / M_PI));
}	