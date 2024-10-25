#include <stdio.h>
#define TailleTab 5

int monTab[TailleTab] = {34,32,1,2,4};

int main (void){

// boucle while classique

	int i = 0;
	while (i<20){
		printf("boucle numero : %d\n" , i);
		i++;

// démonstation d'un boucle qui ne s'execut pas

}
		while(i>20){
 		printf("cette boucle s'éxecute t'elle? : %d\n" , i);

	}
// exempl d'une boucle  Do while qui s'éxecute au moins une fois
i=0;
	do {
		printf("boucle numero de mon do while: %d\n" , i);
		i++;
	}
		while(i<5);
	
// exemple d'une boucle for avec un tableau

for (i=0; i<TailleTab;i++){

	printf("valeur de l'index : %d de mon tableau = %d\n" , i , monTab[i]);

}

//exemple d'une boucle while avec un break

while(1){

	printf("boucle infinie \n");
	break;
	}
	printf("fin de la boucle suite a un break \n");



}