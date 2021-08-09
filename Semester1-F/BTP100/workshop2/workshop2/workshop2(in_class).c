#include<stdio.h>
int main()
{
	float length, area;
	float width;
	int amount, meters;
	int divide;

	printf("Please enter the Length of the Room:");
	scanf("%f",&length);
	printf("Please enter the Width of the Room:");
	scanf("%f",&width);
	area = width * length;
	printf("Area of the Room: %f",area);
	printf("Please enter the amount of carpeting, in square meters:");
	scanf("%d", &amount);
	divide = amount / area;
	printf("Enough carpet to cover: %d", divide);

	return 0;


}
