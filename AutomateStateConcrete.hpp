/*
 *
 *
 *
 *
 */

#ifndef AUTOMATE_STATE_CONCRETE_H
#define AUTOMATE_STATE_CONCRETE_H

#include "AutomateStateAdapter.hpp"

//******************************************************************************
//                      ADDING A NEW STATE TO THE STATE MACHINE :
//
// 1. declare the new state in ConcreteState.hpp
//              class NewState : public StateDataLoaderAdapter { ... }
// 2. implement the new state in ConcreteState.cpp
//              NewState:: ....
// 3. add an attribute of type NewState in Automate.hpp
//              NewState    newstate;
// 4. set the context of newState in Automate.cpp (constructor)
//              newState.setAutomate(this);
// 5. declare and implement getter of newState in Automate.hpp and .cpp
//              AutomateState* getNewState(); (.hpp)
//              AutomateState* Automate::getNewState() {
//                  return &newState;
//              }                                (.cpp)
//******************************************************************************




//==============================================================
//=                          STATE_1                           =
//==============================================================
class State1 : public AutomateStateAdapter {
public:
  State1();
  ~State1();

  void actionEntry();
  void actionExit();
  void transition1();
};

//==============================================================
//=                          STATE_2                           =
//==============================================================
class State2 : public AutomateStateAdapter {
public:
  State2();
  ~State2();

  void actionEntry();
  void actionExit();
  void transition1();
};

//==============================================================
//=                          STATE_2                           =
//==============================================================
class State3 : public AutomateStateAdapter {
public:
  State3();
  ~State3();

  void actionEntry();
  void actionExit();
  void transition1();
};



#endif
