// This file has been automatically generated by goFB and should not be edited by hand
// Transpiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block DoorController
#ifndef DOORCONTROLLER_H_
#define DOORCONTROLLER_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum DoorController_states { STATE_DoorController_E_Stop, STATE_DoorController_Run, STATE_DoorController_Await };


union DoorControllerInputEvents {
	struct {
		UDINT ReleaseDoorOverride : 1;
		UDINT BottlingDone : 1;
		UDINT EmergencyStopChanged : 1;
	} event;
	UDINT events[1];
};


union DoorControllerOutputEvents {
	struct {
		UDINT DoorReleaseCanister : 1;
	} event;
	UDINT events[1];
};


struct DoorController {
    //input events
	union DoorControllerInputEvents inputEvents;

    //output events
	union DoorControllerOutputEvents outputEvents;

    //input vars
	BOOL EmergencyStop;
    
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum DoorController_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
};

//all FBs get an init function
int DoorController_init(struct DoorController *me);

//all FBs get a run function
void DoorController_run(struct DoorController *me);




#endif
