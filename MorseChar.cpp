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
  this->resetCharacter() ;
}

MorseChar::~MorseChar() {}


//===============================================================
//---------------------- Getters & Setters ----------------------
//===============================================================

int MorseChar::getCharValue() const { return character_ ; }

char MorseChar::getCharacter() const {
  char character = '&' ;
  int j = 0 ;
  while (j < 57) {
   if( alpha[j].hex == character_) {
      character = alpha[j].car ;
      j = 57 ;
    }
    j++ ;
  }
  return character ;
}

void MorseChar::resetCharacter() {
  character_ = 0 ;
  numberOfAtoms_ = 0 ;
  numberOfAtomsBuffer_ = 0 ;
  for (int i = 0 ; i < MAX_NB_OF_ATOM ; i ++) {
    buffer_[i] = 0 ;
  }
}



//===============================================================
//--------------------------- Methods ---------------------------
//===============================================================

void MorseChar::addBuffer(uint16_t howLong) {
  buffer_[numberOfAtoms_] = howLong ;
  numberOfAtomsBuffer_ ++ ;
}

char MorseChar::readBuffer() {
  char result = 0 ;
  for (int i = 0 ; i < numberOfAtomsBuffer_ ; i ++) {
    if (buffer_[i] <= 1.5 * TI_DURATION) {
      this->addTi();
    } else if (buffer_[i] > TI_DURATION && buffer_[i] < 1.5 * TAAH_DURATION) {
      this->addTaah();
    }
  }
  result = this->getCharacter() ;
  this->resetCharacter();
  return result ;
}


/*-------------------*
 * EXAMPLE :
 * word : 1011 0011
 * mask : 0110 0000
 *  &   : 0010 0000
 *  |   : 1111 0011
 *  >>  :        01
 *-------------------*/
void MorseChar::addTi() {
  switch (numberOfAtoms_) {
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
      numberOfAtoms_ = 6 ; // pour éviter un overflow a terme avec le ++
      break;
  }
  numberOfAtoms_ ++ ;
}

void MorseChar::addTaah() {
  switch (numberOfAtoms_) {
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
      numberOfAtoms_ = 6 ; // pour éviter un overflow a terme avec le ++
      break;
  }
  numberOfAtoms_ ++ ;
}
