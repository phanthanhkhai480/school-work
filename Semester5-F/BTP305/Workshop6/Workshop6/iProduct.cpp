/*!\File iProduct.cpp
// \Brief BTP305 Workshop 6: STL Container
// \Details    Longer description of file
// \Version 1.0
// \Date 01/11/2018
// \Author Khai Phan
// \copyright GNU Public License.
//
//
**/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "iProduct.h"
using namespace std;

namespace w6
{
	ostream & operator<<(ostream &abc, const iProduct &abcd)
	{
		abcd.display((abc));
		abc << endl;
		return abc;	
	}

	iProduct * readProduct(std::ifstream & abc)
	{
		int tempID;
		double tempPrice;
		char tempTax;
		iProduct* tmp;

		abc >> tempID >> tempPrice;
		if (abc.get() == '\n')
			tmp = new Product(tempID, tempPrice);
		else
		{
			abc >> tempTax;
			if (tempTax != 'H' || tempTax != 'P')
				throw "Error Tax Code";
			else
				tmp = new TaxableProduct(tempID, tempPrice, tempTax);
		}
		return tmp;
	}
	
	
}


