// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block conveyor
#ifndef CONVEYOR_H_
#define CONVEYOR_H_

#include "fbtypes.h"
#include "util.h"


#include "cvode/cvode.h"
#include "nvector/nvector_serial.h"
#include "cvode/cvode_dense.h"
#include "sundials/sundials_dense.h"
#include "sundials/sundials_types.h"


//This is a BFB, so we need an enum type for the state machine
enum conveyor_states { STATE_conveyor_Start, STATE_conveyor_offE0, STATE_conveyor_off, STATE_conveyor_onE0, STATE_conveyor_on, STATE_conveyor_offE1 };


union conveyorInputEvents {
	struct {
		UDINT off;
		UDINT on;
	} event;
	
};


union conveyorOutputEvents {
	struct {
		UDINT xdchange;
	} event;
	
};


typedef struct {
    //input events
	union conveyorInputEvents inputEvents;

    //output events
	union conveyorOutputEvents outputEvents;

    //input vars
	LREAL DeltaTime;
    
    //output vars
	LREAL x;
    LREAL d;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum conveyor_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	//this block uses cvode
	void *cvode_mem;
	N_Vector ode_solution;
	realtype T0;
	realtype Tnext;
	realtype Tcurr;
	int solveInProgress;
	

	
} conveyor_t;

//all FBs get a preinit function
int conveyor_preinit(conveyor_t  *me);

//all FBs get an init function
int conveyor_init(conveyor_t  *me);

//all FBs get a run function
void conveyor_run(conveyor_t  *me);



#endif
