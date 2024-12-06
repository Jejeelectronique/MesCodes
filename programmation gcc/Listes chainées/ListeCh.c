#include "ListeCh.h"

// elementsList* initList(elementsList *elm)
// {
//     elm = malloc(sizeof(*elm));
//     if(elm == NULL)
//     {
//         fprintf(stderr, "Erreur lors de l'allocation de mémoire \n");
//         exit(EXIT_FAILURE);
//     }  
//     elm->next = NULL; 
//     return elm;
// }


elementsList* pop_front_List(elementsList *elm)
{
    elementsList* temp = malloc(sizeof(*temp));
    if(temp == NULL)
    {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire \n");
        exit(EXIT_FAILURE);
    }

    if(elm != NULL)
    {
        temp = elm->next;
        free(elm);
        elm = temp;
    }

    return temp;
}

elementsList* pop_back_List(elementsList *elm)
{
    elementsList* after = malloc(sizeof(*after));
    if(after == NULL)
    {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire \n");
        exit(EXIT_FAILURE);
    }
    after = elm->next;

    elementsList* before = elm;

    for(int i = 0; i < MAX_LISTE_SIZE; i++)
    {
        if(after->next != NULL)
        {
            after = after->next;
            elm = elm->next;
        }
        else
        {
            // free(elm);
            // elm = NULL;
            // elm = before;
            // return elm;
        }
    }

    return elm;
}


elementsList* push_front_List(elementsList *elm, int value)
{
    elementsList* temp = malloc(sizeof(*temp));
    if(temp == NULL)
    {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire \n");
        exit(EXIT_FAILURE);
    }

    if(elm == NULL)
    {
        temp->valeur = value;
        temp->next = NULL;
        return temp;       
    }
    temp->valeur = value;
    temp->next = elm;

    return temp;
}



elementsList* push_back_List(elementsList *elm, int value)
{
    elementsList* after = malloc(sizeof(*after));

    if(after == NULL)
    {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire \n");
        exit(EXIT_FAILURE);
    }

    after->valeur = value;
    after->next = NULL;

    if(elm == NULL)
        return after;

    elementsList* temp = elm;

    for(int i = 0; i < MAX_LISTE_SIZE; i++)
    {
        if(temp->next == NULL)
        {
            temp->next = after;
            return elm;
        }
        temp = temp->next;
    }

    printf("Taille maximale de la liste depasse\n");
    return elm;
}


elementsList* CleanList(elementsList *elm)
{
    while(elm->next != NULL)
        pop_front_List(elm);
    return elm;
}

void printList(elementsList *elm)
{
    elementsList* temp = elm;
    for(int i = 0; i < MAX_LISTE_SIZE; i++)
    {
        printf("element numero %d de la liste avec la valeur : %d\n" , i , temp->valeur);
        if(temp->next == NULL)
            return;
        temp = temp->next;
    }
}