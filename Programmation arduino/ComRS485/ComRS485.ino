/* TP Programmation Arduino - ETD
Communication réseau RS485 via USART de l'ATmega328P
Octobre 2020*/

/* PARTIE SERVEUR */

#define TEST_LED_PIN 13
#define RS485_RW_PIN 11                          //définition de la broche de contrôle lecture/écriture du Max485
#define VERSION 1.0
#define SERIAL_SPEED 9600                       //Vitesse de communication de l'USART
#define TIMEOUT_COM 200                         //durée du Timeout défini dans le protocole de communication (détéction de transmissions incompletes)
#define CYCLE_TIME 2000                         // temps de cadencement en milisecondes d'execution de cycle
#define CYCLE_TIME2 500

//définition des caractères de contrôle du protocole de communication:
//forme de la trame de communication
//@[adresseEmetteur]:[adresseRecepteur]:[fonction]:[parametre];
//adresseEmetteur int de 1 à 99
//adresseDestinataire: int de 0 à 99, avec 0 réservé pour l'envoi de message à tous.
//Les fonctions doivent être définies de façon commune.
//exemples d'adresses: 10 -> serveur / 1 -> panneau solaire / 2 -> station météo / 3 -> horodateur / 4-> afficheur LCD
const int SOLAR_STATION = 1;
const int METEO_STATION = 2;
const int DATE_TIME = 3;
const int LCD_DISPLAY = 4;
const int SERVER = 10;



String datasDateHeure = "";           //init des données à envoyer à l'affichage et au moteur.
String datasMeteo = "";
String NO_REPLY = "Pas de réponse";




//exemples de fonctions: 1 -> getTime / 2 -> getDate / 3 -> getTemperature / 4 -> getHumidity / 5-> getEnlightment / 6-> displayDate / 7-> displayTime / 8 -> displayTemp / 9-> display Humidity / 10 -> display Enlightment / 11->moveHMotor / 12-> moveVMotor
const int GETTIME = 1;
const int GETMETEO = 2;
const int DSPTIME = 3;
const int DSPMETEO = 4;
const int MVHMOT = 5;
const int MVVMOT = 6;
const int DSPMSG = 7;
const int TSTLED = 8;

const char SYNC_CHAR = '@';
const char END_CHAR = ';';
const char SEP_CHAR = ':';
int monAdresse = SERVER;

boolean serialWriteInProgress=false;                  //Flag permettant de gérer le bit de controle de lecture écriture RS485
String bufferRx = "";                         //Définition d'un buffer logiciel de reception, il y sera stocké le contenu des données récupérées sur le Buffer rx de l'USART.

long timeOutCom;                            //contient la derniere valeur temporelle renovoyée par millis()
long lastTimeCycle = 0;                         //dernier Timestamp d'éxecution du cycle long.
long lastTimeCycle2 = 0;

//prototypes de fonctions prédéclarées 
void traitementRx();
void sendMsg(String destinataire,String func, String data);
void serialWrite(String data);
void sendMsg(int destinataire,int func, String data);
void serialEvent();


void setup()                              //fonction d'initialisation de l'ARduino, exécutée une fois au démarrage.
{
  Serial.begin(SERIAL_SPEED);                     //initialisation de l'USART
  pinMode(RS485_RW_PIN,OUTPUT);                     //définition de la broche de controle de lecture/ecriture du max485 en sortie.
  pinMode(TEST_LED_PIN,OUTPUT);                     //définition de la broche de la led de test de présence
  digitalWrite(RS485_RW_PIN,0);                     //initialisation du bus rs485 en "écoute".
}

void loop()                               //boucle inifinie Arduino 
{
  //Test Buffer RX>0
  if (bufferRx.length() > 0) {                      //Teste si le buffer "logiciel" contient au moins un caractère
    traitementRx();                           //appel de la fonction de traitement du contenu buffer
  }

  //Process LEnt
  long millisTime=millis();                       //Déclaration d'une variable temporaire pour enregistrer le timestamp courant.
  if ((millisTime-CYCLE_TIME)>lastTimeCycle){               //TEste si il est temps d'éxécuter le processus lent
    lastTimeCycle=millisTime;                       //stocke le timestamp de derniere execution du process lent.


    

    
  }
 
  //Process rapide

  //Test fin envoi UART TX
  if (serialWriteInProgress){                     //Test du flag d'envoi en cours. déclenché par la fonction d'envoi sur le réseau
    if  (UCSR0A & (1<<TXC0)){                     //Test du bit TXC0 du registre UCSR0A correspondant au flag buffer d'emission vide
      digitalWrite(RS485_RW_PIN,0);                   //on passe le bus rs485 en lecture²
      serialWriteInProgress=false;                    //et on baisse le flag d'emission en cours, pour ne plus entrer dans cette fonction jusqu'à la prochaine émission
    }
  }
}

void serialEvent() {                          //Fonction déclenchée par l'arrivée de données sur le buffer RX de l'USART.
  char incomingByte;                          
  while (Serial.available()) {
    incomingByte = Serial.read();
    bufferRx += incomingByte;
    //bufferRx+= Serial.read();               //Cette ligne peut être directement utilisée à la place d'utiliser une variable temporaire
  }
  timeOutCom = millis();                      //Enregistrement du timestamp du dernier caractere reçu
}

void traitementRx() {                         //Fonction de traitement du contenu du buffer logiciel
  
  int fonction;                            //Déclaration des variables nécessaires au décodage
  String parametre;                           //LE but de cette fonction est de déterminer si la trame est correcte
  int idEmet;                              //Si elle est incomplete, elle sera traitée plus tard jusqu'à ce qu'elle soit complète
  int idDest;                              //Sauf si le dernier caractere est arrivé sur l'USART depuis un temps supérieur au temps TimeOut
  String trame;
  int indexSep;
  int indexStart = 0;
  int indexEnd = 0;
  
  if ((millis() - timeOutCom) > TIMEOUT_COM) {                  //Test du timeOut (comparaison timestamp actuel et timeStamp dernier char reçu)
    bufferRx = "";
  }
  
  indexStart = bufferRx.indexOf(SYNC_CHAR); //caractere de debut
  if (indexStart > -1) {
    indexEnd = bufferRx.indexOf(END_CHAR,indexStart);           //caractere de fin, si absent du buffer on ne traite pas
    if (indexEnd > -1) {                                        // on &a la fin et le debut
      trame = bufferRx.substring(indexStart, indexEnd);
      bufferRx.remove(indexStart, indexEnd - indexStart + 1);
      trame.remove(0,1); // on supprime l'arobas
      
      //id emetteur
      indexSep=trame.indexOf(SEP_CHAR);
      idEmet=trame.substring(0,indexSep).toInt();
      trame.remove(0,indexSep+1);
      
      //id du destinataire
      indexSep=trame.indexOf(SEP_CHAR);
      idDest=trame.substring(0,indexSep).toInt();
      trame.remove(0,indexSep+1);
      
      //fonction
      indexSep=trame.indexOf(SEP_CHAR);
      fonction=trame.substring(0,indexSep).toInt();
      trame.remove(0,indexSep+1);
      
      //paramatre
      indexSep=trame.indexOf(SEP_CHAR);
      parametre=trame.substring(0,indexSep);
      trame.remove(0,indexSep+1);

      if (idDest==monAdresse){
        switch(fonction){
          case GETTIME :
            datasDateHeure=parametre;
            sendMsg(LCD_DISPLAY, DSPTIME, parametre);
            sendMsg(SOLAR_STATION,MVHMOT,calcAngleH(parametre));
            sendMsg(SOLAR_STATION,MVVMOT,calcAngleV(parametre));
          break;
          case GETMETEO :
            datasMeteo= parametre;
            sendMsg(LCD_DISPLAY, DSPMETEO, parametre);
          break;
          case DSPMSG :
            sendMsg(LCD_DISPLAY, DSPMSG, "instruction >"+String(fonction) +"< non traitée");
          break;
          case TSTLED :
            digitalWrite(TEST_LED_PIN,HIGH);
            delay(100);
            digitalWrite(TEST_LED_PIN,LOW);
          break;
          default :
            sendMsg(LCD_DISPLAY, DSPMSG, "instruction >"+String(fonction) +"< inconnue");
          break;   
        }
      }
    }
  }
}

void sendMsg(int destinataire,int func, String data) {
  serialWrite("@"+String(monAdresse) +":"+String(destinataire)+":"  + String(func) + ":" + data + ";");
}

void serialWrite(String data){
  digitalWrite(RS485_RW_PIN,1); //on passe le bus en écriture
  Serial.println(data); 
  serialWriteInProgress=true;
}

String calcAngleH(String dateString){
  //renvoie une valeur d'angle en fonction de l'heure et de la date
  return "45.0";
}

String calcAngleV(String dateString){
  //renvoie une valeur d'angle en fonction de l'heure et de la date
  return "45.0";
}
