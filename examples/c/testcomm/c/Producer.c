// This file has been automatically generated by goFB and should not be edited by hand
// Transpiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for Producer
#include "Producer.h"




/* Producer_init() is required to be called to 
 * initialise an instance of Producer. 
 * It sets all I/O values to zero.
 */
int Producer_init(struct Producer *me) {
	//if there are input events, reset them
	me->inputEvents.events[0] = 0;
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	me->Count = 0;
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs only), call this same function on them
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_Producer_Start;
	

	return 0;
}



/* Producer_run() executes a single tick of an
 * instance of Producer according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void Producer_run(struct Producer *me) {
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_Producer_Start:
			if(me->TxSuccess) {
				me->_state = STATE_Producer_increment;
				me->_trigger = true;
			};
			break;
		case STATE_Producer_increment:
			if(me->TxSuccess) {
				me->_state = STATE_Producer_Tx;
				me->_trigger = true;
			};
			break;
		case STATE_Producer_Tx:
			if(true) {
				me->_state = STATE_Producer_increment;
				me->_trigger = true;
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_Producer_Start:
			break;

		case STATE_Producer_increment:
			Producer_update_count(me);
			break;

		case STATE_Producer_Tx:
			me->outputEvents.event.DataPresent = 1;
			break;

		
		}
	}

	me->_trigger = false;
}

//algorithms

void Producer_update_count(struct Producer *me) {
me->Count++;
me->Data = me->Count;
}



