#include <iostream>
#include <iomanip>
#include "TaxableProduct.h"
using namespace std;

namespace w6
{
	TaxableProduct::TaxableProduct()
	{
		this->tax = '\0';
	}

	TaxableProduct::TaxableProduct(const int ID, const double price, const char m_tax)
		: Product(ID, price)
	{
		this->tax = m_tax;
	}

	double TaxableProduct::getPrice() const
	{
		double tmpPrice;
		if (this->tax == 'H')
			tmpPrice = Product::getPrice() * HST;
		else if (this->tax == 'P')
			tmpPrice = Product::getPrice() * PST;
		else
			tmpPrice = Product::getPrice();
		return tmpPrice;
	}

	void TaxableProduct::display(std::ostream & abc) const
	{
		Product::display(abc);
		if (this->tax == 'H')
			abc << std::left << "HST" << endl;
		else if (this->tax == 'P')
			abc << std::left << "PST" << endl;
}