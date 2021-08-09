#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/***************************************************************
Tester Function prototypes */

void searchTest();
void updateTest();
void addTest();
void addOrUpdateTest();
void adjustQtyTest();
/**************************************************************/

#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
/* btp_ms1*/
void welcome()
{
	printf("---=== Grocery Inventory System ===---\n");
	printf("\n");
}
void prnTitle()
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void prnFooter(double gTotal)
{
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0)
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
}
void clrKyb()
{
	while ( getchar() != '\n' );
}
void pause()
{
	printf("Press <ENTER> to continue...");
	clrKyb();
}
int getInt()
{
	char NL='x';
	int value = 0;
	while (NL != '\n')
	{
		scanf("%d%c", &value,&NL);
		if(NL != '\n')
		{
			clrKyb();
			printf("Invalid integer, please try again: ");
		}
	}
	return value;
}
double getDbl()
{
	char NL='x';
	double value = 0;
	while (NL != '\n')
	{
		scanf("%lf%c", &value,&NL);
		if(NL != '\n')
		{
			clrKyb();
			printf("Invalid number, please try again: ");
		}
	}
	return value;
}
int getIntLimited(int lowerLimit, int upperLimit)
{
	int value;
	do{
		value = getInt();
		if(value > upperLimit || value < lowerLimit)
		{
			printf("Invalid value, %d <= value <= %d: ", lowerLimit, upperLimit);
		}
	}while (value > upperLimit || value < lowerLimit);
	return value;
}	
double getDblLimited(double lowerLimit, double upperLimit)
{
	double value;
	do{
		value = getDbl();
		if(value > upperLimit || value < lowerLimit)
		{
			printf("Invalid value, %lf <= value <= %lf: ", lowerLimit, upperLimit);
		}
	}while (value > upperLimit || value < lowerLimit);	
	return value;
}
/* btp_ms2*/
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

struct Item {
   double price;
   int sku;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[21];
};


/* btp_ms3*/
double totalAfterTax(struct Item item)
{
	return item.quantity * item.price * (1+item.isTaxed * 0.13);	
}
int isLowQty(struct Item item)
{
	int value;
	if(item.quantity < item.minQuantity)
		value = 1;
	else 
		value = 0;
	return value;
}
struct Item itemEntry(int sku) {
   struct Item item;
   item.sku = sku;
   printf("        SKU: %d\n", item.sku);
   printf("       Name: ");
   scanf("%20[^\n]", item.name);
   clrKyb();
   printf("      Price: ");
   item.price = getDblLimited(0.01, 10000.00);
   printf("   Quantity: ");
   item.quantity = getIntLimited(1, MAX_QTY);
   printf("Minimum Qty: ");
   item.minQuantity = getIntLimited(0, 100);
   printf("   Is Taxed: ");
   item.isTaxed = yes();
   return item;
}

void dspItem(struct Item item, int linear)
{
	char taxed[4], low[4];
	
	if (item.isTaxed == 1) { strcpy(taxed, "Yes"); }
	else { strcpy(taxed, "No"); }
	if (linear == 1)
	{
		if (isLowQty(item) == 1) { strcpy(low, "***"); }
		else { strcpy(low, ""); }
		
		printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|%s\n",item.sku, item.name, item.price, taxed, item.quantity, item.minQuantity, totalAfterTax(item), low);
	}	
	else
	{
	printf("        SKU: %d\n", item.sku);
    printf("       Name: %s\n", item.name);
    printf("      Price: %.2lf\n", item.price);
    printf("   Quantity: %d\n", item.quantity);
    printf("Minimum Qty: %d\n", item.minQuantity);
    printf("   Is Taxed: %s\n", taxed);
	
	if (isLowQty(item) == 1)
		printf("WARNING: Quantity low, please order ASAP!!!\n");
	}
}
void listItems(const struct Item item[], int NoOfItems)
{
	int counter = 0;
	double gTotal = 0;
	prnTitle();
	for (counter = 0; counter < NoOfItems; counter++)
	{
		printf("%-4d", counter+1);
		printf("|%3d|%-20s|%8.2lf",item[counter].sku, item[counter].name, item[counter].price);
		if (item[counter].isTaxed == 1)
			{printf("|  Yes");} 
		else 
			{printf("|   No");}	
		printf("| %3d | %3d |%12.2lf|",item[counter].quantity, item[counter].minQuantity, item[counter].quantity * item[counter].price * (1+item[counter].isTaxed * 0.13));
		if (isLowQty(item[counter]) == 1)
			{printf("***\n"); }
		else
			{printf("\n"); }
		gTotal = gTotal + item[counter].quantity * item[counter].price * (1+item[counter].isTaxed * 0.13);
	}
	prnFooter(gTotal);
}
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int value, counter = 0;
	for(counter = 0; counter < NoOfRecs; counter++)
	{
		if (sku == item[counter].sku)
		{
			value = 1;
			*index = counter;
			counter = NoOfRecs;
		}
		else
			value = 0;
	}
	return value;
}

const double TAX = 0.13;

/* btp_ms4*/

void search(const struct Item item[], int NoOfRecs)
{
	int number, value = 0, counter;
	char taxed[4];
	printf("Please enter the SKU: ");
	scanf("%d", &number);
	value = locateItem(item, MAX_ITEM_NO, number,&counter);
	if(value == 1)
	{
		if (item[counter].isTaxed == 1) { strcpy(taxed, "Yes"); }
		else { strcpy(taxed, "No"); }
	
		printf("        SKU: %d\n", item[counter].sku);
		printf("       Name: %s\n", item[counter].name);
		printf("      Price: %.2lf\n", item[counter].price);
		printf("   Quantity: %d\n", item[counter].quantity);
		printf("Minimum Qty: %d\n", item[counter].minQuantity);
		printf("   Is Taxed: %s\n", taxed);
	}
	else
		printf("Item not found!\n");
}
void updateItem(struct Item* itemptr)
{
    struct Item u_item;
    int choice;
    printf("Enter new data:\n");
    u_item = itemEntry(itemptr->sku);
    printf("Overwrite old data? (Y)es/(N)o: ");
    choice = yes();
    if(choice == 1)
    {
        *itemptr = u_item;
        printf("--== Updated! ==--\n");
    }
    else
    {
        printf("--== Aborted! ==--\n");
    }
}
void addItem(struct Item item[], int *NoOfRecs, int sku)
{
	char add;
	if(*NoOfRecs == MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}
	else
	{
		itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		add = yes();
		if(add == 1)
		{
				printf("--== Added! ==--\n");
				*NoOfRecs = *NoOfRecs + 1;
		}	
		else
		{
			printf("--== Aborted! ==--\n");
		}
	}
}
void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	char select, taxed[4];
	int sku, value = 0, counter = 0;
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	for(counter = 0; counter < MAX_ITEM_NO; counter++)
	{
		if(sku == item[counter].sku)
		{
			if (item[counter].isTaxed == 1) { strcpy(taxed, "Yes"); }
			else { strcpy(taxed, "No"); }
			printf("        SKU: %d\n", item[counter].sku);
			printf("       Name: %s\n", item[counter].name);
			printf("      Price: %.2lf\n", item[counter].price);
			printf("   Quantity: %d\n", item[counter].quantity);
			printf("Minimum Qty: %d\n", item[counter].minQuantity);
			printf("   Is Taxed: %s\n", taxed);
			value = 1;
			break;
		}
	}
	if(value == 0)
		{
		addItem(item, NoOfRecs, sku);
		}
		if(value == 1)
		{
		printf("Item already exists, Update? (Y)es/(N)o: ");
		select = yes();
		if(select == 1)
		{
			updateItem(&item[counter]);
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}
	}
	
}
void adjustQty(struct Item item[], int NoOfRecs, int stock)
{
	int value, option, number, counter = 0, amount;
	char taxed[4], string[30];
	printf("Please enter the SKU: ");
	scanf("%d", &number);
	value = locateItem(item, MAX_ITEM_NO, number,&counter);
	if(value == 1)
	{
		if (item[counter].isTaxed == 1) 
		{ 
			strcpy(taxed, "Yes"); 
		}
		else 
		{ 
			strcpy(taxed, "No"); 
		}
		if(item[counter].quantity > item[counter].minQuantity)
		{
			strcpy(string, "to checkout");
			amount = item[counter].quantity;
		}
		else
		{
			strcpy(string, "to stock");
			amount = MAX_QTY;
		}
		printf("        SKU: %d\n", item[counter].sku);
		printf("       Name: %s\n", item[counter].name);
		printf("      Price: %.2lf\n", item[counter].price);
		printf("   Quantity: %d\n", item[counter].quantity);
		printf("Minimum Qty: %d\n", item[counter].minQuantity);
		printf("   Is Taxed: %s\n", taxed);
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", string, amount);
		scanf("%d", &option);
		if(option == 0)
		{
			printf("--== Aborted! ==--\n");
		}
		else
		{
			if(item[counter].quantity > item[counter].minQuantity)
			{
				item[counter].quantity = item[counter].quantity - option;
				printf("--== Checked out! ==--\n");
			}
			else
			{
				item[counter].quantity = item[counter].quantity + option;
				printf("--== Stocked! ==--\n");
			}
		}
		if(item[counter].quantity <= item[counter].minQuantity)
		{
			printf("Quantity is low, please reorder ASAP!!!\n");
		}	
	}
	else
		printf("SKU not found in storage\n");


}


struct Item GI[21] = {
   { 4.4,275,0,10,2,"Royal Gala Apples" },
   { 5.99,386,0,20,4,"Honeydew Melon" },
   { 3.99,240,0,30,5,"Blueberries" },
   { 10.56,916,0,20,3,"Seedless Grapes" },
   { 2.5,385,0,5,2,"Pomegranate" },
   { 0.44,495,0,100,30,"Banana" },
   { 0.5,316,0,123,10,"Kiwifruit" },
   { 4.49,355,1,20,5,"Chicken Alfredo" },
   { 5.49,846,1,3,5,"Veal Parmigiana" },
   { 5.29,359,1,40,5,"Beffsteak Pie" },
   { 4.79,127,1,30,3,"Curry Checken" },
   { 16.99,238,1,10,2,"Tide Detergent" },
   { 10.49,324,1,40,5,"Tide Liq. Pods" },
   { 10.99,491,1,50,5,"Tide Powder Det." },
   { 3.69,538,1,1,5,"Lays Chips S&V" },
   { 3.29,649,1,15,5,"Joe Org Chips" },
   { 1.79,731,1,100,10,"Allen's Apple Juice" },
   { 6.69,984,1,30,3,"Coke 12 Pack" },
   { 7.29,350,1,50,5,"Nestea 12 Pack" },
   { 6.49,835,1,20,2,"7up 12 pack" }
};
int GNoOfRecs = 20;


/*************************************************************
Main tester */
/*
int main() {
   //searchTest();
   updateTest();
   addTest();
   //addOrUpdateTest();
   //adjustQtyTest();
   return 0;
}
*/
/*End of main tester
******************************************************************/


/***************************************************************
Milestone 4 functions to be implemented */







/*End of Milestone 4 functions
******************************************************************/


/*****************************************************************
Milestone 3 function implementations:
Please copy your milestone 3 functions here: */






/*End of Milestone 3 functions.
*******************************************************************/


/***************************************************************
Tester Functions DO NOT MODIFY */

void searchTest() {
   printf("================Search Test:\n");
   printf("Enter 731: \n");
   search(GI, GNoOfRecs);
   printf("Enter 222: \n");
   search(GI, GNoOfRecs);
}
void updateTest() {
   struct Item I = { 11.11,111,1,11,1,"Ones!" };
   printf("================Update Test:\n");
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 111\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Overwrite old data? (Y)es/(N)o: n\n");
   updateItem(&I);
   printf("Unchanged Item Data:\n");
   dspItem(I, FORM);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 111\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Overwrite old data? (Y)es/(N)o: y\n");
   updateItem(&I);
   printf("Updated Item: \n");
   dspItem(I, FORM);
}
void addTest() {
   printf("================Add Test:\n");
   printf("Total items in Storage: %d, Max no: %d\n", GNoOfRecs, MAX_ITEM_NO);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 222\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Add Item? (Y)es/(N)o: n\n");
   addItem(GI, &GNoOfRecs, 222); //n
   printf("Garbage here! Nothing is added, No of items in storage: %d\n", GNoOfRecs);
   dspItem(GI[GNoOfRecs], FORM);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 222\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Add Item? (Y)es/(N)o: y\n");
   addItem(GI, &GNoOfRecs, 222); //y
   printf("New item is added, No of itemsinstorage: %d\n", GNoOfRecs);
   dspItem(GI[GNoOfRecs - 1], FORM);
   printf("Adding 333: \n");
   addItem(GI, &GNoOfRecs, 333);
}
void addOrUpdateTest() {
   GNoOfRecs = MAX_ITEM_NO;
   printf("================AddOrUpdate Test:\n");
   printf("Enter 731 and then \'n\':\n");
   addOrUpdateItem(GI, &GNoOfRecs); // n
   printf("Enter 731, \'y\' and then:\n"
      "       Name: Apple\n"
      "      Price: 1.80\n"
      "   Quantity: 101\n"
      "Minimum Qty: 11\n"
      "   Is Taxed: n\n"
      "Overwrite old data? (Y)es/(N)o: y\n");
   addOrUpdateItem(GI, &GNoOfRecs); // yes new data Yes
   printf("Updated Item: \n");
   dspItem(GI[16], FORM);
   printf("Enter 444: \n");
   addOrUpdateItem(GI, &GNoOfRecs); //n
}

void adjustQtyTest() {
   printf("================AdjustQty Test:\n");
   printf("Invalid SKU Test; Enter 444:\n");
   adjustQty(GI, GNoOfRecs, STOCK);
   printf("Aborting Entry test; Enter 731 and then 0:\n");
   adjustQty(GI, GNoOfRecs, CHECKOUT);
   printf("Checking out with low quantity warning; Enter 731 and then 90:\n");
   adjustQty(GI, GNoOfRecs, CHECKOUT);
   printf("Stocking; Enter 731 and then 50:\n");
   adjustQty(GI, GNoOfRecs, STOCK);
   dspItem(GI[16], FORM);
}

/* End test functions
********************************************************************* */