#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * block item
 */
struct block {
	int id;
	struct block *above;
	struct block *below;
};

/* block pointer array */
struct block *blockArray[25];

/* block array size */
int blockCount;

/*****************************
 * Basic Array Manipulations *
 *****************************/

/*
 * initialize array
 */
void initializeArray() {
	int i = 0;

	for(i=0; i<blockCount; i++){
		blockArray[i] = (struct block *)malloc(sizeof(struct block));
		blockArray[i]->id = i;
		blockArray[i]->above = NULL;
		blockArray[i]->below = NULL;
	}
}


/*
 * print array
 */
void printArray(){
	int i = 0;
	struct block *temp;

	for(i=0; i<blockCount; i++){
		printf("%d:", i);

		if(blockArray[i] != NULL) {
			printf(" %d", i, blockArray[i]->id);

			temp = blockArray[i]->above;
			while(temp != NULL){
				printf(" %d", temp->id);
				temp = temp->above;
			}
		}
		printf("\n");
	}
}

/*
 * clean up array
 */
void cleanupArray(){
	int i = 0;

	/* cleanup array */
	for(i=0; i<blockCount; i++){
		free(blockArray[i]);
	}
}

/***********************
 * Block Manipulations *
 ***********************/

/*
 * findBlock
 *
 * This function finds a block based on its ID and returns the pointer
 * to it's current location
 */
struct block *findBlock(int blockID) {
	struct block *temp = NULL;
	int i;

	for(i=0; i<blockCount; i++){
		if(blockArray[i] != NULL) {
			temp = blockArray[i];
			while(temp != NULL){
				if(temp->id == blockID) {
					return temp;
				}
				temp = temp->above;
			}
		}
	}
}

/*
 * findTop
 *
 * Find the top of a stack of blocks.
 */
struct block *findTop(struct block *blockPTR) {
	struct block *temp = blockPTR;

	while(temp->above != NULL) {
		temp = temp->above;
	}

	return temp;
}

/*
 * resetBlock
 *
 * Returns a block to it's original postion
 */
void resetBlock(struct block *blockPTR){
	if(blockPTR != NULL) {
		if(blockPTR->below != NULL){
			blockPTR->below->above = NULL;
		}

		blockPTR->below = NULL;
		blockPTR->above = NULL;

		blockArray[blockPTR->id] = blockPTR;
	}
}

/*
 * clearAbove
 *
 * This function returns any blocks stacked on top of the defined block
 * to their original locations
 */
void clearAbove(struct block *blockPTR){
	struct block *temp1 = NULL;
	struct block *temp2 = NULL;

	/* break off the pile above the block we're moving */
	temp1 = blockPTR->above;

	/* loop through everything on the pile moving it back
	   to it's original position */
	while(temp1 != NULL){
		temp2 = temp1;
		temp1 = temp1->above;
		resetBlock(temp2);
	}

	blockPTR->above = NULL;
}


/*
 * moveOntoBlock
 *
 * Moves block A onto block B. First find the two blocks based on their ID
 * then clear all blocks above them, if any. Once they are prepared then
 * blockA on top of blockB
 */
void moveOntoBlock(int blockA, int blockB){
	struct block *ptrBlockA = NULL;
	struct block *ptrBlockB = NULL;

	/* locate the blocks based on their ID's */
	ptrBlockA = findBlock(blockA);
	ptrBlockB = findBlock(blockB);

	/* clear all blocks above the two blocks in question */
	clearAbove(ptrBlockA);
	clearAbove(ptrBlockB);


	/* check if block A is comming off and existing stack, and break it
	   loose from that stack */
	if(ptrBlockA->below != NULL){
		ptrBlockA->below->above = NULL;
	}

	/* move block A onto block B */
	ptrBlockB->above = ptrBlockA;
	ptrBlockA->below = ptrBlockB;

	/* make sure the initial position of block A is empty */
	blockArray[blockA] = NULL;
}

/*
 * moveOverBlock
 *
 * Clears the stack of blocks off A. Put A on top of the stack of B.
 */
void moveOverBlock(int blockA, int blockB) {
	struct block *ptrBlockA = NULL;
	struct block *ptrBlockB = NULL;

	ptrBlockA = findBlock(blockA);
	ptrBlockB = findBlock(blockB);

	clearAbove(ptrBlockA);

	/* if block A is on a stack break it free from that stack before moving
	   it over another stack */
	if(ptrBlockA->below != NULL){
		ptrBlockA->below->above = NULL;
	}

	/* find the top of the stack containig block B */
	ptrBlockB = findTop(ptrBlockB);

	/* add A to the top of B's stack */
	ptrBlockB->above = ptrBlockA;
	ptrBlockA->below = ptrBlockB;

	/* make sure block A's initial position is cleared */
	blockArray[blockA] = NULL;
}

/*
 * pileOntoBlock
 *
 * Clears the stack off block B then moves the stack starting at block A
 * onto block B
 */
void pileOntoBlock(int blockA, int blockB) {
	struct block *ptrBlockA = NULL;
	struct block *ptrBlockB = NULL;

	/* find blocks based on their ID */
	ptrBlockA = findBlock(blockA);
	ptrBlockB = findBlock(blockB);

	/* reset all the blocks currently above block B */
	clearAbove(ptrBlockB);

	/* if block A is currently on a stack break it free from that stack */
	if(ptrBlockA->below != NULL){
		ptrBlockA->below->above = NULL;
	}

	/* pile the stack starting at A onto whatever is already on B */
	ptrBlockB->above = ptrBlockA;
	ptrBlockA->below = ptrBlockB;

	/* make sure block A's initial position is cleared */
	blockArray[blockA] = NULL;
}

int main() {
	char inputBuffer[20] = "\0";
	char *endBuffer = NULL;
	char command[2][5] = {"\0"};
	int i = 0;
	int blockA = 0;
	int blockB = 0;
	struct block *ptrBlockA = NULL;
	struct block *ptrBlockB	= NULL;

	fgets(inputBuffer, 19, stdin);
	blockCount = (int) strtol(inputBuffer, &endBuffer, 10);

	initializeArray();

	while(strncmp(command[1], "quit", 4) != 0) {
		fgets(inputBuffer, 19, stdin);
		sscanf(inputBuffer, "%s %d %s %d", command[1], &blockA, command[2], &blockB);

		if(blockA != blockB){
			if(strncmp(command[1], "move", 4) == 0){
				if(strncmp(command[2], "onto", 4) == 0) {
					/*move a onto b*/
					moveOntoBlock(blockA, blockB);
				}
				else if(strncmp(command[2], "over", 4) == 0) {
					/*move a over b*/
					moveOverBlock(blockA, blockB);
				}
			}
			else if(strncmp(command[1], "pile", 4) == 0) {
				if(strncmp(command[2], "onto", 4) == 0) {
					/*pile a onto b*/
					pileOntoBlock(blockA, blockB);
				}
				else if(strncmp(command[2], "over", 4) == 0) {
					/*pile a over b*/
				}
			}
			else if(strncmp(command[1], "prin", 4) == 0) {
				printArray();
			}
		}
	}

	printArray();
	cleanupArray();

	return 0;
}