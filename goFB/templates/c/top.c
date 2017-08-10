{{define "top"}}// This file has been automatically generated by goFB
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}{{$eventQueue := .EventQueue}}{{$instG := .InstG}}
//This is the main file for the iec61499 network with {{$block.Name}} as the top level block

#include "FB_{{$block.Name}}.h"
#include <sys/time.h>
{{if $eventQueue}}#include <unistd.h>{{end}}
// #ifndef MAX_TICKS
// #define MAX_TICKS 100
// #endif

{{if .EventQueue}}//this is being executed with an event queue, which is defined here
#ifndef EVENT_QUEUE_LENGTH
#define EVENT_QUEUE_LENGTH 256
#endif

//this is a FIFO queue which means we need two index values
EventInvokation events[EVENT_QUEUE_LENGTH];
int eventCurrent; //the currently executing event index
int eventInsert; //the location to insert events

//in any given "run", eventInsert should never exceed EVENT_QUEUE_LENGTH
//at the end of a "run", eventInsert and eventCurrent should be reset to zero

//PushEvent is for when an event is emitted by a BFB, and it adds the event to the queue for execution
void PushEvent(short instanceID, char portID) {
	events[eventInsert].InstanceID = instanceID;
	events[eventInsert].PortID = portID;
	eventInsert++;
}

//PopEvent is for when the runtime consumes an event, and it removes an event from the queue
//if it returns 0, there are no more events to consume
//if it returns 1, there is an event to consume
char PopEvent(EventInvokation* event) {
	if(eventCurrent < eventInsert) {
		event->InstanceID = events[eventCurrent].InstanceID;
		event->PortID = events[eventCurrent].PortID;
		eventCurrent++;
		return 1;
	}
	return 0;
}

{{end}}

//put a copy of the top level block into global memory
{{$block.Name}}_t my{{$block.Name}};

int main() {
{{if $eventQueue}}//this is executing with an event queue and event-driven semantics
	eventCurrent = 0;
	eventInsert = 0;

	EventInvokation curEvent;
	while(1) {
		//TODO: only tick SIFBs
		{{$block.Name}}_runSIFBs(&my{{$block.Name}});

		if(!PopEvent(&curEvent)) {
			printf("No events to execute\n");
			sleep(1);
		} 

		//there was an event to execute
		//range all instanceIDs
			//if selected,
			//range all portIDs
				//if selected,
				//copy data to destinations
				//perform all connected invokations
		switch(curEvent.InstanceID) {
		{{range $instanceIndex, $inst := $instG}}
		{{$blockDef := findBlockDefinitionForType $.Blocks $inst.FBType}}{{if and (or $blockDef.BasicFB $blockDef.IsSIFB) $blockDef.EventOutputs}}case {{$inst.InstanceID}}: //{{$inst.InstanceName}} (type {{$inst.FBType}})
			switch(curEvent.PortID) {//range over source output event ports
			{{range $outputEventIndex, $outputEvent := $blockDef.EventOutputs}}
			case {{$outputEventIndex}}: //{{$outputEvent.Name}}
				//copy associated data
				//invoke connected FBs network-wide
				break;{{end}}
			default:
				printf("An error has occurred (unknown port ID %i in event invokation in block {{$inst.InstanceName}}(type {{$blockDef.Name}})!\r\n", curEvent.PortID);
				while(1);
			}
			break;
		{{else}}//{{$inst.InstanceName}} has no source output event ports so can't generate events
		{{end}}{{end}}
		default:
			printf("An error has occurred (unknown instance ID %i in event invokation!\r\n", curEvent.InstanceID);
			while(1);
		}
	
	}

{{else}}//this is executing with synchronous semantics
	//printf("\n\n\n");
	//printf("\nTop: %20s   Size: %lu\n", "{{$block.Name}}", sizeof(my{{$block.Name}}));

	#ifdef PRINT_VALS
	printf("Simulation time,");
	#endif

	if({{$block.Name}}_preinit(&my{{$block.Name}}) != 0) {
		printf("Failed to preinitialize.");
		return 1;
	}
	if({{$block.Name}}_init(&my{{$block.Name}}) != 0) {
		printf("Failed to initialize.");
		return 1;
	}
	printf("\n");
	
	struct timeval tv1, tv2;
	gettimeofday(&tv1, NULL);

	int tickNum = 1;
	do {
		#ifdef PRINT_VALS
			printf("%f,",(double)tickNum*0.01);
		#endif
		{{$block.Name}}_syncOutputEvents(&my{{$block.Name}});
		{{$block.Name}}_syncInputEvents(&my{{$block.Name}});

		{{$block.Name}}_syncOutputData(&my{{$block.Name}});
		{{$block.Name}}_syncInputData(&my{{$block.Name}});
		
		{{$block.Name}}_run(&my{{$block.Name}});
		#ifdef PRINT_VALS
			printf("\n");
		#endif
	} 
	#ifdef MAX_TICKS
		while(tickNum++ < MAX_TICKS);
	#else
		while(1);
	#endif
	gettimeofday(&tv2, NULL);
	#ifdef PRINT_TIME
	printf ("Total time = %f seconds\n",
         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec));
	#endif
	return 0;
{{end}}
}



{{end}}