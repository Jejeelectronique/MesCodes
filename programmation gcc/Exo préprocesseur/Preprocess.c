#include <stdio.h>

#define ecrire printf

/*
	__FILE__(nom du fichier)
	__LINE__(ligne du fichier)
	__DATE__(date de compilation)
	__TIME__(heure de compilation)


*/

int main (void)
{

ecrire("nom du fichier %s\n" ,  __FILE__);
ecrire("ligne du fichier %d\n" ,  __LINE__);
ecrire("date de compilation %s\n" ,  __DATE__);
ecrire("heure de compilation %s\n" ,  __TIME__);





	return 0;
}