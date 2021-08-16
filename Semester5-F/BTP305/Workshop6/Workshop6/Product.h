#ifndef PRODUCT_H
#define PRODUCT_H
#include "iProduct.h"

namespace w6
{
	class Product : public iProduct
	{
		int productID;			/*!< variable type int hold productID !>*/
		double productPrice;	/*!< variable type double hold productPrice !>*/
	public:
		Product();				/*!< default constructor !>*/
		Product(const int ID, const double price);
		/*!< custom constructor with 2 arguments  !>*/
		double getPrice() const;	/*!< return price for Product without tax !>*/
		void display(std::ostream& abc) const;
		/*!< display Product without tax !>*/
	};
}

#endif