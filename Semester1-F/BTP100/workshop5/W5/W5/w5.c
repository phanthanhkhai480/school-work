#include<stdio.h>
#define MAX_ITEMS 10
struct Item {
	int sku;
	float price;
	int quantity;
};
int main()
{
	int select = 0, size = 0, sku, quantity, counter = 0;
	float price;
	printf("Welcome to the shop\n ===================\n");
	struct Item item[MAX_ITEMS];
	printf("Please select from the following options:\n 1)Display the inventory\n 2)Add to the inventory\n 0)Exit\n Select:");
	scanf("%d", &select);
	while (select != 0) 
	{
		if (select == 1) {
			printf("Inventory\n =========================================\n Sku  Price  Quantity\n");
			for (counter = 0; counter < sizeof(item); counter++) {
				printf("%d %d %f\n", item[counter].sku, item[counter].quantity, item[counter].price);
			}
			printf("=========================================\n");
			break;
		}
		
		if (select == 2) {
			printf("Enter a sku number: ");
			scanf("%d", &sku);
			counter = 0;
			if (sizeof(item) != MAX_ITEMS) {
				for (counter = 0; counter < MAX_ITEMS; counter++) {
					if (sku != item[counter].sku) {
						printf("Quantity: ");
						scanf("%d", &quantity);
						printf("Price: ");
						scanf("%f", &price);
						printf("The items is successfully added to inventory\n");
						break;
					}
					else if (sku == item[counter].sku) {
						printf("Error item exists\n");
						break;
					}
				}
			}
			else {
				printf("Inventory full\n");
			}
			
		}
		
		
		if (select < 0 || select > 2) {
			printf("Invalid input, try again: Please select from the following options: \n 1)Display the inventory\n 2)Add to the inventory\n 0)Exit\n Select:");
			scanf("%d", &select);
		}
		
		}
			
	
	}
	
	
	if (select == 0)
		printf("Good Bye !!!\\n");

	return 0;
}