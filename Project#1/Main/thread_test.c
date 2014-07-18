/**
 *
 * Coded by SatyaSwaroop Boddu and MohanRaj Balumuri
 */
#include <stdio.h>
#include "threads.h"

void function_1() {
	int i = 1;
	while (1) {
		if (i == 10000) {
			i = 1;
			printf("Function 1 Yielding\n");
			yield();
			printf("Function 1 Resuming\n");
		} else
			i++;


	}
}

void function_2() {
	int i = 1;
	while (1) {
		if (i == 10000) {
			i = 1;
			printf("Function 2 Yielding\n");
			yield();
			printf("Function 2 Resuming\n");
		} else
			i++;


	}
}

void function_3() {
	int i = 1;
	while (1) {
		if (i == 10000) {
			i = 1;
			printf("Function 3 Yielding\n");
			yield();
			printf("Function 3 Resuming\n");
		} else
			i++;

	}
}

int main() {
	InitQ(&RunQ);
	start_thread(function_1);
	start_thread(function_2);
	start_thread(function_3);
	run();
	return 0;
}
