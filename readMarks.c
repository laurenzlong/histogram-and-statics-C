/* CISC 220 Assn 6: ReadMarks Function
Lauren Long, 8zl1
Fall 2012

Function: reads marks from standard input, store in an array
Input: array that marks will be stored in
Output: number of marks entered (max = 20)
*/

#include <stdio.h>
#include <stdlib.h>
#include "readMarks.h"

int readMarks (int marks[]){

	int result = 1;
	int mark;
	int counter = 0;

	while (result == 1 && counter<MAX){
		result = scanf("%d", &mark);
	
		if (result !=1 && result !=EOF){
			printf("Error: input is not an integer.\n");
			exit (1);
		}

		else {
			marks[counter] = mark;
			counter ++;	
		}
	}

	if (counter < 2){
		printf("Error: less than 2 marks entered.\n");
		exit (1);
	}

	return counter; // equal to number of marks entered
 
}
