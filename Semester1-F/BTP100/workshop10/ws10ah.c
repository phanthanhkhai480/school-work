#include <stdio.h>
#include <string.h>


int main(void){
        int length, counter = 0;
        char name[9] = "default";
        char backup[9];
        char string[9];
        char pass[9];

        printf("Password Game\n");
        printf("=============\n");
        printf("Enter your name (up to 8 chararcters): ");
        scanf("%8[^\n]", name);
        length = strlen(name);
        strcpy(backup,name);
        strcpy(pass,name);
        for(counter = 0; counter < length; counter++ )
		{
            pass[counter]--;
        }
        printf("WELCOME %s\n",name);
        while(length > 0)
		{
			printf("Guess the password (up to 8 characters) %s: ", name);
			scanf("%s",string);
                if( strcmp(string, pass) == 0)
				{
                    printf("You got it, %s!!!\n", backup);
                    length = 0;
                }
                else
				{
                    length--;
                    name[length] = '\0';
                    printf("FALSE: ");
                    if(length <= 0)
					{
                        printf("Thou has failed.\n");
                    }
                }

        }
        printf("Game Over!\n");

	return 0;
}