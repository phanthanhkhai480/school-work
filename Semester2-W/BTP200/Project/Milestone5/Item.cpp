#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include<iostream>
#include<cstring>
#include <fstream>
// inlcude Item and POS header files
#include "POS.h"
#include "PosIO.h"
#include "Item.h"


using namespace std;
namespace ict {

	// class Item implementaion
	Item::Item()
	{
		m_sku[0] = '\0';
		m_name = nullptr;
		m_price = 0;
		m_quantity = 0;
		m_taxed = true;
	}

	Item::Item(const char* sku, const char* name, double price, bool taxed)
	{
		for (int counter = 0; counter < MAX_SKU_LEN; counter++)
		{
			m_sku[counter] = sku[counter];
		}
		int len = strlen(name);
		for (int counter = 0; counter < len; counter++)
		{
			m_name[counter] = name[counter];
		}
		m_price = price;
		m_quantity = 0;
		m_price = price;
		if (taxed == 0)
			m_taxed = false;
		else
			m_taxed = true;
	}

	bool Item::operator==(const char* sku)
	{
		if (this->m_sku == sku)
			return true;
		return false;
	}

	Item::Item(const Item &other)
	{
		this->m_taxed = other.m_taxed;
		this->m_quantity = other.m_quantity;
		this->m_price = other.m_price;
		if (other.m_name != nullptr)
		{
			//cout << "This is if-name: " << other.m_name << endl;
			int len = strlen(other.m_name);
			this->m_name = new char[len + 1];
			strcpy(m_name, other.m_name);
		}
		else
		{
			m_name = nullptr;
		}
		//cout << "This is sku:" << this->m_sku;
		//cout << "This is other.sku:" << other.sku;
		if (other.m_sku != nullptr)
		{
			//cout << "This is sku:" << this->m_sku;
			//cout << "This is other.sku:" << other.sku;
			m_sku[0] = '\0';
			int len = strlen(m_sku);
			for (int counter = 0; counter < len; counter++)
			{
				m_sku[counter] = other.m_sku[counter];
			}
		}
		else
		{
			m_sku[0] = '\0';
		}
	}

	Item& Item::operator=(const Item &other)
	{
		//cout << "This is name assignment: " << other.m_name << endl;
		if (this != &other)
		{
			this->m_price = other.m_price;
			this->m_quantity = other.m_quantity;
			this->m_taxed = other.m_taxed;
			//delete[] m_name;
			//delete[] m_sku;
			if (other.m_name != nullptr)
			{
				int len = strlen(other.m_name);
				this->m_name = new char[len + 1];
				strcpy(m_name, other.m_name);
			}
			else
			{
				m_name = nullptr;
			}
			if (other.m_sku != nullptr)
			{
				m_sku[0] = '\0';
				int len = strlen(m_sku);
				for (int counter = 0; counter < len; counter++)
				{
					m_sku[counter] = other.m_sku[counter];
				}
			}
			else
			{
				m_sku[0] = '\0';
			}
		}
		return *this;
	}

	Item::~Item()
	{
		delete[] m_name;
	}

	void Item::sku(const char* sku)
	{
		strcpy(m_sku, sku);
	}

	void Item::name(const char* name)
	{
		this->m_name = new char [strlen(name) + 1];
		strcpy(m_name, name);
	}

	void Item::quantity(const int quantity)
	{
		this->m_quantity = quantity;
	}

	void Item::price(const double price)
	{
		this->m_price = price;
	}

	void Item::taxed(const bool taxed)
	{
		this->m_taxed = taxed;
	}

	const char* Item::sku()	const
	{
		return this->m_sku;
	}

	double Item::price() const
	{
		return m_price;
	}

	const char* Item::name() const
	{
		return m_name;
	}

	bool Item::taxed() const
	{
		return m_taxed;
	}

	int Item::quantity() const
	{
		//cout << "This is quantity: " << m_quantity << endl;
		return m_quantity;
	}

	double Item::cost() const
	{
		if (m_taxed == 0)
			return m_price;
		else
			return m_price*1.13;
	}

	bool Item::isEmpty()
	{
		if (m_sku[0] == 0 && m_name[0] == '\0' && m_price == 0 && m_quantity == 0 && m_taxed)
			return true;
		return false;
	}

	int Item::operator+=(int quantity)
	{
		this->m_quantity += quantity;
		return this->m_quantity;
	}

	int Item::operator-=(int quantity)
	{
		this->m_quantity -= quantity;
		return this->m_quantity;
	}

	std::ostream & Item::write(std::ostream & os, bool linear) const
	{
		return os;
		// TODO: insert return statement here
	}

	std::istream & Item::read(std::istream & is)
	{
		return is;
		// TODO: insert return statement here
	}

	double operator+=(double& d, const Item & I)
	{
		d += (I.quantity()*I.price());
		return d;
	}

	std::ostream& operator << (std::ostream & os, const Item & I)
	{
		I.write(os, true);
		return os;
	}

	std::istream & operator >> (std::istream & is, Item & I)
	{
		I.read(is);
		return is;
		// TODO: insert return statement here

	}

}