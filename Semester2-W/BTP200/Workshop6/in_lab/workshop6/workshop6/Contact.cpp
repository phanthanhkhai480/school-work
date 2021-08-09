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
		//getcountryCode by divided 10 000 000 000
	}

	int Contact::getAreaCode(long long phonenumber) const
	{
		return (((phonenumber % 10000000000) / 10000000) % 1000);
		//getAreaCode by divided 10 000 000 000 and extracted last 3 digits
	}

	int Contact::getNumberLeft(long long phonenumber) const
	{
		return ((phonenumber / 10000) % 1000);
		//getNumberLeft by divided 10 000 and extracted last 3 digits
	}

	int Contact::getNumberRight(long long phonenumber) const
	{
		return ((phonenumber % 10000000000) % 10000);
		//getnumberRight extract the last 3 digits
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
}






















