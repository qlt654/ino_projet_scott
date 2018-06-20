#include "AutomateStateConcrete.h"
#include "Automate.h"
#include "Arduino.h"

//#include <iostream>
using namespace std;


//==============================================================
//=                           STATE_1                          =
//==============================================================
State1::State1() {}
State1::~State1() {}


// ############### ENTRY / DO / EXIT ###############
void State1::actionEntry() {
  digitalWrite(automate_->getGreen() , HIGH) ;
}

void State1::actionExit() {
  digitalWrite(automate_->getGreen() , LOW) ;
//cout << "Sortie état 1" << endl;
}

void State1::transition1() {
  automate_->setCurrentState(automate_->getState2());
//cout << "Transition 1 depuis 1" << endl;
}


//==============================================================
//=                           STATE_2                          =
//==============================================================
State2::State2() {}
State2::~State2() {}


// ############### ENTRY / DO / EXIT ###############
void State2::actionEntry() {
  digitalWrite(automate_->getYellow() , HIGH) ;
}

void State2::actionExit() {
  digitalWrite(automate_->getYellow() , LOW) ;
}

void State2::transition1() {
  automate_->setCurrentState(automate_->getState3());
//cout << "Transition 1 depuis 2" << endl;
}


//==============================================================
//=                           STATE_3                          =
//==============================================================
State3::State3() {}
State3::~State3() {}


// ############### ENTRY / DO / EXIT ###############
void State3::actionEntry() {
  digitalWrite(automate_->getRed() , HIGH) ;
}

void State3::actionExit() {
   digitalWrite(automate_->getRed() , LOW) ;
}

void State3::transition1() {
  automate_->setCurrentState(automate_->getState1());
//cout << "Transition 1 depuis 3" << endl;
}
