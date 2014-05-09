## 102 Ecological Bin Packing
This problem is built around the problem of sorting glass bottles by color. There are three colors of glass (brown, green, clear) and we need to figure out how to sort them in the least number of moves. The input is a series of 9 integers that define the number of each color bottles that go into each of three initial bins. 

The boundaries in the problem are based around the number of bins and the number of colors, both the same. So we know right away that the maximum number of combinations to our sorting problem is `3 x 2 x 1 = 6`. 

	These options sorted alphabeically are:
		BCG
		BGC
		CBG
		CGB
		GBC
		GCB

So I could have gotten fancy and figured out the necessary logic to solves these combinations via loops but since there are only 6 options it's just as easy to copy/paste/edit to get all the combinations. 

### How I solved it
Like my solutions so far I want to make sure I'm using at least a secure input method so I define an input buffer and use `fgets()` to read in from `STDIN`. Once I have the 9 integers in a character array I can loop through using `strtol`, *string to long* for those not familiar with it, to convert each integer to a *base10* integer. 

I pull the input into a 2-dimensional array (3x3) where the first value defines the *bin* and the second defines the color bottle in that bin. I've chosen to define the order of colors based on their input precedence; brown=0, green=1, clear=2. 

Once the input has been parsed I run through each of the 6 combinations and find the number of moves required to accomplish them. The moves total is placed into an array correlating to the specific combination. I then search through that list of moves and look for the smalled number and return the index ID of that move. This ID is used to correlate to a string array I built with all the combinations in alphabetical order so all I need to do is print the string at the index ID and the number of moves at the index ID. 

By doing things in this way I don't need to have my program know or care about sorting or alphabetizing the combinations because I've done that ahead of time. 

I'm learning as I work through these types of problems that you really must pay attention to the boundaries of the problem and know where you can interject your own brain power instead of making the program do it.

### Submission 1 - Wrong Answer!
So my initial submission was wrong and a quick search on the forums made me realize what I had missed. I was only expecting small numbers to be pulled into the program, specifically I was assuming everything was less than 100 which was just naive of me. The problem specifically says that it will be feeding integers as the input so that would be 10 digits per value and 10 spaces plus a `\n` newline and `\0` null terminator on the string pulled from `STDIN`. But to just make the numbers a nice round one and to allow for what the problem described as *any number of spaces* between each entry I increased my input buffer to 256 characters.

### Submission 2 - Accepted!
The input buffer increase did the trick, everything else works exactly as described in the problem.

### Conclusion
Overall this was a very simple problem that I was able to knock out in a couple hours of on and off work. I did spend a little time trying to work through the logic that would allow me to find the moves via a loop of some sort but quickly realized that it was much simpler to just brute force each combination since there where so few.  
