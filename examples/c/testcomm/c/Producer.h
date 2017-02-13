// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block Producer
#ifndef PRODUCER_H_
#define PRODUCER_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum Producer_states { STATE_Producer_Start, STATE_Producer_increment, STATE_Producer_Tx };


union ProducerInputEvents {
	struct {
		UDINT TxSuccessChanged : 1;
	} event;
	UDINT events[1];
};


union ProducerOutputEvents {
	struct {
		UDINT DataPresent : 1;
	} event;
	UDINT events[1];
};


typedef struct {
    //input events
	union ProducerInputEvents inputEvents;

    //output events
	union ProducerOutputEvents outputEvents;

    //input vars
	BOOL TxSuccess;
    
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
	
} Producer_t;

//all FBs get a preinit function
int Producer_preinit(Producer_t _SPM *me);

//all FBs get an init function
int Producer_init(Producer_t _SPM *me);

//all FBs get a run function
void Producer_run(Producer_t _SPM *me);

//basic FBs have a number of algorithm functions

void Producer_update_count(Producer_t _SPM *me);


#endif
