// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block _CoreSingle
#ifndef _CORESINGLE_H_
#define _CORESINGLE_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "SawmillModule.h"
#include "SawmillModule.h"
#include "SawmillModule.h"
#include "PrintStatus.h"


//this block had no input events


//this block had no output events


typedef struct {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	SawmillModule_t saw1;
	SawmillModule_t saw2;
	SawmillModule_t saw3;
	PrintStatus_t statusprint;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} _CoreSingle_t;

//all FBs get a preinit function
int _CoreSingle_preinit(_CoreSingle_t _SPM *me);

//all FBs get an init function
int _CoreSingle_init(_CoreSingle_t _SPM *me);

//all FBs get a run function
void _CoreSingle_run(_CoreSingle_t _SPM *me);

//composite/resource/device FBs get sync functions
void _CoreSingle_syncOutputEvents(_CoreSingle_t _SPM *me);
void _CoreSingle_syncInputEvents(_CoreSingle_t _SPM *me);

void _CoreSingle_syncOutputData(_CoreSingle_t _SPM *me);
void _CoreSingle_syncInputData(_CoreSingle_t _SPM *me);



#endif
