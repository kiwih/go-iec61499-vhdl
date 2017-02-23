// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block MaskedSwitch
#ifndef MASKEDSWITCH_H_
#define MASKEDSWITCH_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum MaskedSwitch_states { STATE_MaskedSwitch_Start, STATE_MaskedSwitch_Update };


//this block had no input events


union MaskedSwitchOutputEvents {
	struct {
		UDINT SwitchChanged;
	} event;
	
};


typedef struct {
    //input events
	

    //output events
	union MaskedSwitchOutputEvents outputEvents;

    //input vars
	BYTE SwitchMask;
    
    //output vars
	BOOL SwitchOn;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum MaskedSwitch_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} MaskedSwitch_t;

//all FBs get a preinit function
int MaskedSwitch_preinit(MaskedSwitch_t _SPM *me);

//all FBs get an init function
int MaskedSwitch_init(MaskedSwitch_t _SPM *me);

//all FBs get a run function
void MaskedSwitch_run(MaskedSwitch_t _SPM *me);

//basic FBs have a number of algorithm functions

void MaskedSwitch_SwitchesService(MaskedSwitch_t _SPM *me);


#endif
