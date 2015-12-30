## 101 The Blocks Problem
The original problem description is [here](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37)

This problem involves simulating the functionality of a robotic arm to manipulate stacks of blocks. The initial state has all the blocks lined up in sequence from 0 to n. There are four different move operations that must be programmed.

### How I Solved It
My solution is on [Github](https://github.com/taddev/UVa-Submissions/tree/master/101-The_Blocks_Problem).

The problem description states there will be no more than 25 blocks maximum so that become the upper bound that we can program against. Each of the movements has a different requirement for how the blocks and stacks must be manipulated. I had to carefully re-read some of the problem because I found myself trying to program cases that were not legal moves. In fact the moves I was trying to program for where very difficult so them being labeled illegal moves by the description made the program much easier than I was trying to solve.

I chose to implement this solution with series of linked lists. I use a 1 dimensional array to store the initial state of the blocks in sequence from 0 to n based on the user input. This is an array of pointers to the blocks so this problem simply becomes pointer manipulation once the initial state is setup.

The structure I use to store the block information is this:

	struct block {
		int id;
		int stack;
		struct block *above;
		struct block *below;
	};

I had initially not included the stack reference in each block, but it became necessary when I realized I had to be able to check whether two blocks where in the same stack. The problem description required that moves involving blocks in the same stack be ignored so this was my solution to be able to quickly identify which stack the block was currently in. 

### Possible Alternate Solution
Near the end of my work on this problem I realized that I could probably have solved this with a 2 dimensional array that was preallocated to 25x25 since that is the maximum input. Each point in the array would then correspond to spot in a stack and could simply contain the block ID in that position. This solution could be more difficult when you start moving entire stacks because the risk of incorrectly manipulated indexes.  

### Conclusion
My solution ended up with quite a bit of copied code that I'm sure could be condensed if necessary, but having it compartmentalized like I do I believe makes it easier to read and definitely made the logic easier to work through.

This was my first submission that I got *accepted* on the first try so I'm pretty happy with that. If I get real ambitious I might go back and rework this problem with the alternate solution I described, just to see how it would differ.