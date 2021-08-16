#include <iostream>
#include <iomanip>
#include "Product.h"
using namespace std;

namespace w6
{
	Product::Product()
	{
		this->productID = 0;
		this->productPrice = 0;
	}

	Product::Product(const int ID, const double price)
	{
		this->productID = ID;
		this->productPrice = price;
	}

	double Product::getPrice() const
	{
		return this->productPrice;
	}

	void Product::display(std::ostream & abc) const
	{
		abc << setw(10) << right << this->productID
			<< setw(6) << this->productPrice;
	}
}