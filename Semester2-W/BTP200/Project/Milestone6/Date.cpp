#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict
{
	Date::Date()
	{
		m_dateOnly = false;
		set();
	}

	Date::Date(int year, int month, int day)
	{
		m_dateOnly = true;
		m_year = year;
		m_mon = month;
		m_day = day;
		m_hour = 0;
		m_min = 0;
		m_readErrorCode = NO_ERROR;
	}

	Date::Date(int year, int month, int day, int hour, int min)
	{
		m_dateOnly = false;
		m_year = year;
		m_mon = month;
		m_day = day;
		m_hour = hour;
		m_min = min;
		m_readErrorCode = NO_ERROR;
	}

	void Date::set()
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		m_day = lt.tm_mday;
		m_mon = lt.tm_mon + 1;
		m_year = lt.tm_year + 1900;
		if (dateOnly())
		{
			m_hour = m_min = 0;
		}
		else 
		{
			m_hour = lt.tm_hour;
			m_min = lt.tm_min;
		}
	}

	int Date::value()const
	{
		return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
	}

	void Date::errCode(int errorCode)
	{
		this->m_readErrorCode = errorCode;
	}

	void Date::set(int year, int month, int day, int hour, int min )
	{
		this->m_year = year;
		this->m_mon = month;
		this->m_day = day;
		this->m_hour = hour;
		this->m_min = min;
		this->m_readErrorCode = NO_ERROR;
	}

	bool Date::operator==(const Date& D)const 
	{
		return this->value() == D.value();
	}

	bool Date::operator!=(const Date& D)const 
	{
		return this->value() != D.value();
	}

	bool Date::operator<(const Date& D)const 
	{
		return this->value() < D.value();
	}

	bool Date::operator>(const Date& D)const 
	{
		return this->value() > D.value();
	}

	bool Date::operator<=(const Date& D)const 
	{
		return this->value() <= D.value();
	}

	bool Date::operator>=(const Date& D)const 
	{
		return this->value() >= D.value();
	}

	int Date::errCode() const
	{
		return m_readErrorCode;
	}

	bool Date::bad() const
	{
		if (this->m_readErrorCode != 0)
			return true;
		return false;
	}

	bool Date::dateOnly() const
	{
		return this->m_dateOnly;
	}

	void Date::dateOnly(bool value)
	{
		this->m_dateOnly = value;
		if (value == true)
		{
			this->m_hour = 0;
			this->m_min = 0;
		}
	}

	int Date::mdays()const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
		mon--;
		return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
	}

	std::istream& Date::read(std::istream& is)
	{
		char delim1;
		char delim2;
		char delim3;
		char delim4;
		if (this->dateOnly() == true)
		{
			is >> this->m_year >> delim1 >> this->m_mon >> delim2 >> this->m_day;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				this->m_readErrorCode = CIN_FAILED;
			}
			else
			{
				if (this->m_year > MAX_YEAR || this->m_year < MIN_YEAR)
				{
					this->m_readErrorCode = YEAR_ERROR;
				}
				else if (this->m_mon > 12 || this->m_mon < 1)
				{
					this->m_readErrorCode = MON_ERROR;
				}
				else if (this->m_day > this->mdays() || this->m_day < 1)
				{
					this->m_readErrorCode = DAY_ERROR;
				}
			}
		}
		else
		{

			is >> this->m_year >> delim1 >> this->m_mon >> delim2 >> this->m_day >> delim3 
				>> this->m_hour >> delim4 >> this->m_min;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				this->m_readErrorCode = CIN_FAILED;
			}
			else
			{
				if (this->m_year > MAX_YEAR || this->m_year < MIN_YEAR)
				{
					this->m_readErrorCode = YEAR_ERROR;
				}
				else if (this->m_mon > 12 || this->m_mon < 1)
				{
					this->m_readErrorCode = MON_ERROR;
				}
				else if (this->m_day > this->mdays() || this->m_day < 1)
				{
					this->m_readErrorCode = DAY_ERROR;
				}
				else if (this->m_hour > 23 || this->m_hour < 0)
				{
					this->m_readErrorCode = HOUR_ERROR;
				}
				else if (this->m_min > 59 || this->m_min < 0)
				{
					this->m_readErrorCode = MIN_ERROR;
				}
			}
		}
		return is;
	}

	std::ostream& Date::write(std::ostream& ostr)const 
	{
		ostr << m_year << '/';
		if (m_mon < 10)
		{
			ostr << "0" << m_mon << "/";
		}
		else
		{
			ostr << m_mon << "/";
		}
		if (m_day < 10)
		{
			ostr << "0" << m_day;
		}
		else
		{
			ostr << m_day;
		}
		if (m_dateOnly == false)
		{
			ostr << ", " << m_hour << ":" << m_min;
		}
		return ostr;
	}

	
	std::istream& operator >> (std::istream& is, Date& other)
	{
		other.read(is);
		return is;
		// TODO: insert return statement here
	}

	std::ostream& operator << (std::ostream& os, const Date& other)
	{
		other.write(os);
		return os;
		// TODO: insert return statement here
	}

	
}
