/*

Mijn eerst programma zonder om rond te kijken wat moet gebeuren.
die doet en nog werkt ook hehehehehehehe

Word geschrijven voor de ChipKit UNO32

Fading V 1.0.1

0.1 
<-> 
Als bedoelling om de LCD ook er bij te zetten.

Auther Paul M Tas
Aka PA1TAS
11-09-2014 Bij Interact Contour
16-09-2014 (0.1) "
18-09-2014 (0.2) " adding more led's and ldr's
22-09-2014 (0.2) " cleaning up
23-09-2014 (0.2) " Heb een test met hardware en een serial monitor en het werkt :) 
*/

#include <stdio.h>
#include <LiquidCrystal.h>

// pin numers lcd (2,3,4,5,11,12) = 
//            led (6,9,10,13) =
//    power relay (7) =
//         switch (8) =
//          relay (28,29,30,31) =
//            LRD (A0,A1,A2,A3) =
//      power led (32) =

// Power pins
int Power_LED = 32;                // power led voor aan en uit
int RELAY_Power = 7;               // De relay om de heel boel aan te doen
int PowerSwitch_1 = 8;             // De schaakelaar om de spanning aan te doen

// LDR Led pins
int LED_1 = 6;                     // led voor ldr_1
int LED_2 = 9;                     // led voor ldr_2
int LED_3 = 10;                    // led voor ldr_3
int LED_4 = 13;                    // led voor ldr_4

// LDR pins
int LDR_1 = A0;                    // de LDR om te zien of de licht aan de linker kant is
int LDR_2 = A1;                    // de LDR om te zien of de licht aan de rechter kant is
int LDR_3 = A2;                    // de LDR om te zien of de licht aan de boven kant is
int LDR_4 = A3;                    // de LDR om te zien of de licht aan de onder kant is

// Relay pins
int RELAY_2 = 28;                  // De relay om de motor naar rechts te gaan
int RELAY_3 = 29;                  // De relay om de motor naar lings te gaan
int RELAY_4 = 30;                  // De relay om de motor naar boven te gaan
int RELAY_5 = 31;                  // De relay om de motor naar onder te gaan

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Sensor Settings for LDR's
int SensorMax = 1023;              // analoog max sensor value
int SensorMin = 0;                 // analoog min sensor value
int SensorValue_LDR_1 = 0;         // set de sensor eerst op 0
int SensorValue_LDR_2 = 0;         // set de sensor eerst op 0
int SensorValue_LDR_3 = 0;         // set de sensor eerst op 0
int SensorValue_LDR_4 = 0;         // set de sensor eerst op 0
int SensoroutputValue_LDR_1 = 0;   // set de sensor eerst op 0
int SensoroutputValue_LDR_2 = 0;   // set de sensor eerst op 0
int SensoroutputValue_LDR_3 = 0;   // set de sensor eerst op 0
int SensoroutputValue_LDR_4 = 0;   // set de sensor eerst op 0

void setup()
{

  Serial.begin(9600);              // set de serial poort naar 9600
  lcd.begin(16,2);                 // set de lcd scherm als 16x2
  lcd.clear();

  Serial.print("Hi there this is the LDR #\n"); // net wat het zeggen
  lcd.setCursor(0, 0);             // Set de Cursor to 0,0 op de Display
  pinMode(Power_LED, OUTPUT);      // Led voor Power als OUTPUT

  pinMode(LED_1, OUTPUT);          // Led_1 voor LDR als OUTPUT
  pinMode(LED_2, OUTPUT);          // Led_2 voor LDR als OUTPUT
  pinMode(LED_3, OUTPUT);          // Led_3 voor LDR als OUTPUT
  pinMode(LED_4, OUTPUT);          // Led_4 voor LDR als OUTPUT

  pinMode(LDR_1, INPUT);           // LDR_1 als INPUT
  pinMode(LDR_2, INPUT);           // LDR_2 als INPUT
  pinMode(LDR_3, INPUT);           // LDR_3 als INPUT
  pinMode(LDR_4, INPUT);           // LDR_4 als INPUT  

  pinMode(RELAY_Power, OUTPUT);    // Relay als OUTPUT
  pinMode(RELAY_2, OUTPUT);        // Relay als OUTPUT
  pinMode(RELAY_3, OUTPUT);        // Relay als OUTPUT
  pinMode(RELAY_4, OUTPUT);        // Relay als OUTPUT
  pinMode(RELAY_5, OUTPUT);        // Relay als OUTPUT


  pinMode(PowerSwitch_1, INPUT);   // Switch als INPUT
  pinMode(Power_LED, OUTPUT);      // Power LED als OUTPUT
  
  if ((PowerSwitch_1) == HIGH)     // als de switch aan is dan HIGH
    analogWrite(Power_LED, HIGH);  // Set PowerLED naar Aan
    else
    analogWrite(Power_LED, LOW);   // Set PowerLED naar Af als switch LOW is
}

void loop()
{

   LDR_1_value();
   LDR_2_value();
   LDR_3_value();
   LDR_4_value();

}

void LDR_1_value()
{
  SensorValue_LDR_1 = analogRead(LDR_1);    // Lees LDR_1
  SensoroutputValue_LDR_1 = map(SensorValue_LDR_1, SensorMin, SensorMax, 0, 255);
  // Set SensorValue tussen 0 en 255
  analogWrite(LED_1, SensoroutputValue_LDR_1);    // Set de LED van de LDR naar de waarden van SensorValue

  Serial.print("Sensor LDR 1 =  ");
  Serial.print(SensoroutputValue_LDR_1);  // Print de Value van LDR_1
  Serial.print("\t");
  lcd.setCursor(0, 1);                      // set de Cursor op de onderste lijn
  lcd.print(SensorValue_LDR_1);             // Dispay de SensorValue op de onderste rij 
  delay(2);                               // Wacht 50 milli Sec zodat het niet te snel gaat
}

void LDR_2_value()
{
  SensorValue_LDR_2 = analogRead(LDR_2);    // Lees LDR_1
  SensoroutputValue_LDR_2 = map(SensorValue_LDR_2, SensorMin, SensorMax, 0, 255);
  // Set SensorValue tussen 0 en 255
  analogWrite(LED_2, SensoroutputValue_LDR_2);    // Set de LED van de LDR naar de waarden van SensorValue

  Serial.print("Sensor LDR 2 =  ");
  Serial.print(SensoroutputValue_LDR_2);        // Print de Value van LDR_1
  Serial.print("\t");
  lcd.setCursor(4, 1);                      // set de Cursor op de onderste lijn
  lcd.print(SensorValue_LDR_2);             // Dispay de SensorValue op de onderste rij 
  delay(2);                               // Wacht 50 milli Sec zodat het niet te snel gaat
}

void LDR_3_value()
{
  SensorValue_LDR_3 = analogRead(LDR_3);    // Lees LDR_1
  SensoroutputValue_LDR_3 = map(SensorValue_LDR_3, SensorMin, SensorMax, 0, 255);
  // Set SensorValue tussen 0 en 255
  analogWrite(LED_3, SensoroutputValue_LDR_3);    // Set de LED van de LDR naar de waarden van SensorValue

  Serial.print("Sensor LDR 3 =  ");
  Serial.print(SensoroutputValue_LDR_3);        // Print de Value van LDR_1
  Serial.print("\t");
  lcd.setCursor(8, 1);                      // set de Cursor op de onderste lijn
  lcd.print(SensorValue_LDR_3);             // Dispay de SensorValue op de onderste rij 
  delay(2);                               // Wacht 50 milli Sec zodat het niet te snel gaat
}

void LDR_4_value()
{
  SensorValue_LDR_4 = analogRead(LDR_4);    // Lees LDR_1
  SensoroutputValue_LDR_4 = map(SensorValue_LDR_4, SensorMin, SensorMax, 0, 255);
  // Set SensorValue tussen 0 en 255
  analogWrite(LED_4, SensoroutputValue_LDR_4);    // Set de LED van de LDR naar de waarden van SensorValue

  Serial.print("Sensor LDR 4 = ");
  Serial.print(SensoroutputValue_LDR_4);  // Print de Value van LDR_1
  Serial.print("\n");
  lcd.setCursor(12, 1);                      // set de Cursor op de onderste lijn
  lcd.print(SensorValue_LDR_4);             // Dispay de SensorValue op de onderste rij 
  delay(2 );                               // Wacht 50 milli Sec zodat het niet te snel gaat
}

