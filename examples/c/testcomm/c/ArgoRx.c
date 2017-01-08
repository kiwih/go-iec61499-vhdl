// This file has been automatically generated by goFB and should not be edited by hand
// Transpiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for ArgoRx
#include "ArgoRx.h"




/* ArgoRx_init() is required to be called to 
 * initialise an instance of ArgoRx. 
 * It sets all I/O values to zero.
 */
void ArgoRx_init(struct ArgoRx *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs only), call this same function on them
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_ArgoRx_Start;
	
}



/* ArgoRx_run() executes a single tick of an
 * instance of ArgoRx according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void ArgoRx_run(struct ArgoRx *me) {
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_ArgoRx_Start:
			
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_ArgoRx_Start:
			break;

		
		}
	}

	me->_trigger = false;
}

//no algorithms were present for this function block


