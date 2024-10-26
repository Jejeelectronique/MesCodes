#include "FEFY6900.h"


#define ACK 0x0a

Boolean ProgamnRUN = true;
Boolean Event = false;

typedef struct {
    void (*Tab)(int);
}Clavier;


char PortCom[5] = {"COM6"};



int main (void)
{

        Channel1.Amplitude = 2500;
        Channel1.Frequence = 52;
        init_Virtual_SerialCom(PortCom);

        SetFrequence(&Channel1);
        SetAmplitude(&Channel1);
        // if(!ReadFile(hSerial, response, sizeof(response) - 1, &bytesRead, NULL))                             {printf("Erreur lors de la lecture de la réponse.\n"); CloseHandle(hSerial); return 1;}   



    CloseHandle(hSerial);
    

    return 0;
}


