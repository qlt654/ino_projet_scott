/* Explications (a supprimer) :
Une méthode virtuelle suivi de "=0" est dite "pure". Elle DOIT alors nécessairement
être surchargée dans une classe fille.
Une classe possèdant une méthode virtuelle pure est de faire abstraite (elle ne 
peut pas être instanciée).

*/



/*
 * Interface AutomateState
 *
 */ 



#ifndef AUTOMATE_STATE_H 
#define AUTOMATE_STATE_H 

class Automate;

/**
 *
 *
 */
class AutomateState {
public:

/*===============================================================
 *------------------------- Destructor --------------------------
 *===============================================================*/
    virtual ~AutomateState() {};

/*===============================================================
 *---------------------- Getters & Setters ----------------------
 *===============================================================*/
    virtual void setAutomate(Automate* automate) = 0 ;

/*===============================================================
 *--------------------------- Methods ---------------------------
 *===============================================================*/
    virtual void actionEntry() = 0 ;
    virtual void actionDo()  = 0 ;
    virtual void actionExit() = 0 ;
    
    virtual void transition1() = 0 ;
};






#endif
