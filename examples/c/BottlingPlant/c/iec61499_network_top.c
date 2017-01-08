// This file has been automatically generated by goFB
// Transpiler written by Hammond Pearce and available at github.com/kiwih/goFB

//This is the main file for the iec61499 network with FlexPRET as the top level block

#include "FlexPRET.h"

//put a copy of the top level block into global memory
struct FlexPRET myFlexPRET;

int main() {
	FlexPRET_init(&myFlexPRET);
	do {
		FlexPRET_syncEvents(&myFlexPRET);
		FlexPRET_syncData(&myFlexPRET);
		FlexPRET_run(&myFlexPRET);
	} while(true);
	return 0;
}

