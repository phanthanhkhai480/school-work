//Workshop 6 - BTP305-SCC Fall 2017 by Wilson Tang
//Seneca ID: 113482152
//Seneca Email: WTANG49@MYSENECA.CA


#include <iostream>
#include <fstream>
#include <iomanip>
#include "iProduct.h"

namespace w6 {
	Product::Product(const int id, const double price) {
		productID = id;
		productPrice = price;
	}

	double Product::getCharge() const {
		return productPrice;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(10) << std::right << productID << std::setw(10) << productPrice << std::endl;
	}


	TaxableProduct::TaxableProduct(const int id, const double price, const char taxCode) {
		productID = id;
		productPrice = price;
		taxableCode = taxCode;
	}

	double TaxableProduct::getCharge() const {
		double tax;

		if (toupper(taxableCode) == 'H') 
			tax = 1.13;
		else if (toupper(taxableCode) == 'P')
			tax = 1.08;
		else
			tax = 1.00;

		return (productPrice*tax);
	}

	void TaxableProduct::display(std::ostream& os) const {
		os << std::setw(10) << productID << std::setw(10) << productPrice;

		if (taxableCode == 'H')
			os << std::setw(10) << std::left << "  HST" << std::right << std::endl;
		else if (taxableCode == 'P') 
			os << std::setw(10) << std::left << "  PST" << std::right << std::endl;
		else
			os << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& productInfo) {
		productInfo.display(os);
		
		return os;
	}

	iProduct* readProduct(std::ifstream& is) {
		int itemID;
		double itemPrice;
		char itemTax;
		iProduct* temp;

		is >> itemID >> itemPrice;

		if (is.get() != '\n') {
			is.get(itemTax);
			temp = new TaxableProduct(itemID, itemPrice, itemTax);
		}
		else 
			temp = new Product(itemID, itemPrice);

		return temp;
	}
}