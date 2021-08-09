#include <stdio.h>
#include <string.h>
// define statements go here
#define LINEAR 1
#define FORM 0 
#define STOCK 1 
#define CHECKOUT 0 
/* ms1 prototypes*/
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
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
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
			printf("Invalid value, %.6f< value < %.6f: ", lowerLimit, upperLimit);
		}
	}while (value > upperLimit || value < lowerLimit);	
	return value;
}
/* ipc_ms2 prototype*/
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


/* ms3 prototypes*/

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
struct Item itemEntry(int sku)
{
	struct Item item;
	item.sku = sku;
	printf("        SKU: %d\n", item.sku);
	printf("       Name: ");
	scanf("%20[^\n]", item.name);
	clrKyb();
	printf("      Price: ");
	scanf("%lf", &item.price);
	printf("   Quantity: ");
	scanf("%d", &item.quantity);
	printf("Minimum Qty: ");
	scanf("%d", &item.minQuantity);
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
		}
		else
			value = 0;
	}
	return value;
}

/* Constant double TAX value */
const double TAX  = 0.13;




/*	int main() {
   struct Item I[21] = {
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
   double val;
   int ival;
   int searchIndex;
   val = totalAfterTax(I[0]);
   printf("totalAfterTax: yours=%lf, program's=44.000000\n", val);
   val = totalAfterTax(I[7]);
   printf("totalAfterTax: yours=%lf, program's=101.474000\n", val);
   ival = isLowQty(I[0]);
   printf("isLowQty: yours=%d, program's=0\n",ival);
   ival = isLowQty(I[14]);
   printf("isLowQty: yours=%d, program's=1\n",ival);
   pause();
   printf("itemEntry, enter the following values:\n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 50\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: n\n");
   printf("Enter the values:\n");
   I[20] = itemEntry(999);
   printf("dspItem, Linear:\nYours: ");
   dspItem(I[20], LINEAR);
   printf(" Prog: |999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|\n");
   printf("dspItem, Form:\nYours:\n");
   dspItem(I[20], FORM);
   printf("Programs: \n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 50\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: No\n");
   I[20].quantity = 2;
   I[20].isTaxed = 1;
   pause();
   printf("dspItem, Linear with low value and taxed:\nYours: ");
   dspItem(I[20], LINEAR);
   printf(" Prog: |999|Red Apples          |    4.54|  Yes|   2 |   5 |       10.26|***\n");
   printf("dspItem, Form with low value:\nYours:\n");
   dspItem(I[20], FORM);
   printf("Programs: \n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 2\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: Yes\n"
      "WARNING: Quantity low, please order ASAP!!!\n");
   pause();
   printf("Listing Items: \n");
   listItems(I, 21);
   pause();
   printf("Locate Item, successful search:\n");
   printf("program: Found the item 999 at index: 20\n");
   printf("  Yours: ");
   if (locateItem(I, 21, 999, &searchIndex)) {
      printf("Found the item 999 at index: %d\n", searchIndex);
   }
   else {
      printf("No item with the sku 999 is in the array!\n");
   }

   printf("Locae Item, unsuccessful search:\n");
   printf("Progam: No item with the sku 732 is in the array!\n");
   printf(" Yours: ");
   if (locateItem(I, 21, 732, &searchIndex)) {
      printf("Found the item at index: %d\n", searchIndex);
   }
   else {
      printf("No item with the sku 732 is in the array!\n");
   } 
   return 0;
} */



/*   item entry output 
        SKU: 999
       Name: Red Apples
      Price: 4.54
   Quantity: 50
Minimum Qty: 5
   Is Taxed: n
        SKU: 999
       Name: Red Apples
      Price: 4.54
   Quantity: 50
Minimum Qty: 5
   Is Taxed: No
WARNING: Quantity low, please order ASAP!!!
   
*/

/*  dspItems
|999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|
        SKU: 999
       Name: Red Apples
      Price: 4.54
   Quantity: 50
Minimum qty: 5
   Is Taxed: No
*/


/*ms1 and 2 functions: */
