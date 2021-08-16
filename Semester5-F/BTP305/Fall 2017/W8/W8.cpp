// Workshop 8 - Smart Pointers
// W8.cpp

#include <iostream>
#include <iomanip>
#include <memory>
#include "Element.h"
#include "List.h"

const int FWC = 5;
const int FWD = 12;
const int FWP = 8;

w8::List<w8::Product> merge(
	const w8::List<w8::Description>& desc,
	const w8::List<w8::Price>& price) {

	w8::List<w8::Product> priceList;

	for (int i = 0; i < desc.size(); i++) {

		for (int j = 0; j < price.size(); j++) {

			if (desc[i].code == price[j].code) {
			
			  std::unique_ptr<w8::Product> product(new w8::Product(desc[i].desc, price[j].price));
			  product->validate();
			  priceList += std::move(product);
			}
		}
	}

	return priceList;
}

int main(int argc, char** argv) {
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 3) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}

	try {
		w8::List<w8::Description> desc(argv[1]);
		std::cout << std::endl;
		std::cout << std::setw(FWC) << "Code" <<
			std::setw(FWD) << "Description" << std::endl;
		std::cout << desc << std::endl;
		w8::List<w8::Price> price(argv[2]);
		std::cout << std::endl;
		std::cout << std::setw(FWC) << "Code" <<
			std::setw(FWP) << "Price" << std::endl;
		std::cout << price << std::endl;
		w8::List<w8::Product> priceList = merge(desc, price);
		std::cout << std::endl;
		std::cout << std::setw(FWD) << "Description" <<
			std::setw(FWP) << "Price" << std::endl;
		std::cout << priceList << std::endl;
	}
	catch (const std::string& msg) {
		std::cerr << msg << std::endl;
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}

	std::cout << "\nPress any key to continue ... ";
	std::cin.get();
}