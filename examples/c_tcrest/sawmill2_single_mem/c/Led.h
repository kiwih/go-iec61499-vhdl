// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block Led
#ifndef LED_H_
#define LED_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum Led_states { STATE_Led_Start, STATE_Led_Run };


union LedInputEvents {
	struct {
		UDINT CommandChange;
	} event;
	
};


//this block had no output events


typedef struct {
    //input events
	union LedInputEvents inputEvents;

    //output events
	

    //input vars
	BOOL Run;
    
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum Led_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} Led_t;

//all FBs get a preinit function
int Led_preinit(Led_t  *me);

//all FBs get an init function
int Led_init(Led_t  *me);

//all FBs get a run function
void Led_run(Led_t  *me);

//basic FBs have a number of algorithm functions

void Led_LedService(Led_t  *me);


#endif
