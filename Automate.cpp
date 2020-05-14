/*
 *
 *
 *
 *
 */

#include "Automate.hpp" ;

/*===============================================================
 *------------------------ Constructors -------------------------
 *===============================================================*/
Automate::Automate() {
  state1_.setAutomate(this) ;
  state2_.setAutomate(this) ;
  state3_.setAutomate(this) ;
//  this->setCurrentState(&state1_);
  currentState_ = &state1_ ;
}

/*===============================================================
 *------------------------- Destructor --------------------------
 *===============================================================*/
Automate::~Automate() {}

/*===============================================================
 *---------------------- Getters & Setters ----------------------
 *===============================================================*/
AutomateState* Automate::getCurrentState()  {return currentState_ ; }
AutomateState* Automate::getState1()  {return &state1_    ; }
AutomateState* Automate::getState2()  {return &state2_    ; }
AutomateState* Automate::getState3()  {return &state3_    ; }

int  Automate::getGreen()         const {return green_    ; }
void Automate::setGreen(int green)      { green_ = green  ; }

int  Automate::getYellow()        const {return yellow_   ; }
void Automate::setYellow(int yellow)    {yellow_ = yellow ; }

int  Automate::getRed()           const {return red_      ; }
void Automate::setRed(int red)          {red_ = red      ; }

void Automate::setCurrentState(AutomateState* newState) {
  currentState_->actionExit() ;
  currentState_ = newState ;
  currentState_->actionEntry() ;
}

/*===============================================================
 *--------------------------- Methods ---------------------------
 *===============================================================*/
void Automate::activateAutomate() {}

void Automate::transition(int transition) {
  if (transition == 1) {
    currentState_->transition1();
  }
//  switch (transition) {
//    case 1:
//      currentState_->transition1();
//      break;
//    }
}


/*


*/


/*
// implementer l'interface AutomateState pour avoir les transitions ?
// Nécessité de décider à quel niveau on place la gestion des E/S arduino ?
// dans le loop{} ou dans l'Automate ?
// le loop "monitor" les entrées et active de méthode de Automate pressButon1() ...
// l'appel de ces fonctions change la valeur d'un attribu
// a chaque appel on vérifie les transitions pouvant être activées

Quelle nom de lib pour utiliser du code arduino hors du .ino ?
*/
