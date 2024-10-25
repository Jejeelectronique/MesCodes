#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef enum Chauff{
    desactiver,
    activer,
    non_def
}Chauff;

typedef enum EtatProg{
    ProgrammOFF,
    ProgrammRUN,
    ProgrammRunAgain
}EtatProg;

char StringAffichage [2][12] = {{"desactiver"} , {"activer"}};

void PrintBin(unsigned char a);
void InstructionsChauffage(unsigned char *chauffage);
void printEtatChauffage(unsigned char a);


/* --------------------------Déclarations------------------------------------------------------------------------------------ */


int main(void)
{
    unsigned char chauffage = 0;
    unsigned char NumChauffage = 0;

    printf("saisir une valeur de chauffage \n");
    scanf("%d" , &chauffage);
    printEtatChauffage(chauffage);
    EtatProg prog = ProgrammRUN;
    
    while(prog)
    {
        InstructionsChauffage(&chauffage);
        printEtatChauffage(chauffage);

        printf("Voulez vous modifier l'etat d'autre chauffages? SpaceBar : yes |  Tab : no\n");
        prog = ProgrammRunAgain;

        while((prog & ProgrammRunAgain)) 
        {
            if(GetAsyncKeyState(VK_SPACE) & 0x8000)
                prog = ProgrammRUN; 

            else if(GetAsyncKeyState(VK_TAB) & 0x8000)
                prog = ProgrammOFF;

            Sleep(40);
        }   
    }
    return 0;
}


/* ---------------------------Prototypes----------------------------------------------------------------------------------- */

void PrintBin(unsigned char a)
{
    for(int i = 0; i < 8; i++)
        printf("%d" , ((a >> i) & 1));
    printf("\n");
}



void InstructionsChauffage(unsigned char *chauffage)
{
    unsigned char Num_chauffage;

    Chauff controle = non_def;
    printf("Appuyez sur la touche pour selectionner -> [Ctrl : activer] --- [Maj : desactiver]\n");

    while(controle == non_def)
    {
        if(GetAsyncKeyState(VK_CONTROL) & 0x8000)
            controle = activer;
        
        Sleep(20);

        if(GetAsyncKeyState(VK_SHIFT) & 0x8000)
            controle = desactiver;

         Sleep(20);
    }
    
    printf("Saisir la valeur du chauffage a modifier\n");
    scanf("%hhu" , &Num_chauffage);

    unsigned char Nchauffage = 0;

    switch (controle)
    {
    case activer :
        Nchauffage = (1 << (Num_chauffage - 1));
        *chauffage |= Nchauffage;
        break;
    
    case desactiver :
        Nchauffage = ~(1 << (Num_chauffage - 1));
        *chauffage &= Nchauffage;
        break;

    default :   
        printf("Erreur fonction instruction chauffage\n");
        break;
    }
}


void printEtatChauffage(unsigned char a)
{
    for(int i = 0; i < 8; i++)
        printf("etat du chauffage %d : %s\n" , (i+1) ,StringAffichage[((a >> i) & 1)]);
        
    printf("\n");
}
