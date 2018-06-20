
/*
 *
 *
 */



#ifndef AUTOMATE_STATE_ADAPTER_H
#define AUTOMATE_STATE_ADAPTER_H

#include "AutomateState.hpp"


class AutomateStateAdapter : public AutomateState {
protected:
    Automate* automate_ ;


public:
/*===============================================================
 *------------------------- Destructor --------------------------
 *===============================================================*/
    virtual ~AutomateStateAdapter() ;

/*===============================================================
 *---------------------- Getters & Setters ----------------------
 *===============================================================*/
    virtual void setAutomate(Automate* automate) ;

/*===============================================================
 *--------------------------- Methods ---------------------------
 *===============================================================*/
    virtual void actionEntry() ;
    virtual void actionDo() ;
    virtual void actionExit() ;

    virtual void transition1();
};






#endif
