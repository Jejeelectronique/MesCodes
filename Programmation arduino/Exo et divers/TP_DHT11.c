//code avec ecran 16x02 i2c



#include <Wire.h>
#include <Adafruit_MCP23008.h>
#include <Adafruit_LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2          // Broche de signal du capteur DHT11
#define DHTTYPE DHT11     // Type de capteur DHT

DHT dht(DHTPIN, DHTTYPE);

Adafruit_MCP23008 mcp;

// Définition des pins de l'écran LCD
#define LCD_COLS 16
#define LCD_ROWS 2
#define LCD_ADDRESS 0x27

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp & Humidite");
  
  dht.begin();
}

void loop() {
  // Lecture des valeurs de température et d'humidité
  float temperature = dht.readTemperature();
  float humidite = dht.readHumidity();

  // Affichage des valeurs sur l'écran LCD
  lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.print(" C  Hum: ");
  lcd.print(humidite);
  lcd.print(" %");

  delay(2000);  // Pause de 2 secondes entre chaque lecture
}
