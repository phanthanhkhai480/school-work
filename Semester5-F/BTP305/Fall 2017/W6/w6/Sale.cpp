//Workshop 6 - BTP305-SCC Fall 2017 by Wilson Tang
//Seneca ID: 113482152
//Seneca Email: WTANG49@MYSENECA.CA

#include <iostream>
#include <fstream>
#include <iomanip>
#include "iProduct.h"
#include "Sale.h"

namespace w6 {

	Sale::Sale(const char* fn) {
		std::ifstream file(fn);

		while (file.good())	{
			iProduct* ip = readProduct(file);
			productList.push_back(ip);
		}
	}

	void Sale::display(std::ostream& os)	{
		double totalSum = 0;
		os << std::setw(10) << "Product No" << std::setw(10) 
		   << "Cost" << std::setw(10) << "Taxable\n";
		os << std::fixed << std::setprecision(2);
		
		for (auto i : productList){
			os << *i;
			totalSum += i->getCharge();
		}
		os << std::setw(10) << "Total" << std::setw(10) 
		   << totalSum << std::endl;
	}
}