	/* ">---===IPC Mark Analyser ===---<"	*/

#include<stdio.h>
int main(void)
{
	int number, marks, sum=0, counter=0, min=100, max=0;
	float average;
	printf("Please enter the number marks, must be between 3 and 40: ");
	scanf("%d", &number);	 
	while (number >= 3 && number <= 40)
	{	
		if (counter == number)
		break;
		while (counter < number)
			{
			printf("Please enter the marks: ");
			counter = counter + 1;
			scanf("%d", &marks);
			sum = sum + marks;
			printf("The total marks of the class is: %d\n", sum);
			if (marks > max)
				max = marks;
				printf("The maximum number is: %d", max);
			if (marks < min)
				min = marks;
				printf("The minimum number is: %d", min);
			}
	}
	if (number < 3 || number>40)
	{
		printf("Invalid, Please enter a numbet between 3 and 40 inclusive:\n ");
		return main();
	}
	else
	{
		average = sum / number;
		printf("The average marks in this class is: %.2f\n", average);
	}
		
	return 0;
}


