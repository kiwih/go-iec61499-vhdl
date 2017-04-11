{{define "basicFB"}}// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}{{$basicFB := $block.BasicFB}}{{$tcrestUsingSPM := .TcrestUsingSPM}}{{$tcrestSmartSPM := .TcrestSmartSPM}}{{$cvodeEnabled := .CvodeEnabled}}
// This file represents the implementation of the Basic Function Block for {{$block.Name}}
#include "{{$block.Name}}.h"

{{template "_fbinit" .}}

{{if $basicFB.Algorithms}}//algorithms
{{if $cvodeEnabled}}{{template "_cvode_fs" $block}}{{end}}
{{range $algIndex, $alg := $basicFB.Algorithms}}
void {{$block.Name}}_{{$alg.Name}}({{$block.Name}}_t {{if or $tcrestUsingSPM $tcrestSmartSPM}}_SPM{{end}} *me) {
{{if algorithmNeedsCvodeInit $alg}}//AUTOGENERATED CODE: see {{$block.Name}}_{{$alg.Name}}_cvode_init()
	{{$block.Name}}_{{$alg.Name}}_cvode_init(me);
{{else if algorithmNeedsCvode $alg}}
//NO CODE: this is a cvode algorithm, so is defined elsewhere
{{else}}//PROVIDED CODE: this algorithm was provided in an algorithm's text field
{{$alg.Other.Text}}
{{end}}
}
{{end}}
{{else}}//no algorithms were present for this function block
{{end}}

/* {{$block.Name}}_run() executes a single tick of an
 * instance of {{$block.Name}} according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void {{$block.Name}}_run({{$block.Name}}_t {{if or $tcrestUsingSPM $tcrestSmartSPM}}_SPM{{end}} *me) {
	//if there are output events, reset them
	{{/*{{if $block.EventOutputs}}{{range $index, $count := count (add (div (len $block.EventOutputs.Events) 32) 1)}}me->outputEvents.events[{{$count}}] = 0;
	{{end}}{{end}}// this method seems to be having trouble on the t-crest SPM memory*/}}
	{{if $block.EventOutputs}}{{range $index, $event := $block.EventOutputs.Events}}me->outputEvents.event.{{$event.Name}} = 0;
	{{end}}{{end}}

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		{{range $curStateIndex, $curState := $basicFB.States}}case STATE_{{$block.Name}}_{{$curState.Name}}:
			{{range $transIndex, $trans := $basicFB.GetTransitionsForState $curState.Name}}{{if $transIndex}}} else {{end}}if({{$cond := getCECCTransitionCondition $block $trans.Condition}}{{$cond.IfCond}}) {
				me->_state = STATE_{{$block.Name}}_{{$trans.Destination}};
				me->_trigger = true;
			{{end}}{{if $basicFB.GetTransitionsForState $curState.Name}}};{{end}}
			break;
		{{end}}
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		{{range $curStateIndex, $curState := $basicFB.States}}case STATE_{{$block.Name}}_{{$curState.Name}}:
			{{range $actionIndex, $action := $curState.ECActions}}{{if $action.Algorithm}}{{$block.Name}}_{{$action.Algorithm}}(me);
			{{end}}{{if $action.Output}}me->outputEvents.event.{{$action.Output}} = 1;
			{{end}}{{end}}break;

		{{end}}
		}
	}

	me->_trigger = false;
}


{{end}}