#ifndef __FEFY6900__H__                                     //gcc -shared -o FEFY6900.dll FEFY6900.c
#define __FEFY6900__H__                                     //gcc Driver_FEFY6900.c FEFY6900.c -o fefy6900
                                                            //.\fefy6900
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

typedef enum Boolean{
    false,
    true
}Boolean;

typedef struct GBF_Channel{
    char WaveForm;
    char Amplitude[5];
    char Frequence[19];
    char Offset[5];
    char Phase[5];
    char DutyCycle[5];
    Boolean Channel_ON_Off;
    const char Output_Channel;
}GBF_Channel;

#define CHANNEL_A 'M'
#define CHANNEL_B 'F'

#define CHANNEL_OFF '0'
#define CHANNEL_ON '1'

#define NO_ERREUR 0
#define ERREUR -1

#define MAX_SIZE_TAB 256
#define END_CHAR_COM 0x0a

#define SIZE_REPONSE 20

#define SINE 0
#define SQUARE 1
#define RECTANGLE 2
#define TRAPEZOID_1 3
#define CMOS 4
#define DC 5
#define TRIANGLE 6
#define RAMP 7
#define NEG_RAMP 8
#define STAIR_TRIANGLE 9
#define STAI_RSTEP 10
#define NEG_STAIR 11
#define POS_EXPONENT 12
#define NEG_EXPONENT 13
#define P_FALL_EXP 14
#define N_FALL_EXP 15
#define POS_LOGARIT 16
#define NEG_LOGARIT 17
#define P_FALL_LOG 18
#define N_FALL_LOG 19
#define P_FULL_WAV 20
#define N_FULL_WAV 21
#define P_HALF_WAV 22
#define N_HALF_WAV 23
#define LORENTZ_PU 24
#define MULTITONE 25
#define RANDOM_NOISE 26
#define ECG 27
#define TRAPEZOID_2 28
#define SINC_PULSE 29
#define IMPULSE_1 30
#define AWGN 31
#define AM 32
#define FM 33
#define CHIRP 34
#define IMPULSE_2 35

extern char response[SIZE_REPONSE];
extern DWORD bytesWritten, bytesRead;
extern DCB dcbSerialParams;
extern COMMTIMEOUTS timeouts;
extern HANDLE hSerial;
extern char LastPortCom[5];
extern Boolean ctrl_COM;

extern GBF_Channel Channel1;
extern GBF_Channel Channel2;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved);

__declspec(dllexport) void CloseComm();
__declspec(dllexport) int SetFrequence(GBF_Channel *Channel);
__declspec(dllexport) int init_Virtual_SerialCom(char PortCOM[5]);
__declspec(dllexport) int SetChannel(GBF_Channel *Channel);
__declspec(dllexport) int SetWaveForm(GBF_Channel *Channel);
__declspec(dllexport) int SetAmplitude(GBF_Channel *Channel);
__declspec(dllexport) int SetOffset(GBF_Channel *Channel);
__declspec(dllexport) int SetDutyCycle(GBF_Channel *Channel);
__declspec(dllexport) int SetPhaseValue(GBF_Channel *Channel);
__declspec(dllexport) int Set_ON_OFF_Channel(GBF_Channel *Channel);
__declspec(dllexport) int SetTrigger_Channel1(GBF_Channel *Channel);
__declspec(dllexport) GBF_Channel GetStructChannel(GBF_Channel *Channel);




void Traitement_commande(char *amp, char commande [10]);
void ReplaceChar(char *car, char Car_to_replace, char new_car);
void Min_to_Maj(char *command);
void Check_reponse_GBF();
void Inverser_valeur(char *a, char *b);
void Inverser_tableau(char *a, char indexA, char indexB);
void Conversion_float_to_String(float Nb_float, char *string);

#endif