//
//  MorseChar.cpp
//  ino_projet_scott
//
//  Created by qlt654 on 21/06/2018.
//
//

#include "MorseChar.hpp"
#include "Alphabet.hpp"


//===============================================================
//------------------------ Constructors -------------------------
//===============================================================
MorseChar::MorseChar()  {
  numberOfAtom_ = 0 ;
  character_    = 0 ;
}
MorseChar::~MorseChar() {}


//===============================================================
//---------------------- Getters & Setters ----------------------
//===============================================================

int MorseChar::getCharValue() const {
  return character_ ;
}

char MorseChar::getCharacter() const {
  char character = '&' ;

  int j = 0 ;
  while (j < 57) {
   if( alpha[j].hex == character_) {
      character = alpha[j].car ;
    }
    j++ ;
  }
/* Forum adruino :
Bonjour,
Je débute actuellement sur Arduino. Je me suis lancé dans un petit projet pour
dégripper un peu mes souvenir de CPP et je souhaite en profiter pour tout de suite
prendre les bons reflexes en terme d'optimisation de la mémoire et du temps de calcul.

Je cherche à faire une fonction qui doit interpréter une valeur numérique (u_int)
et la comparer à une "base de données" afin d'y récupérer un caractère associé
un peu comme on pourrait le faire avec une table ASCII si on voulait le faire
manuellement (par exemple : 'a' = 159).

J'ai resorti deux solutions :
#1 utiliser un gros renfort de macro puis traverser la liste dans un switch/case :
#define CHAR_A 159
switch(code) {
case CHAR_A :
caractere = 'a';
break;
(...)
}

#2 définir une structure adaptée et la parcourir avec un while :
struct maStruct {char caract ; int codeCaract ; }
maStruct liste[100] {
  {'a', 159}, .....
}

while (j < 100) {
  if(code == liste[j].codeCaract) {caractere = liste[j].caract ;}
}






*/


/*
    switch (character_) {

      case CHAR_A :
        character = 'A' ;
        break ;
      case CHAR_B :
        character = 'B' ;
        break ;
      case CHAR_C :
        character = 'C' ;
        break ;
      case CHAR_D :
        character = 'D' ;
        break ;
      case CHAR_E :
        character = 'E' ;
        break ;
      case CHAR_F :
        character = 'F' ;
        break ;
      case CHAR_G :
        character = 'G' ;
        break ;
      case CHAR_H :
        character = 'H' ;
        break ;
      case CHAR_I :
        character = 'I' ;
        break ;
      case CHAR_J :
        character = 'J' ;
        break ;
      case CHAR_K :
        character = 'K' ;
        break ;
      case CHAR_L :
        character = 'L' ;
        break ;
      case CHAR_M :
        character = 'M' ;
        break ;
      case CHAR_N :
        character = 'N' ;
        break ;
      case CHAR_O :
        character = 'O' ;
        break ;
      case CHAR_P :
        character = 'P' ;
        break ;
      case CHAR_Q :
        character = 'Q' ;
        break ;
      case CHAR_R :
        character = 'R' ;
        break ;
      case CHAR_S :
        character = 'S' ;
        break ;
      case CHAR_T :
        character = 'T' ;
        break ;
      case CHAR_U :
        character = 'U' ;
        break ;
      case CHAR_V :
        character = 'V' ;
        break ;
      case CHAR_W :
        character = 'W' ;
        break ;
      case CHAR_X :
        character = 'X' ;
        break ;
      case CHAR_Y :
        character = 'Y' ;
        break ;
      case CHAR_Z :
        character = 'Z' ;
        break ;
      case CHAR_0 :
        character = '0' ;
        break ;
        default :
          character = 0 ;
          break ;
      }*/
  return character ;
}

void MorseChar::resetCharacter() {
  character_ = 0 ;
  numberOfAtom_ = 0 ;
}



//===============================================================
//--------------------------- Methods ---------------------------
//===============================================================

/*-------------------*
 * EXAMPLE :
 * word : 1011 0011
 * mask : 0110 0000
 *  &   : 0010 0000
 *  |   : 1111 0011
 *  >>  :        01
 *-------------------*/
void MorseChar::addTi() {
  switch (numberOfAtom_) {
    case 0 :
      character_ = character_ | MASK_1_TI ;
      break;
    case 1 :
      character_ = character_ | MASK_2_TI ;
      break;
    case 2 :
      character_ = character_ | MASK_3_TI ;
      break;
    case 3 :
      character_ = character_ | MASK_4_TI ;
      break;
    case 4 :
      character_ = character_ | MASK_5_TI ;
      break;
    case 5 :
      character_ = character_ | MASK_6_TI ;
      break;
    default :
      numberOfAtom_ = 6 ; // pour éviter un overflow a terme avec le ++
      break;
  }
  numberOfAtom_++ ;
}

void MorseChar::addTaah() {
  switch (numberOfAtom_) {
    case 0 :
      character_ = character_ | MASK_1_TA ;
      break;
    case 1 :
      character_ = character_ | MASK_2_TA ;
      break;
    case 2 :
      character_ = character_ | MASK_3_TA ;
      break;
    case 3 :
      character_ = character_ | MASK_4_TA ;
      break;
    case 4 :
      character_ = character_ | MASK_5_TA ;
      break;
    case 5 :
      character_ = character_ | MASK_6_TA ;
      break;
    default :
      // lever une erreur
      numberOfAtom_ = 6 ; // pour éviter un overflow a terme avec le ++
      break;
  }
  numberOfAtom_++ ;
}
