#include <stdio.h>
#include "malibraire.h"
void fTVA (void);
void carburant (void);
void heuresPassé (void);
static void age(void);


/*l'on peut mettre static devant une fonction pour la forcé à etre 
appelé uniquement dans le fichier ou elle codé et pas ailleurs, cela
revient à un fonction PRIVATE en POO.*/

int TVA = 20;

int main (void)
{


bonjour();
printf("ma TVA actuelle : %d\n" , TVA);

int i=0;

while (i<10){

	fTVA();
	carburant();
	heuresPassé();
	age();
i++;
}


	return 0;
}
/*-------------------------------------------------------------------------------*/

/*fonction avec une variable déclarer en globale, celle-ci s'incrémente donc
bien à la fin de la fonction
*/

void fTVA (void)
{
	printf("TVA = %d\n" , TVA);
	TVA += 10;
}
 	
/*-------------------------------------------------------------------------------*/

/*fonction avec variable interne déclarer en int, on voie que celle ci
se détruit à la fin de chaque éxecution et recommence à zero*/

void carburant (void)
{
int prixCarb = 0;
prixCarb += 10;
printf("augmentation du prix du carburant %d\n" , prixCarb);

}

/*-------------------------------------------------------------------------------*/

/*fonction avec une variable local mais déclarer en static qui permet de conserver
sa valeur sans la détruire meme si l'on déclare au début de la fonction à 0 comme suivie
int static mavariable = 0
*/

void heuresPassé (void)
{
	static int heures=0;
	printf("nombres d'heures passe %d\n" , heures);
	heures += 1;
}

static void age(void)
{
	static int age=0;
	printf("mon age %d\n" , age);
	age++;
}
