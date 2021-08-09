#include<stdio.h>
int main()
{
	int items,loonies, cents;
	float total, price, cost, cash, change;

	printf("Please enter the number of items purchased: ");
	scanf("%d", &items);
	printf("Enter the unit price of selected items: ");
	scanf("%f", &price);
	total = items * price;
	cost = items * price * 1.13;
	printf("The total cost excluding HST: %f", total);
	printf("The total cost including HST: %f", cost);
	printf("Amount of cash received:");
	scanf("%d", &cash);
	change = cash - cost;
	printf("Amount of change: %f", change);
	loonies = change / 1;
	printf("Number of loonies: %d", loonies);
	cents = (cash - loonies) / 0.1;
	printf("Number of cents: %d", cents);

		return 0;
}
