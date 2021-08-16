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
	size_t counter = 0, temp = 0;
	string serialNum, quantity;
	bool a = true;

	this->name = tmp.extractToken(record, counter, a);
	cout << this->name << endl;
	temp = tmp.getFieldWidth();
	if (temp > field_width)
		field_width = temp;
	counter += this->name.size() + 1;

	serialNum = tmp.extractToken(record, counter, a);
	stringstream converter(serialNum);
	converter >> this->serialNumber;
	temp = tmp.getFieldWidth();
	if (temp > field_width)
		field_width = temp;
	counter += serialNum.size() + 1;

	quantity = tmp.extractToken(record, counter, a);
	stringstream convert(quantity);
	convert >> this->Quantity;
	temp = tmp.getFieldWidth();
	if (temp > field_width)
		field_width = temp;
	counter += quantity.size() + 1;

	this->description = tmp.extractToken(record, counter, a);
	cout << this->description << endl;
	temp = tmp.getFieldWidth();
	if (temp > field_width)
		field_width = temp;
}

const std::string & Item::getName() const
{
	return this->name;
}

const unsigned int Item::getSerialNumber() const
{
	int temp = this->serialNumber;
	return temp;
	temp++;
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
		os << setw(CODE_WIDTH)  << "Quantity: " << getQuantity()
		   << "  Description: " << setw(field_width) << description << endl;
}
 