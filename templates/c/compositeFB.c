{{define "compositeFB"}}// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}{{$compositeFB := $block.CompositeFB}}
// This file represents the implementation of the Composite Function Block for {{$block.Name}}
#include "{{$block.Name}}.h"

//When running a composite block, note that you would call the functions in this order
//_init(); 
//do {
//_syncEvents();
//_syncData();
//_run();
//} loop;

{{template "_fbinit" .}}

/* {{$block.Name}}_syncEvents() synchronises the events of an
 * instance of {{$block.Name}} as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void {{$block.Name}}_syncEvents({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//we need to clear our output events before we do synching as we'll be OR-EQUALing them
	{{if $block.EventOutputs}}{{range $index, $count := count (add (div (len $block.EventOutputs.Events) 32) 1)}}me->outputEvents.events[{{$count}}] = 0;
	{{end}}{{end}}

	//clear all input events of fb children as we'll be OR-EQUALing them
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.EventInputs}}
	{{range $index, $count := count (add (div (len $childType.EventInputs.Events) 32) 1)}}me->{{$child.Name}}->inputEvents.events[{{$count}}] = 0;
	{{end}}{{end}}{{end}}
	
	//first, for all "bfb outputs" and "this-level inputs" connections inside this cfb, run their copy
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if and $childType.EventOutputs $childType.BasicFB}}{{range $currEventIndex, $event := $childType.EventOutputs.Events}}
	{{$eventDest := findDestEventName $compositeFB.EventConnections $child.Name $event.Name}}me->{{$eventDest}} |= me->{{$child.Name}}.outputEvents.event.{{$event.Name}};
	{{end}}{{end}}{{end}}

	//second, run this same function on all cfb children
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.CompositeFB}}
	{{$childType.Name}}_syncEvents(&me->{{$child.Name}});//sync for {{$child.Name}} (of type {{$childType.Name}}) which is a CFB
	{{end}}{{end}}

	//third, copy all outputs from all cfbs 




	//old code past here

	//for all basic function block children, perform their synchronisations explicitly
	//events are always copied
	//inputs that go to children
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.EventInputs}}{{range $currEventIndex, $event := $childType.EventInputs.Events}}
	me->{{$child.Name}}.inputEvents.event.{{$event.Name}} = {{$allEventSources := findSourcesEventName $compositeFB.EventConnections $child.Name $event.Name}}{{if $allEventSources}}{{range $currEventSourceIndex, $eventSource := $allEventSources}}{{if $currEventSourceIndex}} || {{end}}me->{{$eventSource}}{{end}}{{else}}0{{end}}; 
	{{end}}{{end}}{{end}}
	//outputs of parent cfb
	{{if $block.EventOutputs}}{{range $eventIndex, $event := $block.EventOutputs.Events}}
	me->outputEvents.event.{{$event.Name}} = {{$allEventSources := findSourcesEventName $compositeFB.EventConnections "" $event.Name}}{{if $allEventSources}}{{range $currEventSourceIndex, $eventSource := $allEventSources}}{{if $currEventSourceIndex}} || {{end}}me->{{$eventSource}}{{end}}{{else}}0{{end}}; 
	{{end}}{{end}}
	
}

/* {{$block.Name}}_syncData() synchronises the data connections of an
 * instance of {{$block.Name}} as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void {{$block.Name}}_syncData({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//for all composite function block children, call this same function
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.CompositeFB}}//sync for {{$child.Name}} (of type {{$childType.Name}}) which is a CFB
	{{$childType.Name}}_syncData(&me->{{$child.Name}});{{end}}{{end}}
	//for all basic function block children, perform their synchronisations explicitly
	//Data is sometimes copied
	{{range $currChildIndex, $child := $compositeFB.FBs}}{{$childType := findBlockDefinitionForType $blocks $child.Type}}{{if $childType.BasicFB}}
	//sync for {{$child.Name}} (of type {{$childType.Name}}) which is a BFB
	{{if $childType.EventInputs}}{{range $currEventIndex, $event := $childType.EventInputs.Events}}{{if $event.With}}
	if(me->{{$child.Name}}.inputEvents.event.{{$event.Name}} == 1) { {{range $withIndex, $with := $event.With}}{{$varDef := findVarDefinitionForName $childType $with.Var}}{{if $varDef}}{{if $varDef.GetArraySize}}
		{{range $index, $count := count $varDef.GetArraySize}}
		me->{{$child.Name}}.{{$with.Var}}[{{$count}}] = me->{{findSourceDataName $compositeFB.DataConnections $child.Name $with.Var}}[{{$count}}];{{end}}
		{{else}}
		me->{{$child.Name}}.{{$with.Var}} = me->{{findSourceDataName $compositeFB.DataConnections $child.Name $with.Var}};{{end}}{{end}}{{end}}
	} {{end}}{{end}}{{end}}{{end}}
	{{end}}
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up)
	{{range $currLinkIndex, $link := $block.CompositeFB.DataConnections}}{{if connIsOnParent $link.Destination}}me->{{$link.Destination}} = me->{{$link.Source}};
	{{end}}{{end}}
	

}


/* {{$block.Name}}_run() executes a single tick of an
 * instance of {{$block.Name}} according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void {{$block.Name}}_run({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	{{range $currChildIndex, $child := $block.CompositeFB.FBs}}{{$child.Type}}_run(&me->{{$child.Name}});
	{{end}}
}

{{end}}