#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct range *rangeptr;

struct range{
	int start;
	int end;
	rangeptr next;
};

rangeptr head = NULL;
rangeptr tail = NULL;

int findCycles(int i) {
	int n = i;
	int count = 1;

	while(n != 1){
		if(n%2 == 0){
			n = n/2;
		}
		else {
			n = (3 * n) + 1;
		}
		count++;
	}

	return count;
}

void addRange(start, end) {
	if(head == NULL && tail == NULL){
		head = (rangeptr) malloc(sizeof(struct range));
		head->start = start;
		head->end = end;
		head->next = NULL;
		tail = head;
	}
	else {
		tail->next = (rangeptr)malloc(sizeof(struct range));
		tail = tail->next;
		tail->start = start;
		tail->end = end;
		tail->next = NULL;
	}
}

int main(){
	int start,end, i, cycles;
	int largest = 0;
	char inputBuffer[14];
	char *endBuffer;
	rangeptr tempPtr = NULL;

	while(1) {
		fgets(inputBuffer, 14, stdin);
		start = (int) strtol(inputBuffer, &endBuffer, 10);
		end = (int) strtol(endBuffer, &endBuffer, 10);

		if((start != 0 && end != 0) && start < end) {
			addRange(start, end);
		}
		else {
			break;
		}
	}

	tempPtr = head;
	while(tempPtr != NULL){
		for(i=tempPtr->start; i<=tempPtr->end; i++) {
			cycles = findCycles(i);

			if(cycles > largest){
				largest = cycles;
			}
		}

		printf("%d %d %d\n", tempPtr->start, tempPtr->end, largest);
		tempPtr = tempPtr->next;
		largest = 0;
		cycles = 0;
	}

	return 0;
}