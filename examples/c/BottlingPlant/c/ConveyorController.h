// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the interface of Function Block ConveyorController
#include "fbtypes.h"

struct ConveyorControllerInputEvents {
	EVENT InjectDone;
	EVENT EmergencyStopChanged;
	EVENT LasersChanged;
}

struct ConveyorControllerOutputEvents {
	EVENT ConveyorChanged;
	EVENT ConveyorStoppedForInject;
}







struct ConveyorController {
    //input events
    struct ConveyorControllerInputEvents inputEvents;

    //output events
    struct ConveyorControllerOutputEvents outputEvents;

    //input vars
    
    BOOL EmergencyStop;
    BOOL InjectSiteLaser;

    //output vars
    
    BYTE ConveyorSpeed;

    //internal vars
    
    BOOL Variable1;

    
}

void ConveyorController_init(struct ConveyorController *me);

void ConveyorController_run(struct ConveyorController *me, int ev_offset);

