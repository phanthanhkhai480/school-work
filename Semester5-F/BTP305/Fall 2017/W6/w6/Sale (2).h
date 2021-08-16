//Workshop 6 - BTP305-SCC Fall 2017 by Wilson Tang
//Seneca ID: 113482152
//Seneca Email: WTANG49@MYSENECA.CA

#ifndef _SALE_H_
#define _SALE_H_

#include "iProduct.h"
#include <iostream>
#include <vector>

namespace w6 {

	class Sale {
		std::vector<iProduct*> productList;

	public:
		Sale(const char*);
		void display(std::ostream&);

	};
}
#endif