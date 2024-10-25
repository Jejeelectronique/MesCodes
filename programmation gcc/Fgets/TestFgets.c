#include <stdio.h>
#include <stdlib.h>

int Fgets_SaisieClav(char *buffer, int Size);
void ViderBufferClavier();
long CopieStrTolong();

int main(int argc, char *argv[]){

char nom[10];
printf("%d\n",(int)sizeof(long long));
printf("quelle est votre prenom?\n");
Fgets_SaisieClav(nom, 10);
printf("votre prenom est donc : [%s]\n", nom);
printf("Rappeler moi votre prenom?\n");
Fgets_SaisieClav(nom, 10);
printf("ah c'etais bien %s!\n", nom);

double ageAmi;
printf("veuiller enregistrer l'age de votre ami\n");
ageAmi = CopieStrTolong();
printf("l age de votre ami est de : [%d]\n", (int)ageAmi);

return 0;
}



int Fgets_SaisieClav(char *buffer, int Size)
{
    if(!fgets(buffer, Size, stdin))
        return 0;

    for(int i = 0; i < Size; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            return 1;
        }
    }
    ViderBufferClavier();
    return 0;
}

void ViderBufferClavier()
{
    int c = 0;
    while(c != '\n' && c != EOF)
        c = getchar();
}

long CopieStrTolong()
{
    char str[100];
    if(!(Fgets_SaisieClav(str,100)))
        return 0;
    

    return strtol(str, NULL, 10);
}