// Workshop 9 - Files

// Name: Khai Phan
// Student #: 100901164

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 

struct Box{
	int id;			// the box ID
	double size[3];	// dimensions of the box (Length, Width, Height)
	double weight;	// weight of the box
};

void listBoxes(const char filename[]) 	// lists all boxes in the file
{
	int id;
	double length, width, height, weight;
	FILE *fp = NULL;
	fp = fopen("storage.txt","r");
	if (fp != NULL)
	{
		while(fscanf(fp, "%d %lf %lf %lf %lf\n", &id, &length, &width, &height, &weight) != EOF)
		{
            printf("%2d	%6.2lf	%5.2lf	%6.2lf	%6.2lf\n",id, length, width, height, weight);
		}
		fclose(fp);
	}
	else
		printf("Failed to open file!!");
}	


void printBox(struct Box b);			// print one box- already implemented for you


int searchBox(FILE *fp, int id2Find) // returns the record number of a box with specified ID, if found  
{
	int value = -1, number, id, counter=0;
	double length, width, height, weight;	
	if (fp != NULL)
	{
		rewind(fp);
		while (fscanf(fp, "%d %lf %lf %lf %lf\n", &id, &length, &width, &height, &weight) != EOF) {
			counter++;
			if (id2Find == id) {
				value = counter;
			}

		}
	}
	return value;
}


void displayBox(const char filename[], int id2Find)		// display a box, given ID
{
	int id, value, counter=0;
	double size, weight;
	struct Box box;
	FILE *fp = NULL;
	fp = fopen("storage.txt","r");
	if (fp != NULL)
	{
		value = searchBox(fp, id2Find);
		if(value != -1)
		{
			rewind(fp);
			while (fscanf(fp, "%d %lf %lf %lf %lf\n", &box.id, &box.size[0], &box.size[1], &box.size[2], &box.weight) != EOF) {
				counter++;
				if (value == counter)
				{
					printf("Found box %d as record %d", box.id, counter);
					printBox(box);
				}
			}
		}
		else
		{
			printf("This box is not recorded.\n");
		}
	}
	else
	{	
		printf("Failed to open file!!");
	}
	fclose(fp);
	
}
int addBox(const char filename[], const struct Box *b2Add)	// add a box to file
{
	int id, value;
	double length, width, height, weight;

	FILE *fp = NULL;
	fp = fopen("storage.txt","a+");
	if (fp != NULL)
	{
		value = searchBox(fp, b2Add->id);
		if(value == -1)
		{
			fprintf(fp, "%d %.2lf %.2lf %.2lf %.2lf\n", b2Add->id, b2Add->size[0], b2Add->size[1], b2Add->size[2], b2Add->weight);
			printf("1 box added to the storage\n");
		}
		else
		{
			value = 0;
		}
	}
	else
		printf("Failed to open file!!");
	fclose(fp);
	return value;
}

int numberBoxes(const char filename[])		// find the number of boxes in a file
{
	int counter = 0;
	struct Box box;
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL)
		while (fscanf(fp, "%d %lf %lf %lf %lf\n", &box.id, &box.size[0], &box.size[1], &box.size[2], &box.weight) != EOF) {
			counter++;
		}
	return counter;
}
int getRandomInt(int lower, int higher)		// get a random number
{
	int result = 0;
	time_t t;
	srand((unsigned)time(&t));

	result = rand() % higher + lower;
	return result;
}
void displayBoxN(char filename[], int n)	// display a box given its record number
{
	int id, counter = 0;
	double length, width, height, weight;
	struct Box box;
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL)
	{
		while (fscanf(fp, "%d %lf %lf %lf %lf\n", &box.id, &box.size[0], &box.size[1], &box.size[2], &box.weight) != EOF) {
			counter++;
		if (n == counter)
		{
			printBox(box);
		}
		}
	}
	else
		printf("Failed to open file!!");
	fclose(fp);
}

void printBox(struct Box b){
	printf("\nID:     %6d\n"
		"Length: %6.2lf\n"
		"Width:  %6.2lf\n"
		"Height: %6.2lf\n"
		"Weight: %6.2lf\n\n", b.id, b.size[0], b.size[1], b.size[2], b.weight);
}

int menu(void){
	int choice = -1;

	printf("1- List all boxes\n");
	printf("2- Find a box\n");
	printf("3- Add a box\n");
	printf("4- Randomly pick a lucky box!\n");
	printf("0- Exit program\n");

	printf("Select an option: ");
	do{
		scanf("%d", &choice);
		if (choice < 0 || choice > 4)
			printf("Please enter a number between 0 and 4: ");
	} while (choice < 0 || choice > 4);
	return choice;
}


int main(void) {

	int choice, id, random, max;
	double length, width, height, weight;
	char filename[] = "storage.txt";
	struct Box b;


	printf("Welcome to My Storage Room\n");
	printf("==========================\n");
	do {
		// get user's choice
		choice = menu();


		switch (choice) {
		case 1:
		{
			// IN_LAB: list items
			printf("List of Boxes\n");
			printf("=============\n");
			printf("\nID	Length	Width	Height	Weight\n");
			printf("-----------------------------\n");
			listBoxes(filename);
			break;
		}


		case 2:
		{
			// IN_LAB: find a box given its ID
			// ask for ID
			printf("Enter box ID: ");
			scanf("%d", &id);
			// call displayBox
			displayBox(filename, id);
			break;
		}


		case 3:
		{
			// AT_HOME: add a box
			// get user input for box's ID, size and weight
			printf("Please enter the box's ID, length, width, height and weight: ");
			scanf("%d %lf %lf %lf %lf", &b.id, &b.size[0], &b.size[1], &b.size[2], &b.weight);
			// call addBox, print message to show number of boxes added
			if (addBox(filename, &b) == 0)
			{
				printf("A box with this ID is already recorded\n 0 box added to storage!\n");
			}
			break;
		}

		case 4:
		{
			// AT_HOME: randomly pick a lucky box
			// choose a random number between 1 and the number of boxes in storage
			max = numberBoxes(filename);
			random = getRandomInt(0, max);
			// display the lucky box!
			printf("Lucky box picked: \n");
			displayBoxN(filename, random);
			break;
		}
		}

		} while (choice > 0);

		return 0;
	}

/*
Welcome to My Storage Room
==========================
1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 1
List of boxes
=============

ID Length Width Height Weight
-----------------------------
10  50.34 61.00  30.00  50.50
11  25.60 12.34   9.23  12.89
55  10.00 20.00  30.00  40.50
56  30.00 40.00  50.00  60.00
57   5.20  6.30   7.40   8.50

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 2
Enter box ID: 55
Found box 55 as record #3:

ID:         55
Length:  10.00
Width:   20.00
Height:  30.00
Weight:  40.50

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 2
Enter box ID: 15
This box is not recorded.

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 0
*/