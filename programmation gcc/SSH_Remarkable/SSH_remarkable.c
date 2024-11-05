#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <libss.h>

#define MAX_SIZE_BUFFER 255
#define PASSWORD "NrnXjgL1yG"
#define IP_ADRESS "192.168.3.135"
#define MAC_ADRESS "B8:2D:28:67:28:02"
#define SSH_ROOT "ssh root@"

int main(int argc, char** argv)
{
    char TabletteIP[MAX_SIZE_BUFFER];
    char Commande[MAX_SIZE_BUFFER];
    int resultat;

    snprintf(Commande, sizeof(Commande), "%s%s" , SSH_ROOT, IP_ADRESS);
    resultat = system("ssh root@192.168.205.159");

    if(resultat == -1){
        fprintf(stderr, "Erreur envoi de la comande");
        exit(EXIT_FAILURE);}
    
    scanf("%d");

    return 0;
}