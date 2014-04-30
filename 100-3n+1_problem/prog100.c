#include <stdio.h>
#include <string.h>

int findCycles(int i) {
	int n = i;
	int count = 1;

	while(n != 1){
		if(n%2 == 0){
			n = n >> 1;
		}
		else {
			n = (3 * n) + 1;
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
	int start,end, i;
	int largest = 0;
	char inputBuffer[14];
	char *endBuffer;

	while(1) {
		fgets(inputBuffer, 14, stdin);
		start = (int) strtol(inputBuffer, &endBuffer, 10);
		end = (int) strtol(endBuffer, &endBuffer, 10);

		printf("%d %d ", start, end);

		if(start != 0 && end != 0) {
			if(start > end) {
				largest = findLargestCycle(end, start);
			}
			else{
				largest = findLargestCycle(start, end);
			}

			printf("%d\n", largest);
		}
		else {
			break;
		}
	}

	return 0;
}