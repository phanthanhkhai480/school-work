//Workshop 6 - BTP305-SCC Fall 2017 by Wilson Tang
//Seneca ID: 113482152
//Seneca Email: WTANG49@MYSENECA.CA

#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

#include <iostream>
#include <fstream>

namespace w6 {

	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	class Product : public iProduct {
		int productID;
		double productPrice;
	public:
		Product(const int , const double);
		double getCharge() const;
		void display(std::ostream&) const;
	};

	class TaxableProduct : public iProduct {
		int productID;
		double productPrice;
		char taxableCode;
	public:
		TaxableProduct(const int, const double, const char);
		double getCharge() const;
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);
}
#endif