#include "CVI.h"
#include <Windows.h>
CtrlString ControleString;
MyEvent myEvent = {.event_occurs = event_occurs,
                    .stateProg = ProgOFF};


void  print_json(char Name[17])
{

    int time = 1254, temp = time;
    int Deci = NbDecimals(time);
    char *tab = malloc(sizeof(char) * Deci);
    for(int i = 0; i < Deci; i++)
    {
        tab[i] = ((time / (10 * i)) & 0xFF);
        printf("tab[%d] : %c", i, tab[i]);
    }
    sprintf(Name, "%s.json",Name);
    fopen(Name, "w+");
    free(tab);
}


char *concat(char *Name, char *NameBis)
{
    int a = 0;
    for(int i = 0; i < 17; i++)
    {
        if(Name[i] == '\0')
            ControleString = true;
        if(NameBis[a] == '\0')
            break;
            
        switch (ControleString)
        {
        case true :
            Name[i] = NameBis[a];
            a++;
            break;
        
        default:
            break;
        }
    } 
return Name; 
}


int NbDecimals(int temp)
{
    int it = 0;
    do
    {
        if(!temp)
            break;
        temp /=10;
        it++;
    } while (temp >= 0);
    return it;
}


int event_occurs(Key *key)
{
    for(int i = 0; i < 256; i++)
    {
        if(GetAsyncKeyState(i) & 0x8000)            //0x8000 vérifie si la touche est enfoncé
        {
            *key = i;
            return i;
        }
    }
}