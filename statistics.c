/* CISC 220 Assn 6: Statistics Functions
Lauren Long, 8zl1
Fall 2012
*/

#include <math.h> 
#include <stdlib.h>

float calcAvg (int marks [], int size){
/*
Function: calculates average mark
Input: array of marks, size of array
Output: average (float)
*/	
	int i;
	int sum =0;

	for (i=0;i<size;i++){
		sum = sum + marks[i];
	}
	
	float avg = (float)sum/size;
	return avg;	
}

float calcStdev (int marks [], int size, float avg){
/*
Function: calculates standard deviation
Input: array of marks, size of array, average mark
Output: standard deviation (float)
*/	
	float diff;
	float diffsq;
	float sumdiffsq =0;
	int i;
	
	for (i=0;i<size;i++) {
		diff = (float)(marks[i]-avg); 
		diffsq = diff*diff;
		sumdiffsq = sumdiffsq + diffsq;
	}
	
	float stdev = sqrt (sumdiffsq/(size-1));
	return stdev;
}

int calcMin (int marks [], int size){
/*
Function: calculates lowest mark
Input: array of marks, size of array
Output: lowest mark (int)
*/
	int min = marks[0];
	int i;
	
	for (i=1;i<size;i++){
		if (marks[i] < min)
			min = marks[i];
	}
	return min;
}

int calcMax (int marks [], int size){
/*
Function: calculates highest mark
Input: array of marks, size of array
Output: highest mark (int)
*/
	int max = marks[0];
	int i;
	
	for (i=1;i<size;i++){
		if (marks[i] > max)
			max = marks[i];
	}
	return max;
}
