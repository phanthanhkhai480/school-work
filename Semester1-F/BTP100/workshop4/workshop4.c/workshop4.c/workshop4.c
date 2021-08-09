#include<stdio.h>
#define SIZE 40
int main()
{
	int number, counter = 0, sum=0, min = 100, max = 0;
	float average;
	long student_number[SIZE];  
	int marks[SIZE];
	int validStudentNumber = 1;
	int validMarks = 1;  

	printf("/*---===IPC Marks Analyser v2.0===---*/\n");
	printf(">Please enter the number of student between 3 and 40:< ");
	do {
		scanf("%d", &number);
		if (number < 3 || number>40)
			printf("Invalid, Please enter a number between 3 and 40 inclusive: ");
	} while (number < 3 || number > 40);
	printf(">Row StudentNumber Marks<\n");
	while (counter < number)
	{
		do
		{
			validStudentNumber= 1;
			validMarks= 1;
			printf("    --------- ---\r%3d ", counter + 1);
			scanf("%ld %d", &student_number[counter], &marks[counter]);
			if (student_number[counter] < 100000000 || student_number[counter] > 999999999)
			{
				printf("Error, Enter Student Number between 100000000 and 999999999 inclusive:\n ");
				validStudentNumber = 0;
			}
			if (marks[counter] < 0 || marks[counter] >100)
			{
				printf("Error, Enter Marks between 0 and 100 inclusive:\n ");
				validMarks = 0;
			}	
			if (marks[counter] > max)
				max = marks[counter];
			if (marks[counter] < min)
				min = marks[counter];
			sum = sum + marks[counter];
		}
		while (validStudentNumber == 0 || validMarks == 0);	 
			counter = counter + 1;
	}
		printf("=================\n Marks entered, Printing results\n >Row StudentNumber Marks<\n");
	for (counter = 0; counter < number; counter++)
		printf("%03d %09ld %03d\n", counter, student_number[counter], marks[counter]);
	printf("=================\n");
	printf("The maximum number is: %d\n The minimum number is: %d\n", max, min);
	average = sum / number; 
	printf("The total marks is: %d\n The average marks in this class is: %.1f\n Program Ended\n", sum, average);
	return 0;
}