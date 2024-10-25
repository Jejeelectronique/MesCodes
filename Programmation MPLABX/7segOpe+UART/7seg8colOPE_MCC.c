#include <xc.h>
#include <stdint.h>
#include "mcc_generated_files/system/system.h"


#define C1   PORTCbits.RC0    //La colonne 1 est connectée au pin RC0 du PORTC
#define C2   PORTCbits.RC1    //La colonne 2 est connectée au pin RC1 du PORTC
#define C3   PORTCbits.RC2    //La colonne 3 est connectée au pin RC2 du PORTC

#define LA   PORTCbits.RC3    //La ligne 1 est connectée au pin RC3 du PORTC
#define LB   PORTCbits.RC4    //La ligne 2 est connectée au pin RC4 du PORTC
#define LC   PORTCbits.RC5    //La ligne 3 est connectée au pin RC5 du PORTC
#define LD   PORTEbits.RE0    //La ligne 4 est connectée au pin RC6 du PORTC

#define PLUS    PORTAbits.RA0   
#define MOINS   PORTAbits.RA1    
#define MULTI   PORTAbits.RA2    
#define DIV     PORTAbits.RA3    
#define EGUAL   PORTAbits.RA4
#define EXPON   PORTAbits.RA5


#define addition 1
#define soustraction 2
#define multiplication 3
#define division 4
#define exponentielle 5


#define RESET PORTEbits.RE1   // Le Reset est relier au pin RC7 du PORTC

#define _XTAL_FREQ 16000000   //definission de la vitesse du quartz interne
#define DISPLAY PORTD         //L'afficheur 7 Segment est connecté au PORTD
#define ANODES PORTB          //Les anodes des afficheurs 7 segments sont connectées au PORTB

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t key,cnt,UN,DEUX,TROIS,QUATRE,CINQUE,SIX,SEPT,HUIT,operateur,Neant=12,ctrl;               // déclaration des variables qui seront utilisé pour stocker la valeur des nombres des 8 colonnes a afficher ainsi que le compteur qui permet de piloter le tous 

//                   (  0 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9 / * / # /Neant)  //Affichage des segments et leur correspondances
uint8_t chiffres[13]={192,249,164,176,153,146,130,216,128,144,156,171,127};   // déclaration d'un tableau qui facilitent l'appel des valeur correspond au nombres a afficher
uint8_t chiffresOpe1[8]={0,0,0,0,0,0,0,0};   // déclaration d'un tableau qui facilitent l'appel des valeur correspond au nombres a afficher
uint8_t chiffresOpe2[8]={0,0,0,0,0,0,0,0};   // déclaration d'un tableau qui facilitent l'appel des valeur correspond au nombres a afficher
uint8_t chiffresOpeResultat[8]={0,0,0,0,0,0,0,0};   // déclaration d'un tableau qui facilitent l'appel des valeur correspond au nombres a afficher
uint8_t stockageChiffres[8]={0,0,0,0,0,0,0,0};

void clavier();         //rappel de fonction
void test();            
void affichage();       
void Segment();
void operation(); 
void reset();
void reset_ope();


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void main()                     //Déclaration du programme principal
{
SYSTEM_Initialize();
TRISB=0b00000000;               
TRISD=0b10000000;               
TRISC=0b10111000;               
TRISA=0x00;
TRISE=0xF;
ANSELE=0X0;                     //Ansel 0 = digital mode ; Ansel 1 = analog mode
ANSELA=0x00;

PORTB=0x00;              
PORTD=0x00;                        
PORTC=0x00;                        
PORTA=0x00;
PORTE=0x00;

cnt=0;                          //initialisation à 0 du compteur qui sert au pilotage de l'affichage selon la colonne

UN=Neant;                         //Le code de la premiere colonne
DEUX=Neant;                       //Le code de la deuxieme colonne
TROIS=Neant;                      //Le code de la troisieme colonne
QUATRE=Neant;                     //Le code de la quatrieme colonne
CINQUE=Neant;                     //Le code de la cinquieme colonne
SIX=Neant;                        //Le code de la sixieme colonne
SEPT=Neant;                       //Le code de la septieme colonne
HUIT=Neant;                       //Le code de la huitieme colonne

UART1.Write(25);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



while(1)
{

    Segment();

}
}


void reset_ope()
{
 UN=Neant;DEUX=Neant;TROIS=Neant;QUATRE=Neant,CINQUE=Neant,SIX=Neant,SEPT=Neant,HUIT=Neant;cnt=0;        // réinitialisation de l'afficheur et du compteiur à l'aide du bouton reset
 for (int i =0; i<8; i++){stockageChiffres[i] = 0;} 
}

void reset()
{
 UN=Neant;DEUX=Neant;TROIS=Neant;QUATRE=Neant,CINQUE=Neant,SIX=Neant,SEPT=Neant,HUIT=Neant;cnt=0;        // réinitialisation de l'afficheur et du compteiur à l'aide du bouton reset
 for (int i =0; i<8; i++){stockageChiffres[i] = 0;} 
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
    if(RESET == 1){reset();}
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
    //if(cnt==16){UN=Neant;DEUX=Neant;TROIS=Neant;QUATRE=Neant,CINQUE=Neant,SIX=Neant,SEPT=Neant,HUIT=Neant;cnt=0;} //réini de l'affichage
    
    stockageChiffres[0]=UN; stockageChiffres[1]=DEUX; stockageChiffres[2]=TROIS; stockageChiffres[3]=QUATRE; stockageChiffres[4]=CINQUE; stockageChiffres[5]=SIX; stockageChiffres[6]=SEPT; stockageChiffres[7]=HUIT;
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

void operation()
{
    //for(i=0;i<8;i++){if(stockageChiffres[i]>9){stockageChiffres[i]=0;}}
    if(PLUS == 1){operateur=addition;ctrl=1;}
    if(MOINS == 1){operateur=soustraction;ctrl=1;}
    if(DIV == 1){operateur=division;ctrl=1;}
    if(MULTI == 1){operateur=multiplication;ctrl=1;}
    
    if (operateur > 0 && ctrl > 0){for(int i=0;i<8;i++){chiffresOpe1[i] = stockageChiffres[i];}reset();cnt = 0;ctrl=0;}

    if(EGUAL == 1 && operateur > 0){for(int i=0;i<8;i++){chiffresOpe2[i]=stockageChiffres[i];}
    cnt = 0;

        switch (operateur){


            case addition :
                for(int i=0;i<8;i++){
                    chiffresOpeResultat[i] = chiffresOpe1[i]+chiffresOpe2[i];
                    }
                
                for(int i=0;i<8;i++){
                    if(chiffresOpeResultat[i]>10){
                        chiffresOpeResultat[i]-=10;chiffresOpeResultat[i+1]+=1;  
                        }
                    }
                operateur=0;
                UN=chiffresOpeResultat[0]; DEUX=chiffresOpeResultat[1]; TROIS=chiffresOpeResultat[2]; QUATRE=chiffresOpeResultat[3]; CINQUE=chiffresOpeResultat[4]; SIX=chiffresOpeResultat[5]; SEPT=chiffresOpeResultat[6]; HUIT=chiffresOpeResultat[7];
                break;



            case soustraction :
                for(int i=0;i<8;i++){
                    chiffresOpeResultat[i] = chiffresOpe1[i]-chiffresOpe2[i];
                    }
                operateur=0;
                break; 



            case multiplication :

                for(int i=0;i<8;i++){
                    chiffresOpeResultat[i] = chiffresOpe1[i]*chiffresOpe2[i];
                    }
                operateur=0;
                break;



            case division :

                for(int i=0;i<8;i++){
                    chiffresOpeResultat[i] = chiffresOpe1[i]/chiffresOpe2[i];
                    }
                operateur=0;
                break;

            }
         
        }
    
    }


void Segment()
{
     clavier();
     
     test();
     
     affichage(); 
     
     operation();
}
    
