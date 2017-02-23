// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for SawmillMessageHandler
#include "SawmillMessageHandler.h"


/* SawmillMessageHandler_preinit() is required to be called to 
 * initialise an instance of SawmillMessageHandler. 
 * It sets all I/O values to zero.
 */
int SawmillMessageHandler_preinit(SawmillMessageHandler_t _SPM *me) {
	//if there are input events, reset them
	me->inputEvents.event.MessageChanged = 0;
	me->inputEvents.event.TxSuccessChanged = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.TxDataPresent = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_SawmillMessageHandler_Start;
	

	return 0;
}

/* SawmillMessageHandler_init() is required to be called to 
 * set up an instance of SawmillMessageHandler. 
 * It passes around configuration data.
 */
int SawmillMessageHandler_init(SawmillMessageHandler_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



/* SawmillMessageHandler_run() executes a single tick of an
 * instance of SawmillMessageHandler according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void SawmillMessageHandler_run(SawmillMessageHandler_t _SPM *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.TxDataPresent = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_SawmillMessageHandler_Start:
			if(true) {
				me->_state = STATE_SawmillMessageHandler_tx_done;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillMessageHandler_try_tx:
			if(me->inputEvents.event.TxSuccessChanged && ( ! me->TxSuccess)) {
				me->_state = STATE_SawmillMessageHandler_try_tx;
				me->_trigger = true;
				
			} else if(me->inputEvents.event.TxSuccessChanged && (me->TxSuccess)) {
				me->_state = STATE_SawmillMessageHandler_tx_done;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillMessageHandler_tx_done:
			if(me->inputEvents.event.MessageChanged) {
				me->_state = STATE_SawmillMessageHandler_try_tx;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_SawmillMessageHandler_Start:
			break;

		case STATE_SawmillMessageHandler_try_tx:
			SawmillMessageHandler_LoadData(me);
			me->outputEvents.event.TxDataPresent = 1;
			break;

		case STATE_SawmillMessageHandler_tx_done:
			break;

		
		}
	}

	me->_trigger = false;
}
//algorithms

void SawmillMessageHandler_LoadData(SawmillMessageHandler_t _SPM *me) {
me->TxData = me->Message;
}



