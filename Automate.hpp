
/*
 *
 *
 */



#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "AutomateState.h"
#include "AutomateStateConcrete.h"





class Automate {


private:
  // Liste des états de la machine
  AutomateState* currentState_ ;
  State1 state1_ ;
  State2 state2_ ;
  State3 state3_ ;

  // Adresses des I/O de la carte utilisées
  int green_ ;
  int yellow_ ;
  int red_ ;
  


public:

//===============================================================
//------------------------ Constructors -------------------------
//===============================================================
  Automate() ;

/*===============================================================
 *------------------------- Destructor --------------------------
 *===============================================================*/

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

};






#endif
