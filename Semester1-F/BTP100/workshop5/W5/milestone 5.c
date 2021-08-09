#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define SIZE 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define MAX_ITEM_NO 500   
#define DATAFILE "items.txt" 

struct Item {
   double price;
   int sku;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[SIZE];
};




/********************************************************************
Milestones 1 to 4  prototypes, definitions and etc...*/







/*End of milestone 1 to 4 stuff
*********************************************************************/
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
	printf("Press <ENTER> to continue...\n");
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
/********************************************************************
Milestone 5 prototypes*/

void saveItem(struct Item item, FILE* dataFile)
{
	fprintf(dataFile,"%d,%.2d,%.d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}
int loadItem(struct Item* item, FILE* dataFile)
{
	int value = 0;
	
	if(fscanf(dataFile,"%d,%d,%d,%lf,%d,%20[^\n]\n", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name) == 6)
	{	
		printf("%d,%d,%d,%lf,%d,%s\n", item->sku, item->quantity, item->minQuantity, item->price, item->isTaxed, item->name);
		value = 1;
	}
	
	printf("value = %d\n", value);
	return value;
}

int saveItems(struct Item* item, char fileName[], int NoOfRecs)
{
	int value = 0, counter = 0;
	FILE *fp = NULL;
	fp = fopen(fileName, "w+");
	if(fp != NULL)
	{
		for(counter = 0; counter < NoOfRecs; counter++)
		{
			//fprintf(fp, "%d,%.2d,%.d,%.2lf,%d,%s\n", item->sku, item->quantity, item->minQuantity, item->price, item->isTaxed, item->name);
			saveItem(item[counter], fp);
		}
		value = 1;
	}
	fclose(fp);
	return value;
}

int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr)
{
	int value, counter = 0;
	FILE *fp = NULL;
	fp = fopen(fileName, "r");
	if(fp != NULL)
	{
		/*for(counter = 0; counter < *NoOfRecsPtr; counter++)
		{
			value = loadItem(&item[counter], fp);
		}*/
		
		while(loadItem(&item[counter],fp)){
			counter++;
		}
		
	}
	*NoOfRecsPtr = counter;
	printf("counter = %d\n", counter);
	fclose(fp);
	return 1;
}

/*End of milestone 5 prototypes
*********************************************************************/

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

void GrocInvSys()  									// ms2
{
	struct Item inventory[MAX_ITEM_NO];
	int SEL, DONE = 0, record, save1, save2, save3, max;
	
	welcome();
	record = loadItems(inventory, DATAFILE, &max);
	if(record == 0)
	{
		printf("Could not read from %s.\n", DATAFILE);
	}
		
	while (DONE == 0) {
		SEL = menu();
		switch (SEL)
		{
		case 1:
		{
			printf("List Items!\n");
			printf("max = %d\n", max);
			listItems(inventory, max);
			pause();
			break;
		}
		case 2:
		{
			printf("Search Items!\n");
			search(inventory, max);
			pause();
			break;
		}
		case 3:
		{
			printf("Checkout Item!\n");
			adjustQty(inventory, max, CHECKOUT);
			save1 = saveItems(inventory, DATAFILE, max);
			if(save1 == 0)
			{
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
			break;
		}
		case 4:
		{
			printf("Stock Item!\n");
			adjustQty(inventory, max, STOCK);
			save2 = saveItems(inventory, DATAFILE, max);
			if(save2 == 0)
			{
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
			break;
		}
		case 5:
		{
			printf("Add/Update Item!\n");
			addOrUpdateItem(inventory, &max);
			save3 = saveItems(inventory, DATAFILE, max);
			if(save3 == 0)
			{
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
			break;
		}
		case 6:
		{
			printf("Delete Item!\n");
			printf("Not implemented!\n");
			pause();
			break;
		}
		case 7:
		{
			printf("Search by name!\n");
			printf("Not implemented!\n");
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

/*
*************************************************************************
    TTTTTTTTT   EEEEEEEE   SSSSSSSS   TTTTTTTTTT   EEEEEEEEE   RRRRRRRR                                                      
       TT       EE         SS             TT       EE          RR     RR          
       TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RRRRRRRR
       TT       EE               SS       TT       EE          RR  RR
       TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RR    RR
***************************************************************************
Tester for saveItem, loadItem, saveItems and loadItems:
uncomment this to test your functions prior to putting all the code together by adding a * and / here:  
void prnFile() {
   FILE* tp = fopen("test.txt", "r");
   char ch;
   if (tp) {
      for (; fscanf(tp,"%c", &ch) == 1; putchar(ch));
      fclose(tp);
   }
   else {
      printf("text.txt not found\n");
   }
}

int main(void) {
   int i, n;
   struct Item GI[3] = {
      { 4.4,275,0,10,2,"Royal Gala Apples" },
      { 5.99,386,0,20,4,"Honeydew Melon" },
      { 3.99,240,0,30,5,"Blueberries" },
   };
   struct Item I;
   struct Item IN[3];
   printf("***********Testing saveItem:\n");
   printf("Your saveItem saved the following in test.txt: \n");
   FILE* tp = fopen("test.txt", "w");
   if (tp) {
      for (i = 0; i < 3; i++) saveItem(GI[i], tp);
      fclose(tp);
      prnFile();
   }
   printf("*******************************\nThey have to match the following:\n");
   printf("275,10,2,4.40,0,Royal Gala Apples\n");
   printf("386,20,4,5.99,0,Honeydew Melon\n");
   printf("240,30,5,3.99,0,Blueberries\n");
   printf("***********END Testing saveItem!\n\n\n");
   pause();
   printf("***********Testing loadItem:\n");
   printf("Your loadItem loaded the following from test.txt: \n");
   tp = fopen("test.txt", "r");
   if (tp) {
      for (i = 0; i < 3; i++) {
         loadItem(&I, tp);
         dspItem(I, LINEAR);
      }
      fclose(tp);
      tp = fopen("test.txt", "w");
      fclose(tp);
   }
   printf("*******************************\nThey have to match the following:\n");
   printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
   printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
   printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
   printf("***********END Testing loadItem!\n\n\n");
   pause();
   printf("***********Testing saveItems:\n");
   printf("Your saveItems saved the following in test.txt: \n");
   saveItems(GI, "test.txt", 3);
   prnFile();
   printf("*******************************\nThey have to match the following:\n");
   printf("275,10,2,4.40,0,Royal Gala Apples\n");
   printf("386,20,4,5.99,0,Honeydew Melon\n");
   printf("240,30,5,3.99,0,Blueberries\n");
   printf("***********END Testing saveItems!\n\n\n");
   pause();
   printf("***********Testing loadItems:\n");
   printf("Your loadItems loaded the following from test.txt: \n");
   loadItems(IN, "test.txt", &n);
   for (i = 0; i < n; i++) {
      dspItem(IN[i], LINEAR);
   }
   printf("*******************************\nThey have to match the following:\n");
   printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
   printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
   printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
   printf("***********END Testing loadItems!\n\n\n");
   pause();
   printf("Done!\n"); 
   return 0; 
} 
End MS5 functions' tester
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************


***************************************************************************
Main function to run the application
uncomment this to test your functions after putting all the code together by adding a * and / here: */
int main(void) {
GrocInvSys();
return 0;
}

/* End Main function
********************************************************************/





/********************************************************************
Milestone 5 functions*/

/*End of milestone 5 functions
*********************************************************************/

/********************************************************************
Milestones 1  to 4 functions*/



/*End of milestone 1 to 4 functions
*********************************************************************/








/* ms5 Tester output
***********Testing saveItem:
Your saveItem saved the following in test.txt:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
*******************************
They have to match the following:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
***********END Testing saveItem!
Press <ENTER> to continue...
***********Testing loadItem:
Your loadItem loaded the following from test.txt:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
*******************************
They have to match the following:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
***********END Testing loadItem!
Press <ENTER> to continue...
***********Testing saveItems:
Your saveItems saved the following in test.txt:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
*******************************
They have to match the following:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
***********END Testing saveItems!
Press <ENTER> to continue...
***********Testing loadItems:
Your loadItems loaded the following from test.txt:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
*******************************
They have to match the following:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
***********END Testing loadItems!
Press <ENTER> to continue...
Done!
*/ 