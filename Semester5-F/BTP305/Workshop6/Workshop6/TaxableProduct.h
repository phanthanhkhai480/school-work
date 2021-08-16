#ifndef TAXABLE_PRODUCT_H
#define TAXABLE_PRODUCT_H
#include "Product.h"
const double HST = 1.13;
const double PST = 1.08;

namespace w6
{
	class TaxableProduct : public Product
	{
		char tax;				/*!< variable type char hold tax character !>*/
	public:
		TaxableProduct();		/*!< default constructor !>*/
		TaxableProduct(const int ID, const double price, const char m_tax);
		/*!< constructor with 3 arguments !>*/
		double getPrice() const;	/*!< return price for Product with tax !>*/
		void display(std::ostream& abc) const;		/*!< display Product with tax !>*/
	};
}

#endif