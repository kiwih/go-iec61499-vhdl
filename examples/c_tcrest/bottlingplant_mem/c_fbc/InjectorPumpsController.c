// This file is generated by FBC.

#include "InjectorPumpsController.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void InjectorPumpsControllerinit(InjectorPumpsController* me)
{
    me->_state = 0;
    me->_entered = false;

    me->_input.event.StartPump = 0;
    me->_input.event.EmergencyStopChanged = 0;
    me->_input.event.CanisterPressureChanged = 0;
    me->_input.event.FillContentsAvailableChanged = 0;
    me->_input.event.VacuumTimerElapsed = 0;

    me->_output.event.PumpFinished = 0;
    me->_output.event.RejectCanister = 0;
    me->_output.event.InjectorControlsChanged = 0;
    me->_output.event.FillContentsChanged = 0;
    me->_output.event.StartVacuumTimer = 0;
}

/* ECC algorithms */
void InjectorPumpsController_StartVacuum(InjectorPumpsController* me)
{
me->InjectorVacuumRun = 1;
//printf("Injector: Start vacuum\n");
}

void InjectorPumpsController_ClearControls(InjectorPumpsController* me)
{
me->InjectorContentsValveOpen = 0;
me->InjectorPressurePumpRun = 0;
me->InjectorVacuumRun = 0;
//printf("Injector: Clear controls\n");
}

void InjectorPumpsController_OpenValve(InjectorPumpsController* me)
{
me->InjectorContentsValveOpen = 1;
//printf("Injector: Open valve\n");
}

void InjectorPumpsController_StartPump(InjectorPumpsController* me)
{
me->InjectorPressurePumpRun = 1;
//printf("Injector: Start pump\n");
}

/* Function block execution function */
void InjectorPumpsControllerrun(InjectorPumpsController* me)
{
    int _PRET_BOUND_i = 0;
    me->_output.event.PumpFinished = 0;
    me->_output.event.RejectCanister = 0;
    me->_output.event.InjectorControlsChanged = 0;
    me->_output.event.FillContentsChanged = 0;
    me->_output.event.StartVacuumTimer = 0;


        if (me->_input.event.EmergencyStopChanged) {
            me->EmergencyStop = me->_EmergencyStop;
        }
        if (me->_input.event.CanisterPressureChanged) {
            me->CanisterPressure = me->_CanisterPressure;
        }
        if (me->_input.event.FillContentsAvailableChanged) {
            me->FillContentsAvailable = me->_FillContentsAvailable;
        }
    
	#pragma loopbound min 1 max 2
    for (_PRET_BOUND_i = 0; _PRET_BOUND_i < 2; _PRET_BOUND_i++) {
    asm("#@PRET_Bound 2");
        switch (me->_state) {
        asm("#@PRET_switch_start 1");
            case 0:
                // State: RejectCanister
                if (!me->_entered) {
                    InjectorPumpsController_ClearControls(me);
                    me->_output.event.RejectCanister = 1;
                    me->_output.event.InjectorControlsChanged = 1;
                    me->_entered = true;
                    break;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                    break;
                }
                break;
            case 1:
                // State: AwaitPump
                if (!me->_entered) {
                    me->_output.event.PumpFinished = 1;
                    me->_entered = true;
                    break;
                }
                else {
                    if (me->_input.event.StartPump) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                    break;
                }
                break;
            case 2:
                // State: VacuumPump
                if (!me->_entered) {
                    InjectorPumpsController_StartVacuum(me);
                    me->_output.event.InjectorControlsChanged = 1;
                    me->_output.event.StartVacuumTimer = 1;
                    me->_entered = true;
                    break;
                }
                else {
                    if (me->_input.event.VacuumTimerElapsed) {
                        me->_state = 0;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.CanisterPressureChanged && (me->CanisterPressure <= 10)) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                    break;
                }
                break;
            case 3:
                // State: StopVacuum
                if (!me->_entered) {
                    InjectorPumpsController_ClearControls(me);
                    me->_output.event.InjectorControlsChanged = 1;
                    me->_entered = true;
                    break;
                }
                else {
                    me->_state = 4;
                    me->_entered = false;
                    continue;
                    break;
                }
                break;
            case 4:
                // State: OpenValve
                if (!me->_entered) {
                    InjectorPumpsController_OpenValve(me);
                    me->_output.event.InjectorControlsChanged = 1;
                    me->_entered = true;
                    break;
                }
                else {
                    me->_state = 5;
                    me->_entered = false;
                    continue;
                    break;
                }
                break;
            case 5:
                // State: StartPump
                if (!me->_entered) {
                    InjectorPumpsController_StartPump(me);
                    me->_output.event.InjectorControlsChanged = 1;
                    me->_entered = true;
                    break;
                }
                else {
                    if (me->_input.event.CanisterPressureChanged && (me->CanisterPressure >= 245)) {
                        me->_state = 6;
                        me->_entered = false;
                        continue;
                    }
                    break;
                }
                break;
            case 6:
                // State: FinishPump
                if (!me->_entered) {
                    InjectorPumpsController_ClearControls(me);
                    me->_output.event.InjectorControlsChanged = 1;
                    me->_entered = true;
                    break;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                    break;
                }
                break;
        }
        break;
    asm("#@PRET_switch_end 1");
    }
    if (me->_output.event.InjectorControlsChanged) {
        me->_InjectorPressurePumpRun = me->InjectorPressurePumpRun;
        me->_InjectorVacuumRun = me->InjectorVacuumRun;
        me->_InjectorContentsValveOpen = me->InjectorContentsValveOpen;
    }
    if (me->_output.event.FillContentsChanged) {
        me->_FillContents = me->FillContents;
    }

    me->_input.event.StartPump = 0;
    me->_input.event.EmergencyStopChanged = 0;
    me->_input.event.CanisterPressureChanged = 0;
    me->_input.event.FillContentsAvailableChanged = 0;
    me->_input.event.VacuumTimerElapsed = 0;
}

