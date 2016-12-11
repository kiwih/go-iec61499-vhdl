// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the interface of Function Block IOManager
#include "fbtypes.h"

struct IOManagerInputEvents {
	EVENT DoorReleaseCanister;
	EVENT ConveyorChanged;
	EVENT InjectorPositionChanged;
	EVENT InjectorControlsChanged;
	EVENT FillContentsChanged;
	EVENT StartVacuumTimer;
	EVENT GoRejectArm;
	EVENT CanisterCountChanged;
	EVENT InjectDone;
}

struct IOManagerOutputEvents {
	EVENT InjectorArmFinishMovement;
	EVENT EmergencyStopChanged;
	EVENT CanisterPressureChanged;
	EVENT FillContentsAvailableChanged;
	EVENT LasersChanged;
	EVENT DoorOverride;
	EVENT VacuumTimerElapsed;
}







struct IOManager {
    //input events
    struct IOManagerInputEvents inputEvents;

    //output events
    struct IOManagerOutputEvents outputEvents;

    //input vars
    
    BYTE ConveyorSpeed;
    BYTE InjectorPosition;
    BOOL InjectorContentsValveOpen;
    BOOL InjectorVacuumRun;
    BOOL InjectorPressurePumpRun;
    BOOL FillContents;
    BYTE CanisterCount;

    //output vars
    
    BOOL EmergencyStop;
    BYTE CanisterPressure;
    BYTE FillContentsAvailable;
    BOOL DoorSiteLaser;
    BOOL InjectSiteLaser;
    BOOL RejectSiteLaser;
    BOOL RejectBinLaser;
    BOOL AcceptBinLaser;

    //internal vars
    
    BOOL EmergencyStopped;
    BYTE UART_TX;
    BOOL UART_TX_READY;
    BOOL UART_TX_SEND;

    
}

void IOManager_init(struct IOManager *me);

void IOManager_run(struct IOManager *me, int ev_offset);

