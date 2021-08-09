#include <stdio.h>
#define MAX_ITEMS 10
struct Item {
	int sku;
	float price;
	int quantity;
};
void clear(void);
void clear(void)
{
	while (getchar() != '\n');
}
int main()
{
	int select = 0, size = 0, sku, quantity = 0, counter = 0, i = 0, in_Stock = 0;
	float price = 0;
	printf("Welcome to the shop\n ===================\n");
	struct Item item[MAX_ITEMS];
	do {
		printf("Please select from the following options:\n 1)Display the inventory\n 2)Add to the inventory\n 3)Price Check\n 0)Exit\n Select:");
		scanf("%d", &select);
		clear();
		counter = 0;
		if (select < 0 || select > 3) {
			printf("Invalid.\n ");
		}
		else {
			if (select == 1) {
				printf("Inventory\n =========================================\n Sku  Price  Quantity\n");
				if (size < 1) 
					printf(" There is no item in the inventory currently.\n Select '2' to stock inventory!\n");
				else {
					for (counter = 0; counter < size; counter++) 
						printf("%d %f %d\n", item[counter].sku, item[counter].price, item[counter].quantity);
				}
				printf("=========================================\n");
			}
			else if (select == 2) 
			{
				if (size == MAX_ITEMS) 
					printf("INVENTORY FULL!\n");
				else 
				{
				printf("Enter a sku number: ");
				scanf("%d", &item[size].sku);
				}
				if (sku == item[size].sku)
				{
                    printf("Update the quantity:");
                    scanf("%d", &item[counter].quantity);
                    printf("Successfully updated\n");
				}
                else 
				{
                    printf("\nEnter the price: ");
                    scanf("%f", &item[size].price);
                    clear();
                    printf("\nEnter the quantity: ");
                    scanf("%d", &item[size].quantity);
                    printf("The items is successfully added to inventory\n");
                    clear();
                    size++; 
				}
			}
			else if (select == 3) {{
				printf("Enter the SKU number you are looking for: ");
				scanf("%d", &sku);
				clear(); }
				for (i = 0; i <= size; i++) {
					if (sku == item[i].sku) {
						printf("\nThe price of this item is : %f\n", item[i].price);
						in_Stock = 1;
					}
				}
				if (in_Stock != 1) 
					printf("\nThe item you searched for is not in stock!\n");	
			}
		}

	} while (select != 0);
	if (select == 0)
		printf("Good Bye !!!\\n");
	return 0;
}