// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for _pizza
#include "FB__pizza.h"

//When running a composite block, note that you would call the functions in this order (and this is very important)
//_preinit(); 
//_init();
//do {
//	_syncOutputEvents();
//	_syncInputEvents();
//	_syncOutputData();
//	_syncInputData();
//	_run();
//} loop;


/* _pizza_preinit() is required to be called to 
 * initialise an instance of _pizza. 
 * It sets all I/O values to zero.
 */
int _pizza_preinit(_pizza_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(conveyorHFB_preinit(&me->conv) != 0) {
		return 1;
	}
	if(controller_preinit(&me->cont) != 0) {
		return 1;
	}
	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	
	
	return 0;
}

/* _pizza_init() is required to be called to 
 * set up an instance of _pizza. 
 * It passes around configuration data.
 */
int _pizza_init(_pizza_t  *me) {
	//pass in any parameters on this level
	me->conv.DeltaTime = 0.5;
	me->conv.M = 10;
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	me->cont.X = me->conv.X;
	me->cont.D = me->conv.D;
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(conveyorHFB_init(&me->conv) != 0) {
		return 1;
	}
	if(controller_init(&me->cont) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* _pizza_syncOutputEvents() synchronises the output events of an
 * instance of _pizza as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _pizza_syncOutputEvents(_pizza_t  *me) {
	//first, for all cfb children, call this same function
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
}

/* _pizza_syncInputEvents() synchronises the input events of an
 * instance of _pizza as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _pizza_syncInputEvents(_pizza_t  *me) {
	//first, we explicitly synchronise the children
	
	me->conv.inputEvents.event.Start = me->cont.outputEvents.event.Start; 
	
	me->conv.inputEvents.event.Off = me->cont.outputEvents.event.Off; 
	
	me->conv.inputEvents.event.On = me->cont.outputEvents.event.On; 
	
	me->conv.inputEvents.event.MChange = me->cont.outputEvents.event.Start; 
	
	me->cont.inputEvents.event.XChange = me->conv.outputEvents.event.XChange; 
	
	me->cont.inputEvents.event.DChange = me->conv.outputEvents.event.DChange; 
	

	//then, call this same function on all cfb children
	
}

/* _pizza_syncOutputData() synchronises the output data connections of an
 * instance of _pizza as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _pizza_syncOutputData(_pizza_t  *me) {
	//for all composite function block children, call this same function
	
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	
	
}

/* _pizza_syncInputData() synchronises the input data connections of an
 * instance of _pizza as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _pizza_syncInputData(_pizza_t  *me) {
	//for all basic function block children, perform their synchronisations explicitly
	
	//sync for conv (of type conveyorHFB) which is a BFB
	
	if(me->conv.inputEvents.event.Start == 1) { 
	} 
	if(me->conv.inputEvents.event.MChange == 1) { 
	} 
	
	//sync for cont (of type controller) which is a BFB
	
	if(me->cont.inputEvents.event.XChange == 1) { 
		me->cont.X = me->conv.X;
	} 
	if(me->cont.inputEvents.event.DChange == 1) { 
		me->cont.D = me->conv.D;
	} 
	
	
	//for all composite function block children, call this same function
	
	
}


/* _pizza_run() executes a single tick of an
 * instance of _pizza according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void _pizza_run(_pizza_t  *me) {
	conveyorHFB_run(&me->conv);
	controller_run(&me->cont);
	
}

