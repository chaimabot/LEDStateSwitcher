#include "Arduino.h"
#define LED_RED 12
#define LED_GREEN 8
#define BUTTON 13

int etatActuel = 4;

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUTTON, INPUT); 

  Serial.begin(9600);
  Serial.println("Programme démarré. État initial : 4 (Les deux LEDs éteintes)");
}

void loop() {
  static bool dernierEtatButton = HIGH;
  int bouton = digitalRead(BUTTON);
  
  if (dernierEtatButton == HIGH && bouton == LOW) {
    delay(50); 
    
    if (digitalRead(BUTTON) == LOW) { 
      switch (etatActuel) {
        case 4:
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_GREEN, LOW);
          Serial.println("État 1 : Les deux LEDs sont éteintes.");
          etatActuel = 1;
          break;
        case 1:
          digitalWrite(LED_RED, HIGH);
          digitalWrite(LED_GREEN, LOW);
          Serial.println("État 2 : LED rouge allumée, LED verte éteinte.");
          etatActuel = 2;
          break;
        case 2:
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_GREEN, HIGH); 
          Serial.println("État 3 : LED rouge éteinte, LED verte allumée.");
          etatActuel = 3;
          break;
        case 3:
          digitalWrite(LED_RED, HIGH);
          digitalWrite(LED_GREEN, HIGH);
          Serial.println("État 4 : Les deux LEDs sont allumées.");
          etatActuel = 4;
          break;
      }
    }
  }
  
  dernierEtatButton = bouton;
}
