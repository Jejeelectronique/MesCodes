#ifndef COMMI2C_H
#define COMMI2C_H   

#ifdef  __cplusplus
extern "C" {
#endif
    
#include <xc.h>    

#define led PORTBbits.RB15
#define ACKstatus I2C1STATbits.ACKSTAT                          // 1 = NACK, 0 = ACK
#define BufferTransmission I2C1TRN
#define BufferReception I2C1RCV
#define SignalStart I2C1CONbits.SEN                             // 1 = Lance un Start, le hardware remet le bit a 0 a la fine de l'envoie
#define SignalStop I2C1CONbits.PEN                              // 1 = Lance un Stop, le hardware remet le bit a 0 a la fine de l'envoie
#define SignalRestart I2C1CONbits.RSEN                          // 1 = Lance un Restart, le hardware remet le bit a 0 a la fine de l'envoie
#define SetACK_NACK I2C1CONbits.ACKDT                           // 1 = NACK , 0 = ACK 
#define EnableACK I2C1CONbits.ACKEN                             // 1 = Envoie un ACK en mode lecture, le hardware remet le bit à 0 à la fine de l'envoie
#define TX_EnCours I2C1STATbits.TRSTAT                          // 1 = Transmission maitre a esclave en cours (8bits + ack), 0 = Pas de transmission
#define DebordementBufferRX I2C1STATbits.I2COV                  // 1 = Débordement du buffer RX , 0 = Pas de débordement du buffer RX
#define DebordementBufferTX I2C1STATbits.IWCOL                  // 1 = Collision lors de l'écriture , 0 = Pas de collision
#define CollisionBUS I2C1STATbits.BCL                           // 1 = Collision , 0 = no collision
#define BufferTXstatus I2C1STATbits.TBF                         // 1 = Transmit in progress , 0 = Transmit complete
#define BufferRXstatus I2C1STATbits.RBF                         // 1 = Receive complete , 0 = Receive no complete
#define ReceptionEnable I2C1CONbits.RCEN                        // 1 = Lecture data on, le hardware remet le bit a�0 a�la fine de l'envoie

     
uint8_t SendData(uint8_t data);
uint8_t beginTransmission(uint8_t adressI2C);
uint8_t beginReception(uint8_t adressI2C, uint8_t *DataToRead,uint8_t nbPaquet);
void I2C_wait_for_idle();
void Send_ACK();
void Send_NACK();
void SendAdress(uint8_t adress, uint8_t RW);
void StartCom();
void StopCom();
void restart();
void ReceptionData(uint8_t *DataRead);

    
typedef struct 
{
    uint8_t (*SendData)(uint8_t data);
    void (*SendAdress)(uint8_t adress, uint8_t RW);
    void (*ReceptionData)(uint8_t *DataRead);
    uint8_t (*beginReception)(uint8_t adressI2C, uint8_t *DataToRead, uint8_t nbPaquet);
    uint8_t (*beginTransmission)(uint8_t adressI2C);
    void (*I2C_wait_for_idle)();
    void (*Send_NACK)();
    void (*Send_ACK)();
    void (*restart)();
    void (*StopCom)();
    void (*StartCom)();
} I2C_Com;

extern I2C_Com Wire;
void init_I2C(I2C_Com **Ptr);

       
#endif  /* COMMI2C_H */