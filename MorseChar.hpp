//
// MorseChar.hpp
// ino_projet_scott
//
// Created by qlt654 on 21/06/2018.
//
//

#ifndef MORSECHAR_HPP
#define MORSECHAR_HPP


class MorseChar {
private:
unsigned char numberOfAtom_ ;
unsigned int character_ ;


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
void addTi() ;
void addTaah() ;
char interpretMorseChar();

};



#endif /* MORSECHAR_HPP */
