/* CISC 220 Assn 6: Histogram Function
Lauren Long, 8zl1
Fall 2012

Function: prints histogram, organized by letter grade range
Input: array of marks, size of array
Output: none
*/

#include <stdlib.h>
#include <stdio.h>

void histogram (int marks[], int size){
	
	//Keep count of how many marks belong in each range
	int numA =0;
	int numB =0;
	int numC =0;
	int numD =0;
	int numF =0;
	
	int i;

	for (i=0;i<size;i++){
		if (marks[i]<50)
			numF++;
		else if (marks[i]<60)
			numD++;
		else if (marks[i]<70)
			numC++;
		else if (marks[i]<80)
			numB++;
		else // marks[i]>80
			numA++;
	}

	// debug output: prints the number of marks in each range
	if (DEBUG ==1){
		printf("\n");
		printf("There are %d marks in the A range\n", numA);
		printf("There are %d marks in the B range\n", numB);
		printf("There are %d marks in the C range\n", numC);
		printf("There are %d marks in the D range\n", numD);
		printf("There are %d marks in the F range\n", numF);

	}

	//Find out the maximum column height required for the histogram
	int height = numA;
	if (numB>height)
		height=numB;
	if (numC>height)
		height=numC;
	if (numD>height)
		height=numD;
	if (numF>height)
		height=numF;

	//Draw out the histogram
	
	printf("\nGrade distribution:\n\n");
	
	while (height>0){
		printf("%d | ", height);
		
		// Prints F column
		if (numF >= height)
			printf("%2c", 'X');
		else
			printf("%2c", ' ');
		
		// Prints D column
		if (numD >= height)
			printf("%2c", 'X');
		else
			printf("%2c", ' ');

		// Prints C column
		if (numC >= height)
			printf("%2c", 'X');
		else
			printf("%2c", ' ');

		// Prints B column
		if (numB >= height)
			printf("%2c", 'X');
		else
			printf("%2c", ' ');

		// Prints A column
		if (numA >= height)
			printf("%2c", 'X');
		else
			printf("%2c", ' ');

		printf("\n");
		
		height--;

	}

	printf("    ----------\n");
	printf("    %2c%2c%2c%2c%2c\n",'F','D','C','B','A');

}
