/* CISC 220 Assn 6: Main Function
Lauren Long, 8zl1
Fall 2012

This program takes in a group of marks, calculates the average, 
standard deviation, min, and max. And then displays a histogram
that is organized in terms of letter grades. 
*/

#include <stdio.h>
#include "histogram.h"
#include "readMarks.h"
#include "statistics.h"

int main(){

	int marks[MAX];
	int size = readMarks (marks);

	float avg = calcAvg (marks, size);
	float stdev = calcStdev (marks, size, avg);
	int min = calcMin (marks, size);
	int max = calcMax (marks, size);

	//Print statistics
	printf ("number of marks: %d\n", size);
	printf ("average: %.2f\n", avg);
	printf ("standard deviation: %.2f\n", stdev);
	printf ("minimum: %d\n", min);
	printf ("maximum: %d\n", max);

	//Print histogram
	histogram(marks,size);

	return 0;
}
