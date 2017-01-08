// This file has been automatically generated by goFB and should not be edited by hand
// Transpiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block Producer
#ifndef PRODUCER_H_
#define PRODUCER_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum Producer_states { STATE_Producer_Start, STATE_Producer_increment, STATE_Producer_Tx };


union ProducerInputEvents {
	struct {
		UDINT TxStatusChanged : 1;
	} event;
	UDINT events[1];
};


union ProducerOutputEvents {
	struct {
		UDINT DataPresent : 1;
	} event;
	UDINT events[1];
};


struct Producer {
    //input events
	union ProducerInputEvents inputEvents;

    //output events
	union ProducerOutputEvents outputEvents;

    //input vars
	BOOL TxBusy;
    
    //output vars
	INT Data;
    
	//any internal vars (BFBs only)
    INT Count;
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum Producer_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
};

//all FBs get an init function
void Producer_init(struct Producer *me);

//all FBs get a run function
void Producer_run(struct Producer *me);


//basic FBs have a number of algorithm functions

void Producer_update_count(struct Producer *me);


#endif
