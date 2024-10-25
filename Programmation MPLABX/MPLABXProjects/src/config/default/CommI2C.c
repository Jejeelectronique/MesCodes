#include "CommI2C.h"
#include "CommI2C.h"
static uint8_t StatusACK = 0;


I2C_Com Wire = 
{
    .SendData = SendData,
    .SendAdress = SendAdress,
    .ReceptionData = ReceptionData,
    .beginReception = beginReception,
    .beginTransmission = beginTransmission,
    .I2C_wait_for_idle = I2C_wait_for_idle,
    .Send_NACK = Send_NACK,
    .Send_ACK = Send_ACK,
    .restart = restart,
    .StopCom = StopCom,
    .StartCom = StartCom
};

/*------------------------Blocs utilisables------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

uint8_t SendData(uint8_t data)                                                //Fonction d'envoie de donn�es
{
    while(BufferTXstatus);
    I2C_wait_for_idle();
    BufferTransmission = data;                                          //Mettre la ligne � 1 � la fin de la transmission pour �viter de brouiller le signal ACK de l'esclave � la fin de la transmission du mot
    while(BufferTXstatus);                                              //On attend la fin de l'envoie pour controler le bit ACK
    if(ACKstatus)
    {
        return  1;
    }
    return 0;
}



uint8_t beginTransmission(uint8_t adressI2C)                                        //Retourne 1 pour NACK et 0 pour ACK
{
    StartCom();
    SendAdress(adressI2C,0);
    return StatusACK;                                                     
}




uint8_t beginReception(uint8_t adressI2C, uint8_t *DataToRead,uint8_t nbPaquet)     //Retourne 1 pour NACK et 0 pour ACK
{
    StartCom();
    SendAdress(adressI2C,1);
    if(StatusACK);
    return 1;
    
        ReceptionData(DataToRead);
        nbPaquet --;
        while(nbPaquet > 0)
        {
            Send_ACK();
            ReceptionData(DataToRead);
            nbPaquet --;
        }

        Send_NACK();
        StopCom();
        return 0; 
    }


/*------------------------Bloc fonctionnels (non utilisables)------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void I2C_wait_for_idle()
{
    while(I2C1CON & 0x1F);
    while(TX_EnCours);
}



void Send_ACK()
{
    I2C_wait_for_idle();
    SetACK_NACK = 0;
    EnableACK = 1;
    while(EnableACK);
}



void Send_NACK()
{
    I2C_wait_for_idle();
    SetACK_NACK = 1;
    EnableACK = 1;
    while(EnableACK);
}



void SendAdress(uint8_t adress, uint8_t RW)           //Fonction d'envoie d'adresse
{
    StatusACK = SendData((((adress << 1)| RW)));
}



void StartCom()
{
    I2C_wait_for_idle();
    SignalStart = 1;
    while (SignalStart);
}



void StopCom()
{
    I2C_wait_for_idle();
    SignalStop = 1;
}



void restart()
{
    I2C_wait_for_idle();
    SignalRestart = 1;
    while(SignalRestart);
}



void ReceptionData(uint8_t *DataRead)                     
{
    ReceptionEnable = 1;
    while(ReceptionEnable);
    while(BufferRXstatus);
    *DataRead = BufferReception;
}


void init_I2C(I2C_Com **Ptr) {
    // Allouer de la m�moire pour la structure
    *Ptr = malloc(sizeof(I2C_Com));
    if (*Ptr == NULL) {
        // G�rer l'�chec de l'allocation m�moire
        // Peut-�tre une sortie anticip�e de la fonction avec une erreur
        return;
    }

    // Assigner les pointeurs de fonction aux fonctions externes
    (*Ptr)->SendData = SendData;
    (*Ptr)->SendAdress = SendAdress;
    (*Ptr)->ReceptionData = ReceptionData;
    (*Ptr)->beginReception = beginReception;
    (*Ptr)->beginTransmission = beginTransmission;
    (*Ptr)->I2C_wait_for_idle = I2C_wait_for_idle;
    (*Ptr)->Send_NACK = Send_NACK;
    (*Ptr)->Send_ACK = Send_ACK;
    (*Ptr)->restart = restart;
    (*Ptr)->StopCom = StopCom;
    (*Ptr)->StartCom = StartCom;
}