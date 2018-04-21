/* ENGGEN131, Semester Two, 2017 */

/* PROJECT SOLUTION BY:  << George Mcerlean, 518503739, gmce822 >> */

#include "project.h"

/* HELPER FUNCTIONS */
/* If you have defined any "helper" functions, which you call from the required */
/* functions, you should place them here, at the top of the source file.  This will */
/* make it easier for the markers to locate them.  You should also include a */
/* comment at the top of each of the "helper" functions you define which clearly */
/* describes their purpose, and which of the tasks they support. */

/*
The FindLocations function is used in task 5 "ConnectTwo". This function finds the location
of the starting location (1) and ending locations (2) in the maze.

Input:
maze, A two dimensional array containing the maze Data

Output:
locations, An array to store the locations of the values 1 and 2 in. Array values
0 and 1 represent the row and column number of 1 respectively and array values 2 and 3 
represent the row and column number of 2 respectively.

To solve this problem a for loop is used to look through the maze and when the
values 1 and 2 are found the co-ordinates of these points are stored in the Locations array.
*/
void FindLocations(int maze[10][10], int Locations[])
{
	int i, j;

	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			if (maze[i][j] == 1) {
				Locations[0] = i;
				Locations[1] = j;
			} else if (maze[i][j] == 2) {
				Locations[2] = i;
				Locations[3] = j;
			}
		}
	}
}

/*
The PrintDiagonals function is used in task 5 "ConnectTwo". This function finds the
locations of all the co-ordinates along the diagonal path between 1 and 2 and stores 
a 3 in the maze for all of these co-ordinates.

Inputs:
maze, A two dimensional array containing the maze data. The maze data is also 
edited to include the path of threes
Locations, The locations of 1 and 2, stored in an array where values 0 and 1 
represent the row and column number of 1 respectively and values 2 and 3 represent 
the row and column number of 2 respectively. The locations array values for the
starting location are changed to show the end of the path.

The first task in solving this problem was finding which direction the diagonal line 
will travel in using an if statement. Then use a while loop to store the diagonal 
line of 3's in the maze, starting at location 1, and moving in the direction found 
using the if statement until the function reaches the same row or column of the 
location 2. The final position is then stored in the Locations array, replacing the
row and column number of location 1.
*/
void PrintDiagonals(int maze[10][10], int Locations[4])
{
	int i = Locations[0];
	int j = Locations[1];

	if (Locations[0] < Locations[2] && Locations[1] < Locations[3]) {
		while (i+1 <= Locations[2] && j+1 <= Locations[3] && maze[i+1][j+1] == 0) {
			i++;
			j++;
			maze[i][j] = 3;
		}
	} else if (Locations[0] > Locations[2] && Locations[1] < Locations[3]) {
		while (i-1 >= Locations[2] && j+1 <= Locations[3] && maze[i-1][j+1] == 0) {
			i--;
			j++;
			maze[i][j] = 3;
		}
	} else if (Locations[0] < Locations[2] && Locations[1] > Locations[3]) {
		while (i+1 <= Locations[2] && j-1 >= Locations[3] && maze[i+1][j-1] == 0) {
			i++;
			j--;
			maze[i][j] = 3;
		}
	} else if (Locations[0] > Locations[2] && Locations[1] > Locations[3]) {
		while (i-1 >= Locations[2] && j-1 >= Locations[3] && maze[i-1][j-1] == 0) {
			i--;
			j--;
			maze[i][j] = 3;
		}
	}
	Locations[0] = i;
	Locations[1] = j;
}

/*
The FindMax function is used in task 9 "Histogram". This function calculates the 
largest value within the values array.

Inputs:
values, The array of integer we want the max from
numValue, the number of integers in the array

Output:
An integer representing the maximum value in the values array is returned.

This function solves this problem by first storing the first integer in the values
array into the temporary max variable. Then using a for loop to look through the 
values array and replace the temporary max variable with any value greater than
the current temporary max. The final value of temporary max is then returned as
the max value in the array.
*/
int FindMax(int *values, int numValues)
{
	int i = 0;
	int tempMax = values[i];

	for (i = 1; i < numValues; i++) {
		if (tempMax < values[i]) {
			tempMax = values[i];
		}
	}
	return tempMax;
}

/* REQUIRED FUNCTIONS */
/* Implement each of the required functions below.  The code that is provided initially */
/* for each function is incorrect - you should correct this! */

/*
The DivisorOfThree function calculates the greatest common divisor, the largest positive
integer which divides by all input integers without remainder. If any inputs are equal to
or less than 0 then the function should return -1.

Inputs:
a, b, c, The three integers we with to find the greatest common divisor of.

Output: 
An integer showing the greatest common divisor of the three inputs.

When solving this problem this function first checks no inputs are equal to or less than 
one using an if statement, if any are -1 is returned. The function then uses a for loop to
to check for a common divisor for all integers lower than the input, a, which get stored in 
the GCD variable. The greatest divisor is final value stored in the GCD variable.
*/
int DivisorOfThree(int a, int b, int c)
{
	int i;
	int GCD = 0;

	if (a <= 0 || b <= 0 || c <= 0) {
		return -1;
	}
	
	for (i = 1; i <= a; i++) {
		if (a%i == 0 && b%i == 0 && c%i == 0) {
			GCD = i;
		}
	}
	return GCD;
}

/*
The AverageSheep function calculates the average of all values in an array up to,
but excluding the value 9999. Any values equal to -1 in the array are ignored. If
there are no valid values the function should return 0.

Input:
counts, an array of numbers to be averaged, ending in 9999.

Output:
The average of all valid values in the counts array before 9999.

A while loop is used to solve this problem, cycling through the array until the value
9999 is reached. For each cycle the array value is checked to be -1, if it is the
value is ignored, if it isn't the countnum value representing the number of values
added is increased by one and the total is increased by the corresponding value in the
counts array. Then finally the average is returned by dividing the total by the countnum,
if the countnum is 0 then to avoid dividing by 0 an if statement is used to return 0 
instead.
*/
double AverageSheep(int *counts)
{
	int i = 0;
	double total = 0;
	double countnum = 0;

	while (counts[i] != 9999) {
		if (counts[i] == -1) {
			i++;
		} else {
			countnum = countnum + 1;
			total = total + counts[i];
			i++;
		}
	}

	if (countnum == 0) {
		return 0;
	} else {
		return total / countnum;
	}
}

/*
The Emphasise function takes a string with two underscores and capitalizes the 
characters between the underscores. These underscores are removed, shortening
the string. If a character is already a capital nothing happens to it.

Input:
word, A string containing two underscores which we want to emphasise. This is also the 
output string we wish to change.

To solve this problem three while loops are used. The first loop finds the position
of the first underscore in the array. The second while loop removes the first
underscore, writing over it by moving all characters between the underscores one place 
to the left while capitalising all lowercase letters between the underscores using 
an if statement. Before the second underscore can be copied the second loop breaks and 
the third loop starts, replacing the second underscore and moving all the characters 
after the second underscore back by two to make up for the missing underscores, stopping 
after the "\0" has been moved.
*/
void Emphasise(char* word)
{
	int i = 0;

	while (word[i] != '_') {
		i++;
	}

	while (word[i + 1] != '_') {
		word[i] = word[i + 1];
		if ((word[i] >= 'a') && (word[i] <= 'z')) {
			word[i] = word[i] - 32;
		}
		i++;
	}

	while (word[i + 1] != '\0') {
		word[i] = word[i + 2];
		i++;
	}
}

/*
The PrimeFactors function calculates the prime factors of a positive integer and returns
the number of prime factors the integer has. Prime factors are the prime numbers that 
divide the integer exactly. If the input is a prime number the function should return 1.

Inputs:
n, The integer we wish to find the prime factors of
factors, an array to store the prime factors in, in increasing order.

Output:
The number of prime factors the input has

To solve this problem a while loop inside a for loop is used. The for loop cycles
through all possible factors of the input, starting with 2. The while loop is used 
to find which possible factors work and this loop continues till that factor no longer 
works, adding the factor to the factors array each time as well as dividing the tempNum 
integer by the factor to ensure the loop will break and incrementing the position in the 
array the factor should be stored. The final position + 1 is then returned to represent 
the number of prime factors.
*/
int PrimeFactors(int n, int *factors)
{
	int i;
	int tempNum = n;
	int ArrayNum = 0;
	
	for (i = 2; i <= n; i++) {
		while (tempNum%i == 0) {
			factors[ArrayNum] = i;
			ArrayNum = ArrayNum + 1;
			tempNum = tempNum/i;
		}
	}
	return ArrayNum;
}

/*
The ConnectTwo function finds the shortest path between a starting and finishing
location in a 10x10 array labelled 1 and 2 respectively. This function also modifies
the array by setting each element on the path to 3, While leaving the starting and
finishing location unchanged.

Input:
maze, a 10 by 10 array containing a starting (1) and ending (2) location for
the path we need to find, where the rest of the elements are 0. This is also where
the output path should be stored.

To solve this problem the function first initialises a Locations array and uses the
FindLocations helper function to find the starting and finishing locations. I then 
checked to see whether a diagonal line is required and used the PrintDiagonals helper
function if one is. I then found the direction of the final straight line by comparing
the starting location of the final line, this value is the starting location (1) if no
diagonal line was required, with the final location (2). I then used a for loop to print 
the final straight line based on the direction found.
*/
void ConnectTwo(int maze[10][10])
{
	int Locations[4] = {0,0,0,0};
	FindLocations(maze, Locations);
	int i;

	if (Locations[0] != Locations[2] && Locations[1] != Locations[3]) {
		PrintDiagonals(maze, Locations);
	}

	if (Locations[1] == Locations[3]) {
		if (Locations[0] < Locations[2]) {
			for (i = Locations[0] + 1; i < Locations[2]; i++) {
				maze[i][Locations[1]] = 3;
			}
		} else if (Locations[0] > Locations[2]) {
			for (i = Locations[0] - 1; i > Locations[2]; i--) {
				maze[i][Locations[1]] = 3;
			}
		}
	} else if (Locations[0] == Locations[2]) {
		if (Locations[1] < Locations[3]) {
			for (i = Locations[1] + 1; i < Locations[3]; i++) {
				maze[Locations[0]][i] = 3;
			}
		} else if (Locations[1] > Locations[3]) {
			for (i = Locations[1] - 1; i > Locations[3]; i--) {
				maze[Locations[0]][i] = 3;
			}
		}
	}
}

/*
The DayTrader function finds the longest run of increasing integers in an array of
values. The length of the run does not include the value the run began with. For
example 4 1 2 3 2 would have a longest run of 2 (2 3). This function should return
the length and starting index of the longest run. If there are two runs of the same
length the run with the smallest index position is returned.

Inputs:
prices, An array of prices we need to find the longest run from.
numPrices, The number of values in our prices array.

Outputs:
bestRun, An integer pointer which is used to store the length of the best run
bestRunIndex, an integer pointer used to store the index position of the start of the
run

To solve this problem I first initailised a Runlengths array representing the lengths 
of each run from a starting position equal to its index in the array. I then, using a 
for loop, stored zeros in all position we will be using to avoid garbage values. I
then used a while loop nested in a for loop to find the run length of each starting
index in the prices array. The for loop goes through each starting position in the
prices array and the while loop uses a counter to find the length of each run 
checking each cycle if the next value is greater than the last and that it hasn't
reached the end. When the while loop breaks the run length of the index is stored
and the counter begins again. The length and index of the first run are then stored 
in the output values and a for loop is used to cycle through all the run lengths for 
each index starting position to find and store the best run and index.
*/
void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex)
{
	int i,j;
	int temp;
	int RunLengths[MAX_ARRAY_SIZE];
	int RunTemp;

	for (i = 0; i < numPrices; i++) {
		RunLengths[i] = 0;
	}

	for (i = 0; i < numPrices; i++) {
		temp = prices[i];
		j = i;
		RunTemp = 0;
		while (prices[j+1] > temp && j < numPrices - 1) {
			temp = prices[j+1];
			RunTemp = RunTemp + 1;
			j++;
		}
		RunLengths[i] = RunTemp;
	}

	*bestRun = RunLengths[0];
	*bestRunIndex = 0;

	for (i = 1; i < numPrices; i++) {
		if (RunLengths[i] > *bestRun) {
			*bestRun = RunLengths[i];
			*bestRunIndex = i;
		}
	}
}

/*
The Compress function is used to compress an input array by replacing consecutive values
with two values, the number of repititions and the value itself. If there is 1 number by
itself it will return 1 n where 1 is the number of repititions and n is the number itself.
Both the input and output data end is signalled with a value of -1.

Input:
input, An array of positive integers to be compressed

Output:
output, An array to store the compressed data in.

To Solve this function I used a while loop to go through all the relevant data with a counter
increasing by 1 every time it loops through. An if statement inside the while loop is used to
to check if the next value in the input array is the same as the curent one. If it isnt the
number in the counter is used to store the number of repetitions, then the input value is stored
to give the number that was repeated. The count is returned to zero and a variable called outputIndex 
is then increased by two to move past the two values just put in the output array. When the loop is 
finished the value -1 is put at the end of the compressed data.
*/
void Compress(int *input, int *output)
{
	int i = 0;
	int count = 0;
	int outputIndex = 0;

	while (input[i] != -1) {
		count = count + 1;
		if (input[i+1] != input [i]) {
			output[outputIndex] = count;
			output[outputIndex + 1] = input[i];
			count = 0;
			outputIndex = outputIndex + 2;
		}
		i++;
	}
	output[outputIndex] = -1;
}

/*
The AddOne function takes a positive integer represented as a string and increases its value 
by 1. If the string integer is made up solely of 9's the length of the string is increased 
to allow it to fit the new number. This is useful for large numbers which would cause an
integer overflow.

Input:
input, a string representing a number

Output:
output, a string representing a number one larger than the input.

To solve this I first used the strlen and strcpy functions to copy the input string to the
output and to get the length of the string. Then a while loop is used which loops through
all consecutive 9's for the input string, starting from the smallest place value (ones) and 
replacing them with the value 0. This loop also changes the value of i which is used in the
next if statement. If the value of i is -1 which means all values in the string were 9, the
first number in the output string is changed to 1 and a 0 and \0 are added to the end of the 
output string. If i is not -1 the value at index i is increased by one.
*/
void AddOne(char *input, char *output)
{
	int length = strlen(input);
	int i = length - 1;
	strcpy(output, input);

	while (output[i] == '9' && i >= 0) {
		output[i] = '0';
		i--;
	}

	if (i == -1) {
		output[0] = '1';
		output[length] = '0';
		output[length + 1] = '\0';
	} else {
		output[i] = output[i] + 1;
	}
}

/*
The Histogram function takes an array of integers representing data and generates a string
representing a histogram of the data. This histogram also has a border of *'s.

Inputs:
values, an array of integers to be plotted.
numValues, the number of elements in the value array.

Outputs:
result, a string to store the histogram in.

The function starts by creating an array to store the results in and setting all values in
the array to zero to avoid garbage values. The function then uses two nested for loops to 
store the *'s, X's and spaces in the appropriate elements. This results array is then put
into the output string using two nested for loops adding a \n at the end of every line 
except the last where a \0 is entered.
*/
void Histogram(char *result, int *values, int numValues)
{
	int i,j;
	int height = FindMax(values, numValues);
	char ResultArray[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

	for (i = 0; i < MAX_ARRAY_SIZE; i++) {
		for (j = 0; j < MAX_ARRAY_SIZE; j++) {
			ResultArray[i][j] = '0';
		}
	}
	
	for (i = 0; i <= height + 1; i++) {
		for (j = 0; j <= numValues + 1; j++) {
			if (i == 0 || i == height + 1 || j == 0 || j == numValues + 1) {
				ResultArray[i][j] = '*';
			} else if (values[j - 1] > (height) - i) {
				ResultArray[i][j] = 'X';
			} else {
				ResultArray[i][j] = ' ';
			}
		}
	}
	
	for (i = 0; i <= height + 1; i++) {
		for (j = 0; j <= numValues + 2; j++) {
			if (j == numValues + 2 && i == height + 1) {
				result[i*(numValues + 2) + i + j] = '\0';
			} else if (j == numValues + 2) {
				result[i*(numValues + 2) + i + j] = '\n';
			} else {
				result[i*(numValues + 2) + i + j] = ResultArray[i][j];
			} 
		}
	}
}

/*
The GoldRush function takes a 2D array or map representing the locations of minerals 
where 9 is gold. Pure Gold is when a cell contains gold and all 8 adjacent cells also 
contain gold. This function finds the amount of both gold and pure gold on a give map.

Inputs:
rows, an integer representing the number of rows on the map.
cols, an integer representing the number of columns on the map.
map, a two dimensional array of integers which contains the map data.
bonus, only used for bonus tasks.

Output
results, one dimensional array of integers in which the amount of gold (results[0])
and pure gold (results[1]) is stored.

To solve this problem the function first creates an array to store all the locations
of gold and then sets all relevant values in the array to 0 using a for loop. the first 
row represents the row number of the location and the second row represents the 
corresponding column number of the location. Two nested for loops and an if statement
are then used to find each location of the gold. Each time a piece of gold is found
its location is stored and the amount of gold increases by one. A for loop is then used,
checking all the the gold locations in the array. If it is on the edge the location is 
ignored, if it isn't it is then checked to see if all adjacent elements are also gold.
If they are one is added to the pure gold counter.
*/
void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus)
{	
	int i,j;
	int GLoc[2][MAX_MAP_SIZE*MAX_MAP_SIZE]; /* Gold Location */
	results[0] = 0;
	results[1] = 0;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < rows*cols; j++) {
			GLoc[i][j] = 0;
		}
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (map[i][j] == 9) {
			GLoc[0][results[0]] = i;
			GLoc[1][results[0]] = j;
			results[0] = results[0] + 1;
			}
		}
	}

	for (i = 0; i < results[0]; i++) {
		if (GLoc[0][i] != 0 || GLoc[0][i] != rows - 1 || GLoc[1][i] != 0 || GLoc[1][i] != cols - 1) {
			if (map[GLoc[0][i] - 1][GLoc[1][i] + 1] == 9 && map[GLoc[0][i] - 1][GLoc[1][i]]
				 == 9 && map[GLoc[0][i] - 1][GLoc[1][i] - 1] == 9) {
				if (map[GLoc[0][i]][GLoc[1][i] + 1] == 9 && map[GLoc[0][i]][GLoc[1][i] - 1] == 9) {
					if (map[GLoc[0][i] + 1][GLoc[1][i] + 1] == 9 && map[GLoc[0][i] + 1][GLoc[1][i]]
						 == 9 && map[GLoc[0][i] + 1][GLoc[1][i] - 1] == 9) {
						results[1] = results[1] + 1;
					}
				}
			}
		}
	}
	/* Removes compiler warning */
	if (bonus == 0) {
	}
}

