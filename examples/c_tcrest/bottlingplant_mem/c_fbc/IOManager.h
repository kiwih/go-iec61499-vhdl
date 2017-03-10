// This file is generated by FBC.

#ifndef IOMANAGER_H_
#define IOMANAGER_H_

#include "fbtypes.h"

typedef union {
    struct {
        UDINT DoorReleaseCanister ; // 
        UDINT ConveyorChanged ; // 
        UDINT InjectorPositionChanged ; // 
        UDINT InjectorControlsChanged ; // 
        UDINT FillContentsChanged ; // 
        UDINT StartVacuumTimer ; // 
        UDINT GoRejectArm ; // 
        UDINT CanisterCountChanged ; // 
        UDINT InjectDone ; // 
    } event;
} IOManagerIEvents;

typedef union {
    struct {
        UDINT InjectorArmFinishMovement ; // 
        UDINT EmergencyStopChanged ; // 
        UDINT CanisterPressureChanged ; // 
        UDINT FillContentsAvailableChanged ; // 
        UDINT LasersChanged ; // 
        UDINT DoorOverride ; // 
        UDINT VacuumTimerElapsed ; // 
    } event;
} IOManagerOEvents;

typedef struct {
    BOOL _entered;
    IOManagerIEvents _input;
    BYTE ConveyorSpeed; // 
    BYTE _ConveyorSpeed;
    BYTE InjectorPosition; // 
    BYTE _InjectorPosition;
    BOOL InjectorContentsValveOpen; // 
    BOOL _InjectorContentsValveOpen;
    BOOL InjectorVacuumRun; // 
    BOOL _InjectorVacuumRun;
    BOOL InjectorPressurePumpRun; // 
    BOOL _InjectorPressurePumpRun;
    BOOL FillContents; // 
    BOOL _FillContents;
    BYTE CanisterCount; // 
    BYTE _CanisterCount;
    IOManagerOEvents _output;
    BOOL EmergencyStop; // 
    BOOL _EmergencyStop;
    BYTE CanisterPressure; // 
    BYTE _CanisterPressure;
    BYTE FillContentsAvailable; // 
    BYTE _FillContentsAvailable;
    BOOL DoorSiteLaser; // 
    BOOL _DoorSiteLaser;
    BOOL InjectSiteLaser; // 
    BOOL _InjectSiteLaser;
    BOOL RejectSiteLaser; // 
    BOOL _RejectSiteLaser;
    BOOL RejectBinLaser; // 
    BOOL _RejectBinLaser;
    BOOL AcceptBinLaser; // 
    BOOL _AcceptBinLaser;
    INT EmergencyStopped; // 
    INT BottlePositions[4]; // 
    BOOL BottlesActive[4]; // 
    INT NextBottle; // 
    INT InternalConveyorSpeed; // 
} IOManager;

/* Function block initialization function */
void IOManagerinit(IOManager* me);

/* Function block execution function */
void IOManagerrun(IOManager* me);

/* ECC algorithms */
void IOManager_IOAlgorithm(IOManager* me);

#endif // IOMANAGER_H_
