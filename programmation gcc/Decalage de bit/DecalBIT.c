#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Delay 7

void affichebin(unsigned n, unsigned char Affichage);
void SaisieEtAffichageData();
void Decalage(unsigned char Vala);
void my_delay(int x);
long long int timer;
long long int Oldtimer;

int main(void)
{
	SaisieEtAffichageData();
	my_delay(Delay);
}



void affichebin(unsigned n, unsigned char Affichage)
{
	unsigned bit = 0 ;
	unsigned mask = 1 ;
	unsigned NbBits = 0;
	for (int i = 0 ; i < 8 ; ++i)
	{
		bit = ((n >> (7 - i)) & mask);
		printf("%d", bit);
	}
	if (Affichage)
	{
	NbBits++;
	printf("          Affichage du bit numeros%d\n" , NbBits);
	}
	else
	{
		NbBits = 0;
	}
}


void Decalage(unsigned char Vala)
{
	unsigned char ValBits = 0;
	unsigned char CtrlValBits = 0;

	affichebin(Vala,0);
	printf("          Data en binaire a decaler\n");

	for (int i=0; i<8; i++)                     //Les données sont envoyer par paquets de 8bits que l'on appelle un "mot"
    {
    	ValBits = (Vala >> (7 - i) & 0x01);
    	affichebin(ValBits, 1);
    	CtrlValBits |= (ValBits << (7 - i));
    }

    printf("\n");
    affichebin(CtrlValBits,0);
    printf("          Controle de tous les bits declaer\n");
}

void SaisieEtAffichageData()
{	
	int ctrw = 0;
	int Val = 0;
	printf("Rentrer la valeur de l'octet sous forme decimal non signer\n");
	scanf("%d",&Val);
	while(1)
	{
		if (Val >= 255 || Val < 0)
		{

				printf("La valeur n'est pas un octet non signer, entrer une nouvelle valeur\n");
				scanf("%d",&Val);
		}

		else if (Val < 255 || Val > 0)
		{
		Decalage(Val);
		break;
		my_delay(5);
		}
	}
}

void my_delay(int x) /* Pause l'application pendant x secondes */
{
    time_t start_time, current_time;
    time(&start_time); // Obtenez le temps de départ
    while (1)
    {
        time(&current_time); // Obtenez le temps actuel
        if (difftime(current_time, start_time) >= x)
        break; // Quittez la boucle si le temps écoulé est supérieur ou égal à x secondes
    }
}
