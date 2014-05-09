#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findLeastMoves(long moves[]){
	int i = 0;
	int least = 0;

	for(i=1; i<6; i++){
		if(moves[i] < moves[least]){
			least = i;
		}
	}

	return least;
}

int main() {
	char inputBuffer[256] = "\0";
	char *endBuffer = NULL;
	int binArray[3][3]; /* brown=[][0], green=[][1], clear=[][2] */
	int brown = 0;
	int green = 1;
	int clear = 2;
	int i = 0;
	int j = 0;
	long moves[6] = {0};
	int least = 0;
	char moveCombos[][4] = {"BCG",
							"BGC",
							"CBG",
							"CGB",
							"GBC",
							"GCB"
							};


	while(fgets(inputBuffer, 255, stdin) != NULL){
		/*sscanf(inputBuffer, "%d %d %d %d %d %d %d %d %d");*/

		/* set the buffer pointer to the start of the input string */
		endBuffer = inputBuffer;

		/* parse the input into storage */
		for(i=0; i<3; i++){
			/* initial input into bins */
			for(j=0; j<3; j++){
				binArray[i][j] = (int) strtol(endBuffer, &endBuffer, 10);
			}
		}

		/* BCG */
		moves[0] = 0;
		moves[0] += binArray[1][brown] + binArray[2][brown];
		moves[0] += binArray[0][clear] + binArray[2][clear];
		moves[0] += binArray[0][green] + binArray[1][green];

		/* BGC */
		moves[1] = 0;
		moves[1] += binArray[1][brown] + binArray[2][brown];
		moves[1] += binArray[0][green] + binArray[2][green];
		moves[1] += binArray[0][clear] + binArray[1][clear];

		/* CBG */
		moves[2] = 0;
		moves[2] += binArray[1][clear] + binArray[2][clear];
		moves[2] += binArray[0][brown] + binArray[2][brown];
		moves[2] += binArray[0][green] + binArray[1][green];

		/* CGB */
		moves[3] = 0;
		moves[3] += binArray[1][clear] + binArray[2][clear];
		moves[3] += binArray[0][green] + binArray[2][green];
		moves[3] += binArray[0][brown] + binArray[1][brown];

		/* GBC */
		moves[4] = 0;
		moves[4] += binArray[1][green] + binArray[2][green];
		moves[4] += binArray[0][brown] + binArray[2][brown];
		moves[4] += binArray[0][clear] + binArray[1][clear];

		/* GCB */
		moves[5] = 0;
		moves[5] += binArray[1][green] + binArray[2][green];
		moves[5] += binArray[0][clear] + binArray[2][clear];
		moves[5] += binArray[0][brown] + binArray[1][brown];

		least = findLeastMoves(moves);
		printf("%s %d\n", moveCombos[least], moves[least]);

		least = 0;
	}

	return 0;
}