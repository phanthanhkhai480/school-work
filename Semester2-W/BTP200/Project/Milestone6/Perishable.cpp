#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <cstring>
#include <string>
#include "Perishable.h"
using namespace std;

namespace ict
{
	char Perishable::signature() const
	{
		return 'P';
	}

	Perishable::Perishable()
	{
		m_expiry.dateOnly(true);
	}

	fstream & Perishable::save(fstream & file) const
	{
		NonPerishable::save(file);
		file << "," << this->m_expiry;
		return file;
		// TODO: insert return statement here
	}

	fstream & Perishable::load(fstream & file)
	{
		NonPerishable::load(file);
		file.ignore(1);
		file >> this->m_expiry;
		return file;
		// TODO: insert return statement here
	}

	ostream & Perishable::write(ostream & os, bool linear) const
	{
		NonPerishable::write(os, linear);
		if (ok() && linear == false)
			os << "Expiry date: " << this->m_expiry << endl;
		return os;
		// TODO: insert return statement here
	}

	istream & Perishable::read(istream & istr)
	{
		cout << "Perishable ";
		NonPerishable::read(istr);
		if (istr.fail() == false)
		{
			cout << "Expiry date (YYYY/MM/DD): ";
			m_expiry.Date::read(istr);
			if (m_expiry.errCode() == CIN_FAILED)
			{
				NonPerishable::error("Invalid Date Entry");
				//cout << "Invalid Date Entry" << endl;
				istr.setstate(ios::failbit);
			}
			else if (m_expiry.errCode() == YEAR_ERROR)
			{
				NonPerishable::error("Invalid Year in Date Entry");
				//cout << "Invalid Year in Date Entry" << endl;
				istr.setstate(ios::failbit);
			}
			else if (m_expiry.errCode() == MON_ERROR)
			{
				NonPerishable::error("Invalid Month in Date Entry");
				//cout << "Invalid Month in Date Entry" << endl;
				istr.setstate(ios::failbit);
			}
			else if (m_expiry.errCode() == DAY_ERROR)
			{
				NonPerishable::error("Invalid Day in Date Entry");
				//cout << "Invalid Day in Date Entry" << endl;
				istr.setstate(ios::failbit);
			}
		}
		return istr;
		// TODO: insert return statement here
	}
}

