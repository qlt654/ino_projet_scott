//
// MorseChar.hpp
// ino_projet_scott
//
// Created by qlt654 on 21/06/2018.
//
//

#ifndef MORSECHAR_HPP
#define MORSECHAR_HPP

#include <stdint.h>


class MorseChar {
private:
  // Nombre maximum d'atome (Ti ou Taah) que peut contenir un caractère.
  static const unsigned char MAX_NB_OF_ATOM = 6 ;
  // Durée nominale d'un "Ti"
  static const uint16_t TI_DURATION = 1000 ;
  // Durée nominale d'un "Taah"
  static const uint16_t TAAH_DURATION = 3000 ;

  // Nombre d'atome actuellement contenu dans la valeur character_
  unsigned char numberOfAtoms_ ;
  // Valeur encodée du caractère
  unsigned int character_ ;
  // Buffer contenant les temps des différents signaux pour interprétation des durées
  uint16_t buffer_[MAX_NB_OF_ATOM] ;
  // Nombre d'atomes dans le buffer
  unsigned char numberOfAtomsBuffer_ ;


public:
//===============================================================
//------------------------ Constructors -------------------------
//===============================================================
  MorseChar();
  ~MorseChar();

//===============================================================
//---------------------- Getters & Setters ----------------------
//===============================================================
  int getCharValue() const ;
  char getCharacter() const ;
  void resetCharacter() ;

//===============================================================
//--------------------------- Methods ---------------------------
//===============================================================
  void addBuffer(uint16_t howLong) ;
  char readBuffer() ;
  void addTi() ;
  void addTaah() ;
  char interpretMorseChar();

};



#endif /* MORSECHAR_HPP */
