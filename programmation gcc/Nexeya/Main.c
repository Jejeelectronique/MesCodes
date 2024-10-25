#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "CVI.h"

char chaine1[17] = {"FichierTest"};


int main(void)
{   
    while(myEvent.stateProg)
    {
        myEvent.event_occurs(&myEvent.key);
        switch (myEvent.key)
        {
        case 'a':
            printf("a");
            break;
        case 'b' :
            myEvent.stateProg = ProgOFF;
            break;
        default:
            break;
        }
    }

    print_json(chaine1);
    
    return 0;
}