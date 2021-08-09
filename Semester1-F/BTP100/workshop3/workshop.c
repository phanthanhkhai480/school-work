>---===IPC Mark Analyser ===---<
#include<stdio.h>
int main(void)
{
	int number, marks, sum=0, counter = number;
	float average;
	printf("Please enter the number marks, must be between 3 and 40: ");
	scanf("%d", &number);
	while (number<3 && number>40);
	{
		printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		scanf("%d", &number);
		while (counter < number);
		{	printf("Please enter the marks: ");
			scanf("%d", &marks);
			sum = sum + marks;	
		}
		printf("The total marks of the class is: %d", &sum);
	}
	average = sum / number;
	printf("The average marks in this class is: %f.2", &average);

	return 0;
}