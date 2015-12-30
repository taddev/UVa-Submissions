#include <stdio.h>

int main() {
	char inputBuffer[10];
	char *endBuffer;
	int input = -1;

	do {
		printf("Input: ");
		fgets(inputBuffer, 9, stdin);
		input = (int)strtol(inputBuffer, &endBuffer, 10);

		if(input&1 != 0){
			printf("odd\n");
		}
		else {
			printf("even\n");
		}
	}
	while(input != 0);
}