#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

char charac;

#define tempsMaxStationnement 12

typedef enum TypePieces
{
    Pieces_1 = 1,
    Pieces_2 = 2,
    Pieces_5 = 5
}TypePieces;

typedef struct Stationnement{
    int tempsStationnement;
    int prix;
    TypePieces pieces;
    int monnaie;
    int somme;
}Stationnement;

void monnaie(Stationnement *Monstationnement, char *charac);


/* ---------------------------Déclarations---------------------------------------------------------- */



int main(void)
{
    Stationnement MonStationnement;             //instanciation de la structure
    MonStationnement.prix = 2;                  //initialisation du prix de la place
    srand(tempsMaxStationnement);               //initialisation de la génération de nombres aléatoires

    printf("Veuillez introduire une carte par l'appuie sur la touche 'c' \n");

    do
    {
        charac = getch();                       //Lecture des touches du clavier
    } while (charac != 'c');                    //Attente de la touche 'c' pour lancer le programme

    MonStationnement.tempsStationnement = rand();       
    printf("temps de stationnement %d\n" , MonStationnement.tempsStationnement);
    MonStationnement.prix = (MonStationnement.tempsStationnement * MonStationnement.prix);
    printf("Temps de stationnement : %d , somme a payer :  %d \n" , MonStationnement.tempsStationnement, MonStationnement.prix);
    

    while(charac != 'f')
    {
        charac = getch();    
        monnaie(&MonStationnement,&charac);
    }
    
    
    return 0;
}


/* -----------------------------Prototype fonctions----------------------------------------------------------- */

void monnaie(Stationnement *Monstationnement, char *charac)
{
    
    switch (*charac)
    {
    case '1' :
        Monstationnement->somme += 1;
        break;
    
    case '2' :
        Monstationnement->somme += 2;
        break;

    case '5' :
        Monstationnement->somme += 5;
        break;
    }
    printf("Ma somme : %d , Prix de la place : %d\n" , Monstationnement->somme, Monstationnement->prix);
    if(Monstationnement->somme >= Monstationnement->prix)
    {
        Monstationnement->monnaie = (int)((Monstationnement->somme - Monstationnement->prix));
        printf("Monnaie a percevoir %d\n", Monstationnement->monnaie);
        *charac = 'f';
    }
}