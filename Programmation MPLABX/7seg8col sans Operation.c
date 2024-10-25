#include <xc.h>
#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma config FOSC = XT     // Oscillator Selection (EXTRC oscillator: External RC circuit connected to CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable bit (VCAP pin function disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define C1   PORTCbits.RC0    //La colonne 1 est connectée au pin RC0 du PORTC
#define C2   PORTCbits.RC1    //La colonne 2 est connectée au pin RC1 du PORTC
#define C3   PORTCbits.RC2    //La colonne 3 est connectée au pin RC2 du PORTC

#define LA   PORTCbits.RC3    //La ligne 1 est connectée au pin RC3 du PORTC
#define LB   PORTCbits.RC4    //La ligne 2 est connectée au pin RC4 du PORTC
#define LC   PORTCbits.RC5    //La ligne 3 est connectée au pin RC5 du PORTC
#define LD   PORTCbits.RC6    //La ligne 4 est connectée au pin RC6 du PORTC

#define SW PORTDbits.RD7      //Le switch est connecter au pin de RD7 du PORTD
#define RESET PORTCbits.RC7   // Le Reset est relier au pin RC7 du PORTC

#define _XTAL_FREQ 16000000   //definission de la vitesse du quartz interne
#define DISPLAY PORTD         //L'afficheur 7 Segment est connecté au PORTD
#define ANODES PORTB          //Les anodes des afficheurs 7 segments sont connectées au PORTB

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t key,cnt,UN,DEUX,TROIS,QUATRE,CINQUE,SIX,SEPT,HUIT;                    // déclaration des variables qui seront utilisé pour stocker la valeur des nombres des 8 colonnes a afficher ainsi que le compteur qui permet de piloter le tous 

//                   (  0 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9 / * / # /Rien)  //Affichage des segments et leur correspondances
uint8_t chiffres[13]={192,249,164,176,153,146,130,216,128,144,156,171,127};   // déclaration d'un tableau qui facilitent l'appel des valeur correspond au nombres a afficher

void clavier();         //rappel de fonction
void test();            //rappel de fonction
void affichage();       //rappel de fonction
void Segment();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void main()                     //Déclaration du programme principal
{
  

TRISB=0b00000000;               //Tout le PORTB est configuré en sortie
TRISD=0b00000000;               //Tout le PORTD qui est connecter aux anodes (SA,SB,etc...) est configuré en sortie sauf RD7 du SW qui est config en entrée
TRISC=0b01111000;               //Les portc de RC3 à R6 qui gerent les  lignes (LA...) par le clavier seront configurés en entrée
                                

PORTB=0b00000000;               //Initialisation du PORTA par la valeur 1 pour les pins de RA0...RA3 et la valeur 0 pour le reste du PORT
PORTD=0;                        //Initialisation du PORTB par la valeur 0
PORTC=0;                        //Initialisation du PORTC par la valeur 0

cnt=0;                          //initialisation à 0 du compteur qui sert au pilotage de l'affichage selon la colonne

UN=12;                         //Le code de la premiere colonne
DEUX=12;                       //Le code de la deuxieme colonne
TROIS=12;                      //Le code de la troisieme colonne
QUATRE=12;                     //Le code de la quatrieme colonne
CINQUE=12;                     //Le code de la cinquieme colonne
SIX=12;                        //Le code de la sixieme colonne
SEPT=12;                       //Le code de la septieme colonne
HUIT=12;                       //Le code de la huitieme colonne

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



while(1)
{

    Segment();

}
}










void clavier()
{
    C1 = 1;  C2 = 0;  C3 = 0;       //Etat de la colonne qui combinner avec l'etat des lignes permet l'affichage de different Nombres                                            
    if(LA == 1){key = 1;cnt++;while(LA == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    if(LB == 1){key = 4;cnt++;while(LB == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    if(LC == 1){key = 7;cnt++;while(LC == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter           
    if(LD == 1){key = 10;cnt++;while(LD == 1){affichage();}}        //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    
    
    
    C1 = 0;  C2 = 1;  C3 = 0;       //Etat de la colonne qui combinner avec l'etat des lignes permet l'affichage de different Nombres
    if(LA == 1){key = 2;cnt++;while(LA == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    if(LB == 1){key = 5;cnt++;while(LB == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    if(LC == 1){key = 8;cnt++;while(LC == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    if(LD == 1){key = 0;cnt++;while(LD == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
     
    
    C1 = 0;  C2 = 0;  C3 = 1;       //Etat de la colonne qui combinner avec l'etat des lignes permet l'affichage de different Nombres
    if(LA == 1){key = 3;cnt++;while(LA == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    if(LB == 1){key = 6;cnt++;while(LB == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    if(LC == 1){key = 9;cnt++;while(LC == 1){affichage();}}         //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    if(LD == 1){key = 11;cnt++;while(LD == 1){affichage();}}        //affichage selon l'etat de l'entree de la ligne (LA) du pad, la fonction affichage dans la boucle while permet de garder afficher le nombre precedent jusqu'a relachement de la touche, le compteur pour le pilotage de l'ecran et également incrémenter
    
    
    if(RESET == 1){UN=12;DEUX=12;TROIS=12;QUATRE=12,CINQUE=12,SIX=12,SEPT=12,HUIT=12;cnt=0;}        // réinitialisation de l'afficheur et du compteiur à l'aide du bouton reset
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void test ()
{
    
    if(cnt==1){UN=key;} //affichage du premier chiffre
    if(cnt==2){DEUX=UN,cnt++;} //décalage vers la gauche
    if(cnt==3){UN=key;} //affichage du deuxieme chiffres
    if(cnt==4){TROIS=DEUX,DEUX=UN, cnt++;} //décalage vers la gauche
    if(cnt==5){UN=key;} //affichage du troisieme chiffre
    if(cnt==6){QUATRE=TROIS,TROIS=DEUX,DEUX=UN, cnt++;} //décalage vers la gauche
    if(cnt==7){UN=key;} //affichage du quatrieme chiffre
    if(cnt==8){CINQUE=QUATRE,QUATRE=TROIS,TROIS=DEUX,DEUX=UN, cnt++;} //décalage vers la gauche
    if(cnt==9){UN=key;} //affichage du quatrieme chiffre
    if(cnt==10){SIX=CINQUE,CINQUE=QUATRE,QUATRE=TROIS,TROIS=DEUX,DEUX=UN, cnt++;} //décalage vers la gauche
    if(cnt==11){UN=key;} //affichage du quatrieme chiffre
    if(cnt==12){SEPT=SIX,SIX=CINQUE,CINQUE=QUATRE,QUATRE=TROIS,TROIS=DEUX,DEUX=UN, cnt++;} //décalage vers la gauche
    if(cnt==13){UN=key;} //affichage du quatrieme chiffre
    if(cnt==14){HUIT=SEPT,SEPT=SIX,SIX=CINQUE,CINQUE=QUATRE,QUATRE=TROIS,TROIS=DEUX,DEUX=UN, cnt++;} //décalage vers la gauche
    if(cnt==15){UN=key;} //affichage du quatrieme chiffre
    if(cnt==16){UN=12;DEUX=12;TROIS=12;QUATRE=12,CINQUE=12,SIX=12,SEPT=12,HUIT=12;cnt=0;} //réini de l'affichage
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void affichage()
{
        
    ANODES=0b00000001;          //PORTD RD0 à l'état haut
    DISPLAY=chiffres[UN];       // l'etat du PORTD(display) depend de la valeur de [UN] qui elle meme depend de KEY qui depend de la pression sur le nombres du clavier et l'etat du compteur
    __delay_ms(1);              //delais pour pouvoir gerer l'afficheur, le delais doit etre cours pour eviter de voire des clignotements

    ANODES=0b00000010;          //PORTD RD1 à l'état haut
    DISPLAY=chiffres[DEUX];     // l'etat du PORTD(display) depend de la valeur de [DEUX] qui elle meme depend de KEY qui depend de la pression sur le nombres du clavier et l'etat du compteur  
    __delay_ms(1);              //delais pour pouvoir gerer l'afficheur, le delais doit etre cours pour eviter de voire des clignotements

    ANODES=0b00000100;          //PORTD RD2 à l'état haut
    DISPLAY=chiffres[TROIS];    // l'etat du PORTD(display) depend de la valeur de [TROIS] qui elle meme depend de KEY qui depend de la pression sur le nombres du clavier et l'etat du compteur
    __delay_ms(1);              //delais pour pouvoir gerer l'afficheur, le delais doit etre cours pour eviter de voire des clignotements

    ANODES=0b00001000;          //PORTD RD3 à l'état haut
    DISPLAY=chiffres[QUATRE];   // l'etat du PORTD(display) depend de la valeur de [QUATRE] qui elle meme depend de KEY qui depend de la pression sur le nombres du clavier et l'etat du compteur
    __delay_ms(1);              //delais pour pouvoir gerer l'afficheur, le delais doit etre cours pour eviter de voire des clignotements
    
     ANODES=0b00010000;         //PORTD RD4 à l'état haut
    DISPLAY=chiffres[CINQUE];   // l'etat du PORTD(display) depend de la valeur de [CINQUE] qui elle meme depend de KEY qui depend de la pression sur le nombres du clavier et l'etat du compteur 
    __delay_ms(1);              //delais pour pouvoir gerer l'afficheur, le delais doit etre cours pour eviter de voire des clignotements

    ANODES=0b00100000;          //PORTD RD5 à l'état haut
    DISPLAY=chiffres[SIX];
    __delay_ms(1);              //delais pour pouvoir gerer l'afficheur, le delais doit etre cours pour eviter de voire des clignotements

    ANODES=0b01000000;          //PORTD RD6 à l'état haut
    DISPLAY=chiffres[SEPT];     // l'etat du PORTD(display) depend de la valeur de [SIX] qui elle meme depend de KEY qui depend de la pression sur le nombres du clavier et l'etat du compteur
    __delay_ms(1);              //delais pour pouvoir gerer l'afficheur, le delais doit etre cours pour eviter de voire des clignotements

    ANODES=0b10000000;          //PORTD RD7 à l'état haut
    DISPLAY=chiffres[HUIT];     // l'etat du PORTD(display) depend de la valeur de [SIX] qui elle meme depend de KEY qui depend de la pression sur le nombres du clavier et l'etat du compteur
    __delay_ms(1);              //delais pour pouvoir gerer l'afficheur, le delais doit etre cours pour eviter de voire des clignotements
}

void Segment()
{
     clavier();
     
     test();
     
     affichage();  
}
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////