// This file has been automatically generated by goFB and should not be edited by hand
// Transpiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block _TCREST
#ifndef _TCREST_H_
#define _TCREST_H_

#include "fbtypes.h"



//this block had no input events
//This block is a device and probably contains resources
#include "_Core0.h"
#include "_Core1.h"


//this block had no output events


struct _TCREST {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	BOOL tcrestInput;
	INT Core0Input;
	
	//resources (Devices only)
	struct _Core0 Resource;
	struct _Core1 Resource1;
	
	//state and trigger (BFBs only)
	
};

//all FBs get an init function
int _TCREST_init(struct _TCREST *me);

//all FBs get a run function
void _TCREST_run(struct _TCREST *me);

//composite/resource/device FBs get sync functions
void _TCREST_syncEvents(struct _TCREST *me);
void _TCREST_syncData(struct _TCREST *me);

#endif
