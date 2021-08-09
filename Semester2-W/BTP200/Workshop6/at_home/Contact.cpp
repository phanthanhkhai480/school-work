#include<iostream>
#include<cstring>
#include "Contact.h"
using namespace std;
namespace communication
{
	Contact::Contact()
	{
		this->m_name[0] = '\0';
		this->m_noOfPhoneNumbers = 0;
		this->m_phoneNumbers = nullptr;
	}

	bool Contact::isEmpty() const
	{
		if (this->m_name[0] == '\0' && this->m_noOfPhoneNumbers == 0 && this->m_phoneNumbers == nullptr)
		{
			return true;
		}
		return false;
	}

	Contact::Contact(const char* name, long long* phoneNumber, int numberOfPhone)
	{
		int count = 0;
		if (name != nullptr) 
		{
			strncpy(m_name,name,21);
			
			if(strlen(name) >= 21)
				m_name[20] = '\0';

			if (strlen(name) > 0 && phoneNumber != nullptr) {
				m_phoneNumbers = new long long[numberOfPhone];
				for (int counter = 0; counter < numberOfPhone; counter++)
				{
					if (phoneNumber[counter] >= 10000000000 && phoneNumber[counter] < 1000000000000)
					{
						m_phoneNumbers[count] = phoneNumber[counter];
						count++;
					}
				}
				m_noOfPhoneNumbers = count;
			}
			else {
				this->m_noOfPhoneNumbers = 0;
				this->m_phoneNumbers = nullptr;
			}
		}
		else
		{
			this->m_name[0] = '\0';
			this->m_noOfPhoneNumbers = 0;
			this->m_phoneNumbers = nullptr;
		}	
		
	}

	int Contact::getCountryCode(long long phonenumber) const
	{
		return (phonenumber / 10000000000);
	}

	int Contact::getAreaCode(long long phonenumber) const
	{
		return (((phonenumber % 10000000000) / 10000000) % 1000);
	}

	int Contact::getNumberLeft(long long phonenumber) const
	{
		return ((phonenumber / 10000) % 1000);
	}

	int Contact::getNumberRight(long long phonenumber) const
	{
		return ((phonenumber % 10000000000) % 10000);
	}

	Contact::~Contact()
	{
		if (m_phoneNumbers != nullptr)
		{
			delete[] m_phoneNumbers;
		}
	}

	void Contact::display() const
	{
		if (isEmpty() == true)
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << m_name << endl;
			if (m_phoneNumbers != nullptr)
			{
				for (int counter = 0; counter < m_noOfPhoneNumbers; counter++)
				{
					cout << "(+" << getCountryCode(m_phoneNumbers[counter]) << ")" << " "
						<< getAreaCode(this->m_phoneNumbers[counter]) << " "
						<< getNumberLeft(this->m_phoneNumbers[counter]) << "-"
						<< getNumberRight(this->m_phoneNumbers[counter]) << endl;
				}
			}
		}
	}

	
	
	Contact::Contact(const Contact& other)
	{
		//copy constructor
		m_phoneNumbers = nullptr;
		*this = other;
		
	}

	Contact& Contact::operator=(const Contact& other)
	{
		//copy assignment operator
		//have to have if copy constructor exist
		if(this != &other)
		{
			int counter = 0;
			for (counter = 0; counter < 20; counter++)
			{
				m_name[counter] = other.m_name[counter];
			}
			m_name[counter] = '\0';
			m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
			delete[] m_phoneNumbers;
			if (other.m_phoneNumbers != nullptr)
			{
				m_phoneNumbers = new long long[m_noOfPhoneNumbers];
				for (int i = 0; i < m_noOfPhoneNumbers; i++)
				{
					m_phoneNumbers[i] = other.m_phoneNumbers[i];
				}
			}
			else
			{
				m_phoneNumbers = nullptr;
			}
		}
		return *this;
	}


	void Contact::addPhoneNumber(long long phoneNumber)
	{
		long long* temp = new long long[m_noOfPhoneNumbers + 1];
		for (int counter = 0; counter < m_noOfPhoneNumbers; counter++)
		{
			temp[counter] = m_phoneNumbers[counter];
		}
		temp[m_noOfPhoneNumbers++] = phoneNumber;
		delete[] m_phoneNumbers;
		m_phoneNumbers = temp;
	}
	
}






















