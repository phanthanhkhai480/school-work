#include <stdio.h>
struct student_marks {
   int   id;
   float marks;
};

void welcome(void)
{
	printf("#######	Marks Analyzer V3.0 #######\n");
}

int get_data( struct student_marks *ptr )
{
	int value;
	printf("Enter students id and marks: ");
	scanf("%d 	%f",&ptr->id, &ptr->marks);
	printf("%d  %.2f\n", ptr->id, ptr->marks);
	if (ptr->id == -1 || ptr->marks == -1)
		value = 1;
	else
		value = 0;
	return value;
}

void show( struct student_marks list[], int num )
{
	for (int counter = 0; counter < num; counter++)
		printf("%d %d %.2f\n", counter+1, list[counter].id, list[counter].marks);
}
float analyze( struct student_marks list[], int num, float *ptr_highest, float *ptr_lowest)
{
	int sum = 0, counter = 0;
	for (counter = 0; counter < num; counter++)
	{
		if (list[counter].marks > *ptr_highest)
		{
			*ptr_highest = list[counter].marks;
		}
		if (list[counter].marks < *ptr_lowest)
		{
			*ptr_lowest = list[counter].marks;
		}
		sum = sum + list[counter].marks;
	}
	return sum;
}

void print_summary( float avg, float high, float low)
{
	printf("The average is %.2f\n", avg);
	printf("The highest marks is %.2f\n", high);
	printf("The lowest marks is %.2f\n", low);
	
}

int main(void){
	int size = 0, temp;
	float high = 0, low = 100, sum = 0, average;
	
    // declarations of a constant, an array and variables
	const int MAX = 100;
	struct student_marks students[MAX];
	struct student_marks student;
	
    // call a function to display a welcome message
	welcome();
	
	// 1. use a do-while loop to get student ids and student marks
	do
	{
	temp = get_data(&student);
	if (temp == 0)
	{
		students[size] = student;
		size++;
	}
	else
		break;
	}while(size != MAX || temp != 1);
	
	// 2. print out all the student marks
	show(students,size);
	
	// 3. data analysis
	sum = analyze(students, size, &high, &low);
	average = sum / size;
	
	// 4. print the result of data analysis
	print_summary(average, high, low);
	
    return 0;
}