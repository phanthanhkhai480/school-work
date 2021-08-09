#include<stdio.h>
#define MAX 10
struct Item {int sku; float price; int quantity;};

void menu()
{
	printf("Please select from the following options:\n 1) Display the inventory.\n 2) Add to the inventory.\n 3) Check price.\n 4) Clear Screen.\n 0) Exit.\n");
}

int validate(const int low, const int high)
{
	int value;
	do{
		printf("Enter a number:");
		scanf("%d", &value);
		if(value > high || value < low){
		printf("Invalid value, %d < value < %d: ", low, high);
		}
	}	while (value > high || value < low);
		return value;
}

void clear()
{
	for (int counter = 0; counter < 40; counter++)
		printf("\n");
	
}

void displayInventory(const struct Item items[MAX],const int size)
{
	printf("Inventory\n =========================================\n Sku   Price   Quantity\n");
	if (size < 1) 
		printf(" There is no inventory curently.\n Select '2' to stock inventory!\n");
	else {
		for (int counter = 0; counter < size; counter++) 
		printf("%d   %.2f      %5.d\n", items[counter].sku, items[counter].price, items[counter].quantity);
		}
	printf("=========================================\n");
}

int searchInventory(const struct Item items[],const int sku_item,const int size)
{
	int index = -1;
		for (int i = 0; i < size; i++) {
			if (sku_item == items[i].sku){
				index = i;
			}
	     }
		return index;
} 
void addItem(struct Item items[MAX], int *size)
{
	int index, quantity, sku;
	if (*size == MAX){
		printf("INVENTORY FULL!\n");
		}
	else{
		printf("Enter a sku number:");
		scanf("%d", &items[*size].sku);
		index = searchInventory(items, items[*size].sku, *size);
		if (index >= 0){
			printf("Update the quantity:");
			scanf("%d", &items[index].quantity);
			printf("Successfully updated\n");
		}
		else {
			printf("\nEnter the price: ");
			scanf("%f", &items[*size].price);
			printf("\nEnter the quantity: ");
			scanf("%d", &items[*size].quantity);
			printf("The items is successfully added to inventory\n");
			*size = *size + 1; 
		 }
		}
}
	void checkPrice(struct Item items[MAX], int *size)
	{
		int sku, index;
		printf("Enter the SKU number:");
		scanf("%d", &items[*size].sku);
		index = searchInventory(items, items[*size].sku, *size);
		if (index >= 0) 
			printf("\nThe price of this item is : %.3f\n", items[index].price);
		else
			printf("\nThe item you searched for is not in stock!\n");
	}	
int main(void)	
{
	int iVal, size = 0, option;
	struct Item items[MAX];
	clear();
	printf("Welcome to the Shop\n ===================\n");
	do 
	{
	menu();
	iVal = validate(0,4);
	switch(iVal)
		{
			
	case 1:
		displayInventory(items, size);
		break;
		
	case 2:
		addItem(items, &size);
		break;
		
	case 3: 
		checkPrice(items, &size);
		break;
		
	case 4: 	
		clear();
		break;
	}
	}while(iVal != 0);
	return 0;
}


