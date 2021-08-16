#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "CustomerOrder.h"
using namespace std;

CustomerOrder::CustomerOrder()
{
	//this->Name = "";
	//this->Product = "";
	//this->ItemCount = 0;
	//this->field_width = 1;
	this->ItemList = nullptr;
}

CustomerOrder::CustomerOrder(std::string &record)
{
	Utilities tmp;

	size_t counter = 0;
	bool a = true;
	int ab = 0;

	//getName
	this->Name = tmp.extractToken(record, counter, a);
	counter += this->Name.size() + 1;
	//getProduct
	this->Product = tmp.extractToken(record, counter, a);
	counter += this->Product.size() + 1;
	//getItem
	while (counter <= record.size())
	{
		ItemList[ab]->ItemName = tmp.extractToken(record, counter, a);
		counter += ItemList[ab]->ItemName.size() + 1;
		this->ItemCount++;
		cout << counter << std::endl;
		ab++;
	}

	if (tmp.getFieldWidth() > this->field_width)
	{
		this->field_width = tmp.getFieldWidth();
	}
}

CustomerOrder::~CustomerOrder()
{
	if (this->ItemCount > 0)
	{
		for (unsigned int a = 0; a < this->ItemCount; a++)
			delete this->ItemList[a];
	}
	delete[] this->ItemList;
}

CustomerOrder::CustomerOrder(CustomerOrder && abc)
{
	this->ItemList = nullptr;
	*this = std::move(abc);
}

CustomerOrder & CustomerOrder::operator=(CustomerOrder && abc)
{
	if (this != &abc)
	{
		if (this->ItemCount > 0)
		{
			for (unsigned int a = 0; a < this->ItemCount; a++)
				delete this->ItemList[a];
		}
		delete[] this->ItemList;

		*this = std::move(abc);
		abc.ItemList = nullptr;
	}
	return *this;
}

bool CustomerOrder::getOrderFillState()
{
	for (unsigned int a = 0; a < ItemCount; a++)
	{
		if (ItemList[a]->FillState == false)
			return false;
	}
	return true;
}

bool CustomerOrder::getItemFillState(std::string itemName)
{
	for (unsigned int a = 0; a < ItemCount; a++)
	{
		if (ItemList[a]->ItemName == itemName)
			return ItemList[a]->FillState;
	}
}

void CustomerOrder::fillItem(Item & item_, std::ostream & os)
{
	for (unsigned int a = 0; a < this->ItemCount; a++)
	{
		if (this->ItemList[a]->ItemName == item_.getName())
		{
			if (item_.getQuantity() > 0)
			{
				this->ItemList[a]->SerialNumber = item_.getSerialNumber();
				this->ItemList[a]->FillState = true;
				item_.updateQuantity();
				os << "Filled " << this->Name << " " << this->Product
					<< "[" << this->ItemList[a]->ItemName << "]" << std::endl;
			}
			else
			{
				os << "Unfilled " << this->Name << " " << this->Product
					<< "[" << this->ItemList[a]->ItemName << "]" << std::endl;
			}
		}
	}
	os << std::endl;
}

void CustomerOrder::Display(std::ostream & os)
{
	os << this->Name << std::endl;
	os << this->Product << std::endl;
	for (unsigned int a = 0; a < this->ItemCount; a++)
	{
		os << "[" << this->ItemList[a]->SerialNumber << "]"
			<< std::setw(this->field_width) << this->ItemList[a]->ItemName;
		if (this->ItemList[a]->FillState == true)
			os << " - FILLED" << std::endl;
		else
			os << " - MISSING" << std::endl;
	}
}

