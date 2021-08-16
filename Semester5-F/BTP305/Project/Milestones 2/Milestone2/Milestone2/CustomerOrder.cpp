#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "CustomerOrder.h"
using namespace std;

CustomerOrder::CustomerOrder()
{
	this->Name = "";
	this->Product = "";
	this->ItemCount = 0;
	this->field_width = 1;
	this->ItemList = nullptr;
}

CustomerOrder::CustomerOrder(std::string &record)
{
	Utilities tmp;

	size_t counter = 0;
	bool a = true;

	//getName
	this->Name = tmp.extractToken(record, counter, a);
	counter += this->Name.size() + 1;
	//getProduct
	this->Product = tmp.extractToken(record, counter, a);
	counter += this->Product.size() + 1;
	//getItem
	size_t repeat = counter;
	string repeatCheck;
	while (counter <= record.size())
	{
		repeatCheck = tmp.extractToken(record, counter, a);
		this->ItemCount++;
		counter += repeatCheck.size() + 1;
	}

	this->ItemList = new ItemInfo*[this->ItemCount];
	for (unsigned int ab = 0; ab < this->ItemCount; ++ab)
	{
		this->ItemList[ab]= new ItemInfo(tmp.extractToken(record, repeat, a));
		repeat += this->ItemList[ab]->ItemName.size() + 1;
	}
		

	if (tmp.getFieldWidth() > this->field_width)
		this->field_width = tmp.getFieldWidth();
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
		this->Name = abc.Name;
		this->field_width = abc.field_width;
		this->ItemCount = abc.ItemCount;
		this->ItemList = abc.ItemList;
		this->Product = abc.Product;

		abc.Name = "";
		abc.field_width = 0;
		abc.ItemCount = 0;
		abc.Product = "";
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
}

void CustomerOrder::Display(std::ostream & os)
{
	os << this->Name << std::endl;
	os << this->Product << std::endl;
	for (unsigned int a = 0; a < this->ItemCount; a++)
	{
		os << std::left << "[" << this->ItemList[a]->SerialNumber << "]"
			 << this->ItemList[a]->ItemName;
		if (this->ItemList[a]->FillState == true)
			os << " - FILLED" << std::endl;
		else
			os << " - MISSING" << std::endl;
	}
}

