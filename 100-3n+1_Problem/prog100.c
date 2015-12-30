#include <stdio.h>
#include <stdlib.h>

int findCycles(int i) {
	int n = i;
	int count = 1;

	while(n != 1) {
		if(n&1 != 0){
			n = (3 * n) + 1;
		}
		else {
			n = n >> 1;
		}
		count++;
	}

	return count;
}

int findLargestCycle(int start, int end) {
	int i = 0;
	int cycles = 0;
	int largest = 0;

	for(i=start; i<=end; i++) {
		cycles = findCycles(i);

		if(cycles > largest){
			largest = cycles;
		}
	}

	return largest;
}

int main(){
	int start 	= 0;
	int end 	= 0;
	int i 		= 0;
	int largest = 0;
	char inputBuffer[20];
	char *endBuffer;

	while(fgets(inputBuffer, 19, stdin) != NULL) {
		start = (int) strtol(inputBuffer, &endBuffer, 10);
		end = (int) strtol(endBuffer, &endBuffer, 10);

		printf("%d %d ", start, end);

		if(start > end) {
			largest = findLargestCycle(end, start);
		}
		else if(start == end){
			largest = findCycles(start);
		}
		else{
			largest = findLargestCycle(start, end);
		}

		printf("%d\n", largest);

		/* cleanup
		fflush(stdin);
		inputBuffer[0] = '\0';
		endBuffer = NULL;
		largest = 0;
		start = 0;
		end = 0;
		*/
	}

	return 0;
}