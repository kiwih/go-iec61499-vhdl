// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block Switches
#ifndef SWITCHES_H_
#define SWITCHES_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum Switches_states { STATE_Switches_Start, STATE_Switches_Update };


//this block had no input events


union SwitchesOutputEvents {
	struct {
		UDINT DataChanged : 1;
	} event;
	UDINT events[1];
};


typedef struct {
    //input events
	

    //output events
	union SwitchesOutputEvents outputEvents;

    //input vars
	
    //output vars
	INT Data;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum Switches_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} Switches_t;

//all FBs get a preinit function
int Switches_preinit(Switches_t _SPM *me);

//all FBs get an init function
int Switches_init(Switches_t _SPM *me);

//all FBs get a run function
void Switches_run(Switches_t _SPM *me);

//basic FBs have a number of algorithm functions

void Switches_switches_service(Switches_t _SPM *me);


#endif
