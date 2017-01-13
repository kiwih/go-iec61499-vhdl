// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block _Core1
#ifndef _CORE1_H_
#define _CORE1_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "ArgoTx.h"
#include "Producer.h"


//this block had no input events


//this block had no output events


struct _Core1 {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	struct ArgoTx tx;
	struct Producer prod;
	
	//resource vars
	UDINT TxChanId;
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
};

//all FBs get an init function
int __attribute__ ((noinline)) _Core1_init(struct _Core1 *me);

//all FBs get a run function
void __attribute__ ((noinline)) _Core1_run(struct _Core1 *me);

//composite/resource/device FBs get sync functions
void __attribute__ ((noinline)) _Core1_syncEvents(struct _Core1 *me);
void __attribute__ ((noinline)) _Core1_syncData(struct _Core1 *me);

#endif
