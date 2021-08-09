#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "Error.h"

namespace ict
{
	Error::Error()
	{
		this->m_message = nullptr;
	}

	Error::Error(const char * errorMessage)
	{
		this->m_message = nullptr;
		message(errorMessage);
	}

	Error::Error(const Error& em)
	{
		m_message = nullptr;
		*this = em;
	}

	Error::~Error()
	{
		delete[] this->m_message;
	}

	Error& Error::operator=(const Error& em)
	{
		if (this != &em)
		{
			int counter = 0;
			for (counter = 0; counter < 20; counter++)
			{
				m_message[counter] = em.m_message[counter];
			}
			m_message[counter] = '\0';
			delete[] m_message;
		}
		return *this;
	}

	void Error::operator=(const char* errorMessage)
	{
		clear();
		message(errorMessage);
	}

	void Error::clear()
	{
		delete[] m_message;
		this->m_message = nullptr;
	}

	bool Error::isClear() const
	{
		if (this->m_message == nullptr)
			return true;
		return false;
	}

	void Error::message(const char* value)
	{
		delete[] this->m_message;
		int len = strlen(value);
		this->m_message = new char[len + 1];
		strcpy(this->m_message, value);
	}

	Error::operator const char*() const
	{
		return (char *)&this->m_message;
	}

	Error::operator bool() const
	{
		if (this->m_message == nullptr)
			return true;
		return false;
	}

	std::ostream& Error::write(std::ostream& os) const
	{
		os << m_message;
		return os;
	}

	std::ostream& operator<< (std::ostream& os, const Error& error)
	{
		if (error.isClear() == false)
		{
			error.write(os);
		}
		return os;
		// TODO: insert return statement here
	}

}