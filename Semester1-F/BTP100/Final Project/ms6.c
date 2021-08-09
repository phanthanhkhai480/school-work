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

void deleteItem(struct Item* item, int* NoOfRecs)
{
	int record;
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	for(counter = 0; counter < MAX_ITEM_NO; counter++)
	{
		if(sku == item[counter].sku)
		{
			if (item[counter].isTaxed == 1) { strcpy(taxed, "Yes"); }
			else { strcpy(taxed, "No"); }
			printf("        SKU: %d\n", item[counter]->sku);
			printf("       Name: %s\n", item[counter]->name);
			printf("      Price: %.2lf\n", item[counter]->price);
			printf("   Quantity: %d\n", item[counter]->quantity);
			printf("Minimum Qty: %d\n", item[counter]->minQuantity);
			printf("   Is Taxed: %s\n", taxed);
			record = counter;
			value = 1;
			break;
		}
	}
	if(value == 0)
		{
		printf("Item not found!\n");
		}
		if(value == 1)
		{
		printf("This item will be deleted, are you sure? (Y)es/(N)o: ");
		select = yes();
		{
			if(select == 1)
			{
				for(counter = 0; counter < MAX_ITEM_NO; counter++)
				{
					if(item[counter] == record)
					{
						a[counter--] = a[MAX_ITEM_NO --];
					}
				}
			}
			else
			{
				printf("Deleted abort!\n");
			}
		}
	}
	
}
	
}

void searchByName(struct Item* item, int NoOfItems)
{
	char name[100];
	int counter = 0, value = 0;
	printf("Please enter partial name: ");
	scanf("%100[^\n]", name);
	for(counter = 0; counter < NoOfItems, counter++)
	{
		if((strcasecmp(name, item[counter].name) < 0)
		{
			listItems(*item, NoOfItems);
			value = 1;
		}
	}
	if(value ==0)
	{
		printf("No matches found!\n")
	}
	
}