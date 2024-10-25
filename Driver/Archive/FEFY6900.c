#include "FEFY6900.h"

char response[SIZE_REPONSE] = {0};
DWORD bytesWritten, bytesRead;
DCB dcbSerialParams = {0};
COMMTIMEOUTS timeouts = {0};
HANDLE hSerial = NULL;
char LastPortCom[5];
Boolean ctrl_COM = false;

GBF_Channel Channel1 = {
    SQUARE,                           // WaveForm;
    "6",                           // Amplitude
    "00.000.120.120.000",                           // Frequence
    "07.00",                           // Offset
    "20",                           // Phase
    "50",                           // DutyCycle
    CHANNEL_ON,                           // Channel_ON_Off;
    CHANNEL_A                           // Output_channel;   
};

GBF_Channel Channel2 = {
    SQUARE,                           // WaveForm;
    "2248",                           // Amplitude
    "25",                           // Frequence
    "2",                           // Offset
    "60",                           // Phase
    "50",                           // DutyCycle
    CHANNEL_ON,                           // Channel_ON_Off;
    CHANNEL_B                           // Output_channel;
};



/*********************************************************************************************************************************************************/
//                                                                                                                                                       //
//                                                             INITIALISATION / STOP COM ; GET struct & GESTION DLL                                                                                                                                                     //
//                                                                                                                                                       //
/*********************************************************************************************************************************************************/




__declspec(dllexport) void CloseComm()
{
    CloseHandle(hSerial);
    hSerial = NULL;
}




__declspec(dllexport) int init_Virtual_SerialCom(char PortCOM[5])
{
    strcpy(LastPortCom, PortCOM);
    switch(ctrl_COM)
    {
        case false :
            hSerial = CreateFile(
                PortCOM,                             // Nom du port
                GENERIC_READ | GENERIC_WRITE,       // Mode d'accès
                0,                                  // Partage
                NULL,                               // Sécurité
                OPEN_EXISTING,                      // Création
                0,                                  // Attributs              
                NULL                                // Modèle
            );

            // Vérifier si l'ouverture du port a échoué
            if (hSerial == INVALID_HANDLE_VALUE)                                                                    {printf("Erreur lors de l'ouverture du port COM.\n"); return ERREUR;}

            // Initialiser la structure DCB
            dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
            if (!GetCommState(hSerial, &dcbSerialParams))                                                            {printf("Erreur lors de l'obtention de l'état du port.\n"); CloseComm(); return ERREUR;}

            // Configuration du port série
            dcbSerialParams.BaudRate = CBR_115200;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;

            // Appliquer les paramètres au port série
            if (!SetCommState(hSerial, &dcbSerialParams))                                                            {printf("Erreur lors de la configuration du port série.\n"); CloseComm(); return ERREUR;}

            // Configurer les délais
            timeouts.ReadIntervalTimeout = 50;
            timeouts.ReadTotalTimeoutConstant = 50;
            timeouts.ReadTotalTimeoutMultiplier = 10;
            timeouts.WriteTotalTimeoutConstant = 50;
            timeouts.WriteTotalTimeoutMultiplier = 10;

            if (!SetCommTimeouts(hSerial, &timeouts))                                                               {printf("Erreur lors de la configuration des délais.\n"); CloseComm(); return ERREUR;}

        break;


        default:
        break;
    }

    if(!strcmp(LastPortCom, PortCOM)) 
        ctrl_COM = true;
    else
        ctrl_COM = false;


    return NO_ERREUR; // Succès
}




BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) 
    {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            // Code à exécuter lorsque la DLL est chargée dans un processus
            break;
        case DLL_THREAD_ATTACH:
            // Code à exécuter lors de la création d'un thread dans un processus
            break;
        case DLL_THREAD_DETACH:
            // Code à exécuter lors de la destruction d'un thread dans un processus
            break;
        case DLL_PROCESS_DETACH:
            CloseComm();
            // Code à exécuter lors de la fermeture du processus ou du déchargement de la DLL
            break;
    }
    return TRUE;
    }




__declspec(dllexport) GBF_Channel GetStructChannel(GBF_Channel *Channel)
{
    return *Channel;
}





/*********************************************************************************************************************************************************/
//                                                                                                                                                       //
//                                                             PILOTAGE GBF                                                                                                                                                    //
//                                                                                                                                                       //
/*********************************************************************************************************************************************************/





__declspec(dllexport) int SetChannel(GBF_Channel *Channel)
{
    if(Channel->Channel_ON_Off == CHANNEL_OFF)
    {
        Channel->Channel_ON_Off = CHANNEL_ON;
        Set_ON_OFF_Channel(Channel);
    }

    SetWaveForm(Channel);
    SetAmplitude(Channel);
    SetOffset(Channel);
    SetDutyCycle(Channel);
    SetPhaseValue(Channel);
    SetFrequence(Channel);

    
    return NO_ERREUR;   
}




__declspec(dllexport) int SetFrequence(GBF_Channel *Channel)
{
    char commande [19] = {'W' , Channel->Output_Channel , 'F' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , END_CHAR_COM, '\0'};
    int a = 3;
    for(int i = 0; i < 15; i++)
    {
        if(((Channel->Frequence[i] >= '0') && (Channel->Frequence[i] <= '9')))
            {
                commande[a] = Channel->Frequence[i];
                a++;
            }
    }

    printf("commande  a envoyer: %s \n" , commande);
    if(!WriteFile(hSerial, commande, 18, &bytesWritten, NULL))                               {printf("Erreur lors de l'envoi de la commande.\n"); CloseHandle(hSerial); return ERREUR;}
    Check_reponse_GBF(hSerial);
    
    return NO_ERREUR;    
}




__declspec(dllexport) int SetTrigger_Channel1(GBF_Channel *Channel)
{
    char commande [5] = {'W' , 'P' , 'F' , END_CHAR_COM, '\0'};

    if(!WriteFile(hSerial , commande, 9, &bytesWritten, NULL))                               {printf("Erreur lors de l'envoi de la commande.\n"); CloseComm(); return ERREUR;}
    Check_reponse_GBF(hSerial );
    
    return NO_ERREUR;      
}




__declspec(dllexport) int Set_ON_OFF_Channel(GBF_Channel *Channel)
{
    char commande [6] = {'W' , Channel->Output_Channel , 'N' , '0' , END_CHAR_COM, '\0'};

    commande[3] = Channel->Channel_ON_Off;

    if(!WriteFile(hSerial , commande, 9, &bytesWritten, NULL))                               {printf("Erreur lors de l'envoi de la commande.\n"); CloseComm(); return ERREUR;}
    Check_reponse_GBF(hSerial );
    
    return NO_ERREUR;     
}




__declspec(dllexport) int SetPhaseValue(GBF_Channel *Channel)
{
    char commande [10] = {'W' , Channel->Output_Channel , 'P' , '0' , '0', '0', '0' , '0' , END_CHAR_COM, '\0'};

    Traitement_commande(Channel->Phase, commande);

    if(!WriteFile(hSerial , commande, 9, &bytesWritten, NULL))                               {printf("Erreur lors de l'envoi de la commande.\n"); CloseComm(); return ERREUR;}
    Check_reponse_GBF(hSerial );
    
    return NO_ERREUR;    
}




__declspec(dllexport) int SetDutyCycle(GBF_Channel *Channel)
{
    char commande [10] = {'W' , Channel->Output_Channel , 'D' , '0' , '0', '0', '0' , '0' , END_CHAR_COM, '\0'};

    Traitement_commande(Channel->DutyCycle, commande);

    if(!WriteFile(hSerial , commande, 9, &bytesWritten, NULL))                               {printf("Erreur lors de l'envoi de la commande.\n"); CloseComm(); return ERREUR;}
    Check_reponse_GBF(hSerial );
    
    return NO_ERREUR;    
}





__declspec(dllexport) int SetOffset(GBF_Channel *Channel)
{
    char commande [10] = {'W' , Channel->Output_Channel , 'O' , '0' , '0', '0', '0' , '0' , END_CHAR_COM, '\0'};

    Traitement_commande(Channel->Offset, commande);

    if(!WriteFile(hSerial , commande, 9, &bytesWritten, NULL))                               {printf("Erreur lors de l'envoi de la commande.\n"); CloseComm(); return ERREUR;}
    Check_reponse_GBF(hSerial );
    
    return NO_ERREUR;    
}





__declspec(dllexport) int SetAmplitude(GBF_Channel *Channel)
{
    char commande [10] = {'W' , Channel->Output_Channel , 'A' , '0' , '0', '0', '0' , '0' , END_CHAR_COM, '\0'};

    Traitement_commande(Channel->Amplitude, commande);

    if(!WriteFile(hSerial , commande, 9, &bytesWritten, NULL))                               {printf("Erreur lors de l'envoi de la commande.\n"); CloseComm(); return ERREUR;}
    Check_reponse_GBF(hSerial );
    
    return NO_ERREUR;
}




__declspec(dllexport) int SetWaveForm(GBF_Channel *Channel)
{
    char commande [7] = {'W' , Channel->Output_Channel , 'W' , 0 , 0 , END_CHAR_COM, '\0'};
    
    commande[3] = ((Channel->WaveForm % 10) + '0'); // Récupère le dernier chiffre de Channel->WaveForm
    commande[4] = ((Channel->WaveForm / 10) + '0'); // Récupère le premier chiffre de Channel->WaveForm si Channel->WaveForm > 9
    
    if((commande[3] > '0') && (commande[4] == '0'))
        commande[4] = ' ';

    if(commande[4] > '0')
    {
        commande[4] ^= commande[3];
        commande[3] ^= commande[4];
        commande[4] ^= commande[3];
    }

    printf("commande a envoyer :  %s" , commande);

    if(!WriteFile(hSerial , commande, 6, &bytesWritten, NULL))                               {printf("Erreur lors de l'envoi de la commande.\n"); CloseComm(); return ERREUR;}
    Check_reponse_GBF(hSerial );  
    

    return NO_ERREUR;
}









/*********************************************************************************************************************************************************/
//                                                                                                                                                       //
//                                                              FONCTIONS DIVERSES                                                                                                                                                     //
//                                                                                                                                                       //
/*********************************************************************************************************************************************************/




void ReplaceChar(char *car, char Car_to_replace, char new_car)
{
    for(int i = 0; i < 255; i++)
    {
        if(car[i] == Car_to_replace)
            car[i] = new_car;
        if((car[i] == '\0') || (car[i] == '\n'))
            break;
    }
}




void Check_reponse_GBF()
{
    if(!ReadFile(hSerial, response, (SIZE_REPONSE - 1), &bytesRead, NULL))                  {printf("Erreur lors de la lecture de la réponse.\n"); CloseComm(); return;}   
   
    if(*response == END_CHAR_COM)
        printf("ACK GBF\n");
    else    
        printf("NACK GBF\n");
}




void Inverser_valeur(char *a, char *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}




void Inverser_tableau(char *a, char indexA, char indexB)
{
    a[indexA] ^= a[indexB];
    a[indexB] ^= a[indexA];
    a[indexA] ^= a[indexB];
}




void Traitement_commande(char *amp, char commande [10])
{
    char Controle_l = 3;
    char longeur_chaine_l = strlen(amp);


    if(amp[2] >= '0')
    {
        commande[3] = amp[0];
        commande[4] = amp[1];
        commande[6] = amp[2];
        commande[7] = amp[3];
    }
    else if(longeur_chaine_l == 1)
    {
        commande[3] = '0';
        commande[4] = amp[0];
        commande[6] = '0';
        commande[7] = '0';      
    }
    else
    {
        for(int i = 0; i < 5; i ++)
        {
            if((amp[i] >= '0') && (amp[i] <= '9'))
            {
                commande[Controle_l] = amp[i];
                Controle_l++;
            }
            else
            commande[Controle_l] = '0';
        }
    }
    commande[5] = '.';    

    printf("commande a envoyer :  %s" , commande);
}





void Conversion_float_to_String(float Nb_float, char *string)
{
    int partie_entiere = (int)Nb_float;
    int partie_decimal = (int)((Nb_float - partie_entiere) * 100);    

    string[0] = (partie_entiere / 10) + '0'; 
    string[1] = (partie_entiere % 10) + '0';  
    string[2] = '.';                          
    string[3] = (partie_decimal / 10) + '0';  
    string[4] = (partie_decimal % 10) + '0';  
    string[5] = '\0';                        
}





void Min_to_Maj(char *command)
{
    int i;
    for(i = 0; i <MAX_SIZE_TAB; i++)
    {
        if(command[i] < 97)
            command[i] += 32;
    }
}



