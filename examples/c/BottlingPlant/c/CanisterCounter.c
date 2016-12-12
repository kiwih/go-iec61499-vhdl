// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the implementation of the Basic Function Block for CanisterCounter
#include "CanisterCounter.h"

enum CanisterCounter_states { STATE_Start };

void CanisterCounter_init(struct CanisterCounter *me) {
	//if there are input events, reset them
	me->inputEvents.events[0] = 0;
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars, reset them
	me->DoorSiteLaser = 0;
	me->RejectBinLaser = 0;
	me->AcceptBinLaser = 0;
	
	//if there are output vars, reset them
	me->CanisterCount = 0;
	
	//if there are internal vars, reset them
	
}

void CanisterCounter_run(struct CanisterCounter *me) {
	//current state storage
	static enum CanisterCounter_states state = STATE_Start;
	static BOOL trigger = false;

	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//now, let's advance state
	switch(state) {
	case STATE_Start :
		if(me->inputEvents.event.LasersChanged) {
			state = STATE_Start;
			trigger = true;
		};
	
	}

	//now, let's run any algorithms and emit any events that need to occur due to the trigger
	if(trigger == true) {
		switch(state) {
			case STATE_Start :
				CanisterCounter_ChangeCount(me);
				me->outputEvents.event.CanisterCountChanged = 1;
				break;
				
			
		}
	}
}

//algorithms

void CanisterCounter_ChangeCount(struct CanisterCounter *me) {
if(me->DoorSiteLaser) {
	me->CanisterCount++;
}
if(me->RejectBinLaser) {
	me->CanisterCount--;
}
if(me->AcceptBinLaser) {
	me->CanisterCount--;
}
//printf("Canister count:%i\n", me->CanisterCount);
}



