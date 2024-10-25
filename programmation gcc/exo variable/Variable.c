#include <stdio.h>

int maVariable=0;
int maf;

int main (void)
{

for(int i=0;i<10;i++){

printf("valeur de ma variable %d\n" , maVariable);
maVariable += 20;



}

printf("Rentrer une valeur dans le terminale : \n");

printf("acienne valeur de ma variable : %d\n" , maf);
scanf("%d" , &maf);
printf("nouvelle valeur de ma variable : %d\n" , maf);

if(maf==2){

	printf("ok\n");
}

else
{
	printf("erreur\n");
}

	return 0;

}