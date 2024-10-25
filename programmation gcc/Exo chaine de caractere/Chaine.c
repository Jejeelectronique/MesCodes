#include <stdio.h>
#include <string.h>

/**
 Un tableau de caractére doit avoir un emplacement
 supplémentaire pour spécifier que c'est un tableau de char
 exemple : 
	
	char [2] = "A"; //il faut un tableau de 2 pour stocker A

	char [0] = ["A"]
	char [1] = ["\0"] // caractere de fin pour une chaine

	[Fonction des chaines]
		strcpy(destination,source) : copie une chaine de caractere
		strlen(lemot) : longeur d'une chaine sans le caractere de fin de chaine
		strcmp(mot1,mot2) :  compare deux chaines (lexicographiquement) // renvoie zero si les 2 mot sont les memes
		strcat(chaine1,chaine2) : fusionne 2 chaine
		strstr() : chercher une chaine dans une autre
		strchr() : chercher 1er occurence du caractere

		sprintf(variableCar, laChaineQueJeVeuxEcrire,TailleduTableau) : écrire dans une chaine (on ne compte pas le carac supplémentaire dans la taille)
 **/

int main (void)
{	
	char mot2[26];
	char mot1[26];
 
	char fus1[] = "comment ";
	char fus2[] = "ca va?";

	char strchrVariable1[] = "allez vous bien il faut bien";
	char strchrVariable2[] = "bien";

	char sprintfVar[256];


	signed char mot[] = "bonjour";
	signed char stockage[256];
	//signed char mot[] = {'b','o','n','j','o','u','r'}; modele de stockage possible
	printf("%s\n" , mot);

	signed char prenom[26];

	printf("comment tu t'appelle ?\n");
	scanf("%s" , prenom);
	printf("Ton prenom  : %s\n" , prenom);

	strcpy(prenom,stockage);

	printf("comment tu t'appelle maintenant ?\n");
	scanf("%s" , prenom);
	printf("Ton prenom  : %s\n" , prenom);

	printf("Entrer du texte pour mot1 = \n");
	scanf("%s" , mot1);
	printf("Entrer du texte pour mot2 = \n");
	scanf("%s" , mot2);
	int test = strcmp(mot1,mot2);

	if(test){

		printf("les mots ne sont pas les meme \n");
	}

	else{
		printf("les mots sont les meme \n");
	}


	printf("%s\n", strcat(fus1,fus2));


	if(strstr(mot1,mot2) != NULL){
		printf("occurence trouver \n");
	}

	else
	{
		printf("aucune occurence trouver \n");
	}

	char *res = strchr(strchrVariable1,*strchrVariable2);
	printf("%s\n" , res);

	sprintf(sprintfVar, "bonjour", 7);
	printf("ma fonction sprinf   :   %s\n" , sprintfVar);

	return 0;
}

