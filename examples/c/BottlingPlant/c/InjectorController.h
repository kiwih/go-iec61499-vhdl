// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the interface of Function Block InjectorController
#include "fbtypes.h"

union InjectorControllerInputEvents {
	struct {
		UDINT InjectorArmFinishedMovement : 1;
		UDINT EmergencyStopChanged : 1;
		UDINT CanisterPressureChanged : 1;
		UDINT FillContentsAvailableChanged : 1;
		UDINT ConveyorStoppedForInject : 1;
		UDINT VacuumTimerElapsed : 1;
	} event;
	UDINT events[1];
};

union InjectorControllerOutputEvents {
	struct {
		UDINT InjectDone : 1;
		UDINT InjectorPositionChanged : 1;
		UDINT InjectorControlsChanged : 1;
		UDINT RejectCanister : 1;
		UDINT FillContentsChanged : 1;
		UDINT StartVacuumTimer : 1;
		UDINT InjectRunning : 1;
	} event;
	UDINT events[1];
};

struct InjectorController {
    //input events
    union InjectorControllerInputEvents inputEvents;

    //output events
    union InjectorControllerOutputEvents outputEvents;

    //input vars
	BOOL EmergencyStop;
    BYTE CanisterPressure;
    BYTE FillContentsAvailable;
    
    //output vars
	BYTE InjectorPosition;
    BOOL InjectorContentsValveOpen;
    BOOL InjectorVacuumRun;
    BOOL InjectorPressurePumpRun;
    BOOL FillContents;
    
    
};

void InjectorController_init(struct InjectorController *me);

void InjectorController_run(struct InjectorController *me);



