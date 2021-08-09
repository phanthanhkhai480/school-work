#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define SIZE 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define MAX_ITEM_NO 500   
#define DATAFILE "btp_ms5_long.txt" 

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
		if(item[counter].quantity < item[counter].minQuantity)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
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
	struct Item items;
	char add;
	if(*NoOfRecs == MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}
	else
	{
		clrKyb();
		items = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		add = yes();
		if(add == 1)
		{
				item[*NoOfRecs] = items;
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
			if(item[counter].quantity < item[counter].minQuantity)
			{
				printf("WARNING: Quantity low, please order ASAP!!!\n");
			}
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
void adjustQty(struct Item item[], int NoOfRecs, int stock){
        int tsku, found , i, increase, input;
        char sy[20]="to stock", cy[20]="to checkout";
        printf("Please enter the SKU: ");
        tsku = getIntLimited(SKU_MIN, SKU_MAX);
        found = locateItem(item, NoOfRecs, tsku, &i);
                if(found == 0){
                        printf("SKU not found in storage!\n");
                }
                else if(found == 1){
                        dspItem(item[i], FORM);
                if(stock == STOCK){
                        increase = MAX_QTY - item[i].quantity;
						printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ",sy, increase);
                        input = getIntLimited(0, increase);
                                if(input == 0){
                                   printf("--== Aborted! ==--\n");
                                }
                                else if(input != 0){
                                    item[i].quantity = item[i].quantity +  input;
                                    printf("--== Stocked! ==--\n");
                                }
                }
                if(stock == CHECKOUT){
                   printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", cy, item[i].quantity);
                        input = getIntLimited(0 , item[i].quantity);
                        if(input == 0){
                                printf("--== Aborted! ==--\n");
                        }
                        else if(input != 0){
                                item[i].quantity -= /*item[i].quantity -*/ input;
                                printf("--== Checked out! ==--\n");
						if(item[i].quantity <= item[i].minQuantity){
                                printf("Quantity is low, please reorder ASAP!!!\n");
                               }
                        }
                  }
}
}

/*btp_ms5*/

void saveItem(struct Item item, FILE* dataFile)
{
	fprintf(dataFile,"%d,%.2d,%.d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}
int loadItem(struct Item* item, FILE* dataFile){
        int value = 0;
        if(fscanf(dataFile, "%d,%d,%d,%lf,%d,%[^\n]", &item->sku,&item->quantity, &item->minQuantity,&item->price,&item->isTaxed, item->name) == 6){
        value=1;
        }
        return value;
}

int saveItems(struct Item* item, char fileName[], int NoOfRecs)
{
	int  i, exit=0;
    FILE *fp = NULL;

        fp = fopen(fileName, "w+");
        if(fp != NULL){
                for(i=0; i < NoOfRecs; i++)
				{
                    saveItem(item[i], fp);
                }
		fclose(fp);
                exit++;
        }
        return exit;
}

int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr)
{
	
    int counter = 0, value = 0;
	FILE *fp=NULL;
    fp = fopen(fileName,"r");
        if(fp != NULL){
        value = 1;
           while(loadItem(&item[counter],fp))
		   {
				counter++;
		   }
	 *NoOfRecsPtr = counter;
        fclose(fp);
        }
        return value;
}

/*btp_ms6*/

//ms6

void deleteItem(struct Item* item, int* NoOfRecs)
{
	int record, value = 0, sku, counter = 0, select;
	char taxed[4];
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	for(counter = 0; counter < *NoOfRecs; counter++)
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
			if(item[counter].quantity < item[counter].minQuantity)
			{
				printf("WARNING: Quantity low, please order ASAP!!!\n");
			}
			record = counter;
			value = 1;	//found
			break;
		}
	}
	if(value == 0)
	{
		printf("Item not found!\n");
	}
	else 		// found
	{
		printf("This item will be deleted, are you sure? (Y)es/(No): ");
		select = yes();
		{
			if(select == 1)	//yes
			{
				for(counter = 0; counter < *NoOfRecs; counter++)
				{
					if(counter == record)
					{
						item[counter] = item[counter+1];
						record++;
					}
				}
				(*NoOfRecs)--;
				printf("Item deleted!\n");
			}
			else
			{
				printf("Deleted abort!\n");
			}
		}
	}
	
}

void searchByName(struct Item* item, int NoOfItems)
{
	char name[SIZE], temp[SIZE];
	int counter = 0, value = 0, i = 0;
	clrKyb();
	printf("Please enter partial name: ");
	scanf("%[^\n]", name);
	for(counter = 0; name[counter]; counter++)
	{
		name[counter] = tolower(name[counter]);
	}
	for(counter = 0; counter < NoOfItems; counter++)
	{
		strcpy(temp,item[counter].name);
		for(i = 0; i < SIZE; i++)
			{
				(temp[i]) = tolower(temp[i]);
			}
		if(strncmp(name,temp,1) == 0)
		{
			dspItem(item[counter], 1);
			counter = NoOfItems;
			value = 1;
		}
	}
	if(value == 0)
	{
		printf("No matches found!\n");
	}
	
}

void sort(struct Item* item, int NoOfItems)
{
	int select;
	int i,j;
	struct Item temp;
	do
	{
		printf("1- Sort by SKU\n");
		printf("2- Sort by name\n");
		printf("0- Exit\n");
		printf(">");
		scanf("%d", &select);
		if(select == 1)
		{
			for(i=NoOfItems-1;i>=0;i--){
				for(j=1;j<=i;j++){
					if(item[j-1].sku > item[j].sku){
							temp = item[j-1];
							item[j-1] = item[j];
							item[j] = temp;
					}
				}
			}
			for(i=0 ;i<NoOfItems;i++)
				dspItem(item[i], 1);
		}
		else if(select == 2)
		{
			for(i=NoOfItems-1;i>=0;i--){
				for(j=1;j<=i;j++){
					if(strcmp(item[j-1].name, item[j].name) > 0)
					{
							temp = item[j-1];
							item[j-1] = item[j];
							item[j] = temp;
					}
				}
			}
			for(i=0 ;i<NoOfItems;i++)
				dspItem(item[i], 1);
		}
	}while(select != 0);
}
	
int menu()  									
{
	int option;
	printf("1- List all items\n2- Search by SKU\n3- Checkout an item\n4- Stock an item\n5- Add new item or update item\n6- Delete item\n7- Search by name\n8- Sort Items\n0- Exit program\n> ");
	do {
		scanf("%d", &option);
		if (option > 8 || option < 0) {
			printf("Invalid value, 0 <= value <= 8: ");
		}
	} while (option > 8 || option < 0);
	return option;
}

void GrocInvSys ()
{
    struct Item inventory[MAX_ITEM_NO];
    int record, b, holdNR;
    welcome();
    record = loadItems(inventory, DATAFILE, &holdNR);
    if(record == 0)
	{
		printf("Could not read from %s.\n",DATAFILE);
    }
    if(record == 1)
	{
        int DONE = 0;
        int SEL;
        while(!DONE){
        SEL = menu();	
        if(SEL == 1)
		{
            listItems(inventory, holdNR);
			printf("Press <ENTER> to continue...\n");
			clrKyb();
        }
        if(SEL == 2)
		{
            search(inventory, MAX_ITEM_NO);
			printf("Press <ENTER> to continue...\n");
			clrKyb();
        }
        if(SEL == 3)
		{
			adjustQty(inventory, MAX_ITEM_NO ,CHECKOUT);
            b = saveItems(inventory, DATAFILE, holdNR);
            if(b == 0)
			{
                printf("could not update data file %s\n",DATAFILE);
            }
			printf("Press <ENTER> to continue...");
			clrKyb();
        }
		if(SEL == 4)
		{
            adjustQty(inventory, MAX_ITEM_NO, STOCK);
            b = saveItems(inventory, DATAFILE, holdNR);
            if(b == 0)
			{
                printf("could not update data file %s\n",DATAFILE);
            }
			printf("Press <ENTER> to continue...");
			clrKyb();
        }
        if(SEL == 5)
		{
            addOrUpdateItem(inventory, &holdNR);
            b = saveItems(inventory,DATAFILE,holdNR);
            if(b == 0)
			{
                printf("could not update data file%s\n",DATAFILE);
            }
            printf("Press <ENTER> to continue...");
			clrKyb();
        }
         if(SEL == 6)
		{
			deleteItem(inventory, &holdNR);
            printf("Press <ENTER> to continue...");
			clrKyb();
        }
        if(SEL == 7)
		{
			searchByName(inventory, holdNR);
            printf("Press <ENTER> to continue...");
			clrKyb();
        } 
		if(SEL ==8)
		{
			sort(inventory, holdNR);
			printf("Press <ENTER> to continue...");
			clrKyb();pause();
			
		}
        if(SEL == 0)
		{
			printf("Exit the program? (Y)es/(N)o): ");
            DONE = yes();
        }
        }
    }
}

int main(void) 
{
	GrocInvSys();
	return 0;
}









