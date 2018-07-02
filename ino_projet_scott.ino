
#include "Automate.hpp"
#include "MorseChar.hpp"


// Valeurs des E/S utilisées
const int GREEN  =  8 ;
const int YELLOW =  9 ;
const int RED    = 10 ;
const int SWITCH =  2 ;


uint16_t baseTimer = 10 ;
Automate automate(baseTimer) ;
uint16_t howLong ;
char lettre ;

// essais
uint32_t startTime ;
uint32_t currentTime ;



uint16_t blockingRead (int input) ;

void setup() {
  // Setting the serial port communication
  Serial.begin(9600);
  Serial.println(F("Serial is initiated."));

  // Paramétrage des E/S :
  pinMode(GREEN  , OUTPUT) ;
  pinMode(YELLOW , OUTPUT) ;
  pinMode(RED    , OUTPUT) ;
  pinMode(SWITCH , INPUT ) ;

  // Envoi des ID E/S à l'automate
  automate.setGreen(GREEN);
  automate.setYellow(YELLOW) ;
  automate.setRed (RED) ;
  startTime = millis();
  Serial.println(startTime);
}

void loop() {

//  Serial.println(currentTime) ;

  howLong = blockingRead(SWITCH) ;
//  Serial.println(howLong) ;
  lettre = automate.activate(howLong, millis()) ;
  if (howLong > 10) { Serial.println(howLong);}
  if (lettre != 0) {
    Serial.println(lettre);
  }
  delay(baseTimer);
}


uint16_t blockingRead (int input) {
  uint32_t startTime = millis() ;
  while (digitalRead(SWITCH) == HIGH);
  return (millis() - startTime) ;
}
