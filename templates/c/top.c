{{define "top"}}// This file has been automatically generated by goFB
// Transpiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}
//This is the main file for the iec61499 network with {{$block.Name}} as the top level block

#include "{{$block.Name}}.h"

//put a copy of the top level block into global memory
struct {{$block.Name}} my{{$block.Name}};

int main() {
	if({{$block.Name}}_init(&my{{$block.Name}}) != 0) {
		printf("Failed to initialize.");
		return 1;
	}
	
	do {
		{{$block.Name}}_syncEvents(&my{{$block.Name}});
		{{$block.Name}}_syncData(&my{{$block.Name}});
		{{$block.Name}}_run(&my{{$block.Name}});
	} while(true);

	return 0;
}

{{end}}