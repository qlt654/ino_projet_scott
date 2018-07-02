
/*
 *
 *
 */


#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "AutomateState.hpp"
#include "AutomateStateConcrete.hpp"
#include "MorseChar.hpp"
#include <stdint.h>


class Automate {



private:
  // Liste des états de la machine
  AutomateState* currentState_ ;
  State1 state1_ ;
  State2 state2_ ;
  State3 state3_ ;

  MorseChar charBuffer_ ;

  uint16_t baseTimer_ ;
  uint16_t timeout_ ;
  uint32_t lastActivationTime_ ;

  // Adresses des I/O de la carte utilisées
  int green_ ;
  int yellow_ ;
  int red_ ;


public:

//===============================================================
//------------------------ Constructors -------------------------
//===============================================================
  explicit Automate(uint32_t initTime) ;

  virtual ~Automate() ;

/*===============================================================
 *---------------------- Getters & Setters ----------------------
 *===============================================================*/

  AutomateState* getCurrentState() ;
  AutomateState* getState1() ;
  AutomateState* getState2() ;
  AutomateState* getState3() ;

  int getGreen() const ;
  void setGreen(int green) ;
  int getYellow() const ;
  void setYellow(int yellow) ;
  int getRed() const;
  void setRed(int red) ;

  void setCurrentState(AutomateState* newState) ;



/*===============================================================
 *--------------------------- Methods ---------------------------
 *===============================================================*/
    void activateAutomate() ;
    void transition(int transition) ;
    char activate(uint16_t howLong, uint32_t currentTime) ;

};




#endif
