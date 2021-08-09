#include <stdio.h>
void clrKyb(void);
void pause(void);
int getInt(void);
int yes(void);  // ms2
int getIntLimited(int lowerLimit, int upperLimit);
void welcome(void);
void GrocInvSys(void);  // ms2
int menu(void);  // ms2

/* int main(void) {
	GrocInvSys();
	return 0;
} */

// implmement MS2 fucntions here
int yes()  											// ms2
{
	char CH;
	int RET = 0;
	do
	{
		scanf(" %c", &CH);
		
		//CH = getchar();
		clrKyb();
		if ((CH == 'y' || CH == 'Y' || CH == 'n' || CH == 'N')) {
			if (CH == 'Y' || CH == 'y') {

				return RET = 1;
			}
			else {
				return RET;
			}
		}
		else {
			printf("Only (Y)es or (N)o are acceptable: ");
		}

	} while (CH != 'y' || CH != 'Y' || CH != 'n' || CH != 'N');

	return RET;
}
void GrocInvSys()  									// ms2
{
	int SEL, DONE = 0;
	welcome();
	while (DONE == 0) {
		SEL = menu();
		switch (SEL)
		{
		case 1:
		{
			printf("List Items!\n");
			pause();
			break;
		}
		case 2:
		{
			printf("Search Items!\n");
			pause();
			break;
		}
		case 3:
		{
			printf("Checkout Item!\n");
			pause();
			break;
		}
		case 4:
		{
			printf("Stock Item!\n");
			pause();
			break;
		}
		case 5:
		{
			printf("Add/Update Item!\n");
			pause();
			break;
		}
		case 6:
		{
			printf("Delete Item!\n");
			pause();
			break;
		}
		case 7:
		{
			printf("Search by name!\n");
			pause();
			break;
		}
		case 0:
		{
			printf("Exit the program? (Y)es/(N)o : ");
			DONE = yes();
		}
		}
	}
}

int menu()  										// ms2
{
	int option;
	printf("1- List all items\n2- Search by SKU\n3- Checkout an item\n4- Stock an item\n5- Add new item or update item\n6- delete item\n7- Search by name\n0- Exit program\n> ");
	do {
		scanf("%d", &option);
		if (option > 7 || option < 0) {
			printf("Invalid value, 0 < value < 7: ");
		}
	} while (option > 7 || option < 0);
	return option;
}

void welcome() {
	printf("---=== Grocery Inventory System ===---\n");
	printf("\n");
}
/* void prnTitle() {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
} */
/* void prnFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0)
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
} */
void clrKyb() {
	while (getchar() != '\n');
}
void pause() {
	printf("Press <ENTER> to continue...\n");
	clrKyb();
}
int getInt() {
	char NL = 'x';
	int value = 0;
	while (NL != '\n') {
		scanf("%d%c", &value, &NL);
		if (NL != '\n') {
			clrKyb();
			printf("Invalid integer, please try again: ");
		}
	}
	return value;
}
/* double getDbl() {
	char NL = 'x';
	double value = 0;
	while (NL != '\n') {
		scanf("%lf%c", &value, &NL);
		if (NL != '\n') {
			clrKyb();
			printf("Invalid number, please try again: ");
		}
	}
	return value;
} */
int getIntLimited(int lowerLimit, int upperLimit) {
	int value;
	do {
		value = getInt();
		if (value > upperLimit || value < lowerLimit) {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		}
	} while (value > upperLimit || value < lowerLimit);
	return value;
}
/* double getDblLimited(double lowerLimit, double upperLimit)
{
	double value;
	do {
		value = getDbl();
		if (value > upperLimit || value < lowerLimit) {
			printf("Invalid value, %.6f< value < %.6f: ", lowerLimit, upperLimit);
		}
	} while (value > upperLimit || value < lowerLimit);
	return value;
} */

