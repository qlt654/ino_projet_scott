
#include "Automate.hpp"


const int GREEN   = 8 ;
const int YELLOW  = 9 ;
const int RED     = 10 ;
const int SWITCH  = 2 ;

Automate automate ;
int baseTime = baseTimer ;


int blockingRead (int input) ;

void setup() {
  // Setting the serial port communication
  Serial.begin(9600);
  Serial.println("Serial is initiated.");

  // Paramétrage des E/S :
  pinMode(GREEN, OUTPUT) ;
  pinMode (YELLOW, OUTPUT) ;
  pinMode(RED, OUTPUT) ;
  pinMode(SWITCH, INPUT) ;

  // Envoi des ID E/S à l'automate
  automate.setGreen(GREEN);
  automate.setYellow(YELLOW) ;
  automate.setRed (RED) ;
}

void loop() {
//  Serial.print("Valeur du bouton : ");

  // Si pression > 1sec alors on active la transition.
  if (blockingRead(SWITCH) > 100 ) {
    Serial.println("TRANSITION !");
    automate.transition(1) ;
  }
  delay(baseTimer);
}


int blockingRead (int input) {
  int i = 0 ;
  while (digitalRead(SWITCH) == HIGH) {
    i++ ;
    delay(baseTimer) ;
  }
  return i ;
}
