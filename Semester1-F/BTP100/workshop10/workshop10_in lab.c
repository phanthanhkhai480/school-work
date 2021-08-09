#include <stdio.h>
#include <string.h>
/* TODO: include the string library */

/* TODO: define constants for array sizes */
#define SIZE1 100
#define SIZE2 8

int main(void){
	int len;
	/* TODO: declare an input string that can hold up to 100 characters plus one terminating null character. Initialize to empty string */
	char input[SIZE1 + 1];

	/* TODO: declare a name string that can hold up to 8 characters plus one terminating null character. Initalize it to "default" */
	char name[SIZE2 + 1] = "default";

	printf("default name is: %s\n", name);

	printf("Enter a name 100 characters or less: ");
	/* TODO: read up to 100 characters or until the newline is encountered */
	scanf("%100[^\n]", input);
	len = strlen(input);
	/*TODO: change the condition to ensure that there is enough room in the name buffer to copy the input.*/
	if( len < 8 )
	{
		//TODO: copy the input string to the name string
		strcpy(name, input);
		printf("Name : %s\n", name);
	}
	else
	{
		printf("* No Room *\n");
		printf("Name : %s\n", name);
	}
	/*TODO: in the condition compare the name string with the literal string "default" to detemrine if it was successfully changed */
	if( strcmp(name, input) == 0 )
	{
		printf("name was successfully changed!\n");
	}else
	{
		printf("could not copy name, was too long!!\n");
	}
	/*TODO: display the input string */
	printf("input is  %s\n", input);

	/*TODO: display the name string */
	printf("name is %s\n", name);
	return 0;
}