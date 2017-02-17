// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Device Function Block for _TCREST
#include "_TCREST.h"

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



/* _TCREST_preinit() is required to be called to 
 * initialise an instance of _TCREST. 
 * It sets all I/O values to zero.
 */
int _TCREST_preinit(_TCREST_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	me->rx_core.RxChanId = 1;
	me->tx_core.TxChanId = 1;
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	if(_Core0_preinit(&me->rx_core) != 0) {
		return 1;
	}
	if(_Core1_preinit(&me->tx_core) != 0) {
		return 1;
	}
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	

	return 0;
}

/* _TCREST_init() is required to be called to 
 * set up an instance of _TCREST. 
 * It passes around configuration data.
 */
int _TCREST_init(_TCREST_t  *me) {
	//pass in any parameters on this level
	
	me->rx_core.RxChanId = 1;
	me->tx_core.TxChanId = 1;
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	if(_Core0_init(&me->rx_core) != 0) {
		return 1;
	}
	if(_Core1_init(&me->tx_core) != 0) {
		return 1;
	}
	

	return 0;
}



/* _TCREST_sync[Output/Input]Events() synchronises the events of an
 * instance of _TCREST as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _TCREST_syncOutputEvents(_TCREST_t  *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for rx_core (of type _Core0) which is a Resource
	_Core0_syncOutputEvents(&me->rx_core);//sync for tx_core (of type _Core1) which is a Resource
	_Core1_syncOutputEvents(&me->tx_core);
	
}
void _TCREST_syncInputEvents(_TCREST_t  *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for rx_core (of type _Core0) which is a Resource
	_Core0_syncInputEvents(&me->rx_core);//sync for tx_core (of type _Core1) which is a Resource
	_Core1_syncInputEvents(&me->tx_core);
	
}

/* _TCREST_sync[Output/Input]Data() synchronises the data connections of an
 * instance of _TCREST as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _TCREST_syncOutputData(_TCREST_t  *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for rx_core (of type _Core0) which is a Resource
	_Core0_syncOutputData(&me->rx_core);//sync for tx_core (of type _Core1) which is a Resource
	_Core1_syncOutputData(&me->tx_core);

}
void _TCREST_syncInputData(_TCREST_t  *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for rx_core (of type _Core0) which is a Resource
	_Core0_syncInputData(&me->rx_core);//sync for tx_core (of type _Core1) which is a Resource
	_Core1_syncInputData(&me->tx_core);

}


/* _TCREST_run() executes a single tick of an
 * instance of _TCREST according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void _TCREST_run(_TCREST_t  *me) {
	_Core0_run(&me->rx_core);
	_Core1_run(&me->tx_core);
	
}

