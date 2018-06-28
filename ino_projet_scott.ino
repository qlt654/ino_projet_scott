
#include "Automate.hpp"
#include "MorseChar.hpp"


// Valeurs des E/S utilisées
const int GREEN  =  8 ;
const int YELLOW =  9 ;
const int RED    = 10 ;
const int SWITCH =  2 ;


unsigned short baseTimer = 10 ;
Automate automate(baseTimer) ;
unsigned short temp ;
char lettre ;


int blockingRead (int input) ;

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
}

void loop() {
//  Serial.print("Valeur du bouton : ");
  temp = blockingRead(SWITCH) ;
  lettre = automate.activate(temp) ;
if (lettre != 0) {
  Serial.println(lettre) ;
}
  delay(baseTimer);
}


int blockingRead (int input) {
  int i = 0 ;
  while (digitalRead(SWITCH) == HIGH) {
    i++ ;
//    Serial.println(i);
    delay(baseTimer) ;
  }
  return i ;
}
