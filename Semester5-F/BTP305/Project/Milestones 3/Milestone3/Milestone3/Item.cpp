#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Item.h"
using namespace std;

Item::Item(const std::string & record)
{
	Utilities tmp;

	this->field_width = CODE_WIDTH;
	size_t counter = 0;
	string serialNum, quantity;
	bool a = true;
	//getName
	this->name = tmp.extractToken(record, counter, a);
	counter += this->name.size() + 1;
	//getSerial
	serialNum = tmp.extractToken(record, counter, a);
	stringstream converter(serialNum);
	converter >> this->serialNumber;
	counter += serialNum.size() + 1;
	//getQuantity
	quantity = tmp.extractToken(record, counter, a);
	stringstream convert(quantity);
	convert >> this->Quantity;
	counter += quantity.size() + 1;
	//getDescription
	this->description = tmp.extractToken(record, counter, a);
	
	if (tmp.getFieldWidth() > this->field_width)
	{
		this->field_width = tmp.getFieldWidth();
	}
}

const std::string & Item::getName() const
{
	return this->name;
}

const unsigned int Item::getSerialNumber() const
{
	return this->serialNumber;
}

const unsigned int Item::getQuantity() const
{
	return this->Quantity;
}

void Item::updateQuantity()
{
	if (this->Quantity > 0)
		this->Quantity--;
}

void Item::display(std::ostream & os, bool full) const
{
	os  << getName() << setw(CODE_WIDTH)
	   << "[" << setw(CODE_WIDTH)  << getSerialNumber() << "]";
	if (full == true)
		os << setw(CODE_WIDTH)  << " Quantity: " << getQuantity()
		   << "  Description: " << setw(field_width) << description << endl;
}
 