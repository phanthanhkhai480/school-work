#include<stdio.h>
int main()
{
	int number, grades, sum =0, counter = number, total;
	float average;
	printf("Please enter the number of grades: ");
	scanf("%d",&number);
	printf("Please enter the grades: ");
	scanf("%d", &grades);
	while(counter<number);
	{
		printf("Please enter an grades: ");
		scanf("%d", &grades);	
		sum = sum+grades;
		printf("Total grades: %d", total);

	}
	average = sum / number;
	printf("Average grades in class:%f.2", average);
	return 0;
}
