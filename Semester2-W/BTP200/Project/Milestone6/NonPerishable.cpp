#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <cstring>
#include <string>
#include "NonPerishable.h"
using namespace std;

namespace ict
{
	bool NonPerishable::ok() const
	{
		return m_err.Error::isClear();
	}

	void NonPerishable::error(const char * message)
	{
		m_err.Error::message(message);
	}

	char NonPerishable::signature() const
	{
		return 'N';
	}

	std::fstream & NonPerishable::save(std::fstream & file) const
	{
		file << signature() << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity();
		return file;
		// TODO: insert return statement here
	}

	std::fstream & NonPerishable::load(std::fstream & file)
	{
		string sku, name;
		double price;
		int quantity, taxed;
		file.setf(ios::left);
		getline(file, sku, ',');
		getline(file, name, ',');
		file >> price;
		file.ignore(1);
		file >> taxed;
		file.ignore(1);
		file >> quantity;
		Item::sku(sku.c_str());
		Item::name(name.c_str());
		Item::quantity(quantity);
		Item::taxed(bool(taxed));
		Item::price(price);
		return file;
		// TODO: insert return statement here
	}

	std::ostream & NonPerishable::write(std::ostream & ostr, bool linear) const
	{
		if (ok() == false)
		{
			ostr << m_err;
		}
		else
		{
			ostr.setf(ios::fixed);
			/*if (linear)
				cout << "it's linear";
			else
				cout << "Non linear";*/
			if (linear == true)
			{
				ostr << " ";
				ostr.width(MAX_SKU_LEN);
				ostr.unsetf(std::ios::right);
				ostr.setf(ios::left);
				ostr  << sku() << "|";
				ostr.width(20);
				ostr << name() << "|";
				ostr.setf(ios::right);
				ostr.width(7);
				ostr.precision(2);
				ostr << price() << "| " << (taxed() ? "T" : " ") << signature() << "|";
				ostr.width(4);
				ostr << quantity() << "|";
				ostr.width(9);
				ostr << cost() * quantity() << "|";
			}
			else
			{
				if (taxed() == true)
				{
					ostr << "Name:" << endl << name() << endl
						<< "Sku: " << sku() << endl
						<< "Price: " << price() << endl
						<< "Price after tax: " << cost() << endl
						<< "Quantity: " << quantity() << endl
						<< "Total Cost: " << cost() * quantity() << endl;
				}
				else
				{
					ostr << "Name:" << endl << name() << endl
						<< "Sku: " << sku() << endl
						<< "Price: " << price() << endl
						<< "Price after tax: N/A" << endl
						<< "Quantity: " << quantity() << endl
						<< "Total Cost: " << cost() * quantity() << endl;
				}
			}
		}
		return ostr;
		// TODO: insert return statement here
	}

	std::istream & NonPerishable::read(std::istream & istr)
	{
		m_err.clear();
		string sku, name;
		double price;
		int quantity;
		char taxed;
		cout << "Item Entry:" << endl << "Sku: ";
		istr >> sku;
		cout << "Name:" << endl;
		istr >> name;
		cout << "Price: ";
		istr >> price;
		if (istr.fail())
		{
			m_err.message("Invalid Price Entry");
		}
		else
		{
			m_err.clear();
			cout << "Taxed: ";
			istr >> taxed; 
			
			if (taxed != 'y' && taxed != 'Y' && taxed != 'n' && taxed != 'N')
			{
				istr.setstate(ios::failbit);
				m_err.message("Invalid Taxed Entry, (y)es or (n)o");
			}
			else
			{
				m_err.clear();
				cout << "Quantity: ";
				istr >> quantity;
				if (istr.fail())
				{
					m_err.message("Invalid Quantity Entry");
				}
				else
				{
					m_err.clear();
					Item::sku(sku.c_str());
					Item::name(name.c_str());
					Item::price(price);
					Item::quantity(quantity);
					Item::taxed(taxed == 'y' || taxed == 'Y');
				}
			}
		}
		return istr;
		// TODO: insert return statement here
	}

	std::ostream& operator << (std::ostream & os, const NonPerishable & I)
	{
		I.write(os, true);
		return os;
	}

	std::istream & operator >> (std::istream & is, NonPerishable & I)
	{
		I.read(is);
		return is;
		// TODO: insert return statement here

	}
}
