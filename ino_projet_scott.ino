
#include "Automate.hpp"
#include "MorseChar.hpp"


// Valeurs des E/S utilisées
const int GREEN  =  8 ;
const int YELLOW =  9 ;
const int RED    = 10 ;
const int SWITCH =  2 ;


MorseChar morseChar ;
Automate automate ;
int baseTimer = 1 ;
int temp ;
char lettre ;


int blockingRead (int input) ;

void setup() {
  // Setting the serial port communication
  Serial.begin(9600);
  Serial.println("Serial is initiated.");

  // Paramétrage des E/S :
  pinMode(GREEN  , OUTPUT) ;
  pinMode(YELLOW , OUTPUT) ;
  pinMode(RED    , OUTPUT) ;
  pinMode(SWITCH , INPUT ) ;

  // Envoi des ID E/S à l'automate
  automate.setGreen(GREEN);
  automate.setYellow(YELLOW) ;
  automate.setRed (RED) ;
//  for (int i = 0 ; i < 10 ; i ++ ) {
//    test[i] = i ;
//  }
}

void loop() {
//  Serial.print("Valeur du bouton : ");


morseChar.addTaah();
morseChar.addTi();
morseChar.addTi();
morseChar.addTi();
lettre = morseChar.getCharacter() ;
if (lettre != 0) {
Serial.print("Valeur de char : ");
Serial.println(lettre) ;
morseChar.resetCharacter();
}
delay(1000);

/*
  temp = blockingRead(SWITCH) ;

  if (temp > 10 && temp < 150) {
//    automate.addTi() ;
    morseChar.addTi() ;
  } else if (temp >= 250 && temp < 350) {
//    automate.addTaah() ;
    morseChar.addTaah();
  }


  lettre = morseChar.getCharacter() ;
if (lettre != 0) {
  Serial.print("Valeur de char : ");
  Serial.println(lettre) ;
  morseChar.resetCharacter();
}
*/


  delay(baseTimer);
}


int blockingRead (int input) {
  int i = 0 ;
  while (digitalRead(SWITCH) == HIGH) {
    i++ ;
    Serial.println(i);
    delay(baseTimer) ;
  }
  return i ;
}
