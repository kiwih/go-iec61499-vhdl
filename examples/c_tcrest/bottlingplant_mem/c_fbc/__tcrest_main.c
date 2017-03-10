//This is the main file for the iec61499 network with _TCREST as the top level block

#include "FlexPRET.h"

#ifndef PROGS_PER_CORE
#define PROGS_PER_CORE 1
#endif

//put a copy of the top level block into global memory
//struct _TCREST my_TCREST;

const int NOC_MASTER = 0;

void t(void* param);

void task(FlexPRET * c);

int main() {
	printf("bottlingplant_mem tcrest4 startup.\n");
	printf("sizes: %lu, %lu, %lu, %lu\n", sizeof(FlexPRET), sizeof(FlexPRET), sizeof(FlexPRET), sizeof(FlexPRET));
	mp_init();
	printf("Starting t1,t2,t3 and initialising my_TCREST...\n");
	corethread_t core1 = 1;
	corethread_create(&core1, &t, NULL);
	corethread_t core2 = 2;
	corethread_create(&core2, &t, NULL);
	corethread_t core3 = 3;
	corethread_create(&core3, &t, NULL);
	printf("Started t1,t2,t3\n");

	t(NULL);
	int* res;
	//corethread_join(core1, (void**)&res);

	return 0;
}

void __attribute__ ((noinline)) timed_task(FlexPRET * c) {
	for(int i=0; i<PROGS_PER_CORE;i++) {

		FlexPRETrun(&c[i]);
	}
}

void task(FlexPRET * c) {
	//task0 runs core0
	unsigned int tickCount = 0;

	unsigned long long start_time;
	unsigned long long end_time;

	do {
		start_time = get_cpu_cycles();

		timed_task(c);

		end_time = get_cpu_cycles();
		printf("%4d\t\t%lld\n", tickCount, end_time-start_time-3);

		tickCount++;
	} while(1);
}

void t(void* param) {
	HEX = 7;
	FlexPRET c[PROGS_PER_CORE];
	
	//c0 = &c; //SPM_BASE;
	for(int i=0; i < PROGS_PER_CORE; i++) {
		FlexPRETinit(&c[i]);
	}

	HEX = 10;
	
	task(c);
}
