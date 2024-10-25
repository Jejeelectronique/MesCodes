#include <stdio.h>

/*
	== : égal à
	!= : différnt de 
	<  : plus petit que
	>  : plus grand que
	<= : plus petit ou égal que
	>= : plus grand ou égal que
	&& : et
	|| : ou 
	

*/
int main (void){

int jeu_démarre;
int level=0;
int age = 0;
int sexe;
int sexejoueur;
int securiter;

//utilisation if

printf ("Rentrer 0 pour jeu off et 1 pour jeux on\n");
scanf("%d" , &jeu_démarre);
printf("valeur rentrer : %d\n" , jeu_démarre);

if(jeu_démarre){

	printf("le jeu demarre\n");
}

else{

	printf("le jeu ne démarre pas\n");
}

printf ("choisissez le niveau de debut\n");
scanf("%d" , &level);


//utilisation switch

switch(level){

case 0:

	printf("niveau 0\n");
	break;

case 1:

	printf("niveau 1\n");
	break;

case 2:
	printf("niveau 2\n");
	break;

default:
	printf("niveau indisponible\n");
	break;

}

//utilisation d'un test de condition avec un "?"

printf("Entrer votre Age : \n");
scanf("%d" , &age);

(age >= 18) ? printf("l'age est superieur a 18 \n") : printf("l'age est inferieur au minimum autorise \n");
securiter = (age >= 18) ? 1 : 0;
if (!securiter){
	
}

printf("enter votre sexe : H = 1 , F = 2 \n");
scanf("%d" , &sexe);
 
sexejoueur = (sexe == 1) ? 1 : 0;

if(sexe){
	printf("le joueur est un homme \n");
}

else{

	printf("le joueur est une femme \n");
}

printf("appuyer sur une touche pour quitter \n");

scanf("%d");

return 0;

}