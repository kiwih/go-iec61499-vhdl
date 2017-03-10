// This file is generated by FBC.

#ifndef CANISTERCOUNTER_H_
#define CANISTERCOUNTER_H_

#include "fbtypes.h"

typedef union {
    struct {
        UDINT LasersChanged ; // 
    } event;
} CanisterCounterIEvents;

typedef union {
    struct {
        UDINT CanisterCountChanged ; // 
    } event;
} CanisterCounterOEvents;

typedef struct {
    BOOL _entered;
    CanisterCounterIEvents _input;
    BOOL DoorSiteLaser; // 
    BOOL _DoorSiteLaser;
    BOOL RejectBinLaser; // 
    BOOL _RejectBinLaser;
    BOOL AcceptBinLaser; // 
    BOOL _AcceptBinLaser;
    CanisterCounterOEvents _output;
    BYTE CanisterCount; // 
    BYTE _CanisterCount;
} CanisterCounter;

/* Function block initialization function */
void CanisterCounterinit(CanisterCounter* me);

/* Function block execution function */
void CanisterCounterrun(CanisterCounter* me);

/* ECC algorithms */
void CanisterCounter_ChangeCount(CanisterCounter* me);

#endif // CANISTERCOUNTER_H_
