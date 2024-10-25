

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||/PROJET_DASH_BOARD/||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

 
 #include <genieArduino.h>
#include <Arduino.h>
#include <Dash_board.h>
#include <Wire.h>
#include <math.h>

#define pressurePin_1 A0
#define pressurePin_2 A1
int tempPin = A2;
#define tachyPin A3
#define cmdRel_1 1
#define cmdRel_2 2
#define oxygenPin A4
#define ledPressHuileMin 5
#define DELAY1 200

uint16_t ValSuralimentation;
uint16_t ValPressionHuile;
uint16_t ValTachymetre;
uint16_t ValRatioAirEss;
uint16_t ValTemperature;
float pressRefSural = 1.5;
float pressRefHuil = 3.5;
unsigned long waitPeriod = 0;

Genie genie;
temperature Temp(tempPin);
suralimentation suralim(pressurePin_1);
huile CapteurHuile(pressurePin_2, ledPressHuileMin);
tachy tachymetre(tachyPin);
relais Relais(cmdRel_1, cmdRel_2);
airFuel airFuel(oxygenPin);

void myGenieEventHandler(void) {
  genieFrame Event;
  genie.DequeueEvent(&Event);

  if (genie.EventIs(&Event, GENIE_REPORT_EVENT, GENIE_OBJ_ANGULAR_METER, 0)) {
    ValTemperature = genie.GetEventData(&Event);
    genie.WriteObject(GENIE_OBJ_ANGULAR_METER, 0, ValTemperature);
    waitPeriod = millis() + 500;
  }

  if (genie.EventIs(&Event, GENIE_REPORT_EVENT, GENIE_OBJ_ANGULAR_METER, 1)) {
    ValSuralimentation = genie.GetEventData(&Event);
    genie.WriteObject(GENIE_OBJ_ANGULAR_METER, 1, ValSuralimentation);

    if (ValSuralimentation > pressRefSural) {
      genie.WriteObject(GENIE_OBJ_USER_LED, 1, HIGH);
    }
    waitPeriod = millis() + 100;
  }

  if (genie.EventIs(&Event, GENIE_REPORT_EVENT, GENIE_OBJ_COOL_GAUGE, 0)) {
    ValTachymetre = genie.GetEventData(&Event);
    genie.WriteObject(GENIE_OBJ_COOL_GAUGE, 0, ValTachymetre);
    waitPeriod = millis() + 50;
  }

  if (genie.EventIs(&Event, GENIE_REPORT_EVENT, GENIE_OBJ_ANGULAR_METER, 3)) {
    ValPressionHuile = genie.GetEventData(&Event);
    genie.WriteObject(GENIE_OBJ_ANGULAR_METER, 3, ValPressionHuile);

    if (ValPressionHuile <= pressRefHuil) {
      genie.WriteObject(GENIE_OBJ_USER_LED, 0, HIGH);
    }
    waitPeriod = millis() + 200;
  }

  if (genie.EventIs(&Event, GENIE_REPORT_EVENT, GENIE_OBJ_LED_DIGITS, 2)) {
    ValRatioAirEss = genie.GetEventData(&Event);
    genie.WriteObject(GENIE_OBJ_LED_DIGITS, 2, ValRatioAirEss);
    waitPeriod = millis() + 300;
  }
}

void setup() {
  Serial.begin(115200);
  genie.Begin(Serial);
  while (!Serial);
  delay(3500);

  Temp.temp_init();
  suralim.pressionSural_init();
  CapteurHuile.pressionHuile_init();
  tachymetre.tachy_init();
  Relais.relais_init();
  airFuel.airFuel_init();

  genie.AttachEventHandler(myGenieEventHandler);
}

void loop() {
  if (millis() >= waitPeriod) {
    ValTemperature = analogRead(tempPin);     //Temp.traitement_temp();
    Serial.write(ValTemperature);
    genie.WriteObject(GENIE_OBJ_ANGULAR_METER, 0, ValTemperature);
    waitPeriod = millis() + 2000;
  }

  ValSuralimentation = suralim.traitement_pressionSural();
  Serial.println(ValSuralimentation);
  genie.WriteObject(GENIE_OBJ_ANGULAR_METER, 1, ValSuralimentation);

  if (ValSuralimentation > pressRefSural) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, HIGH);
  }
  waitPeriod = millis() + 100;

  ValTachymetre = tachymetre.traitement_TrsMin();
  Serial.println(ValTachymetre);
  genie.WriteObject(GENIE_OBJ_COOL_GAUGE, 0, ValTachymetre);
  waitPeriod = millis() + 50;

  ValPressionHuile = CapteurHuile.traitement_huile();
  Serial.println(ValPressionHuile);
  genie.WriteObject(GENIE_OBJ_ANGULAR_METER, 3, ValPressionHuile);

  if (ValPressionHuile <= pressRefHuil) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 0, HIGH);
  }
  waitPeriod = millis() + 100;

  ValRatioAirEss = airFuel.traitement_airFuel();
  Serial.println(ValRatioAirEss);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 2, ValRatioAirEss);
  waitPeriod = millis() + 100;
}
////////////////////////////////////////////////////////////////////////////DEBUG/////////////////////////////////////////////////////////////////////////
  
  // debug(ValSuralimentation,ValPressionHuile,ValTachymetre,ValTemperature,ValRatioAirEss);
  // }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////