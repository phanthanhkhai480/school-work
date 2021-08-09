#include<iostream>
#include<cstring>
#include "CreditCard.h"

using namespace std;
namespace sict
{
	void CreditCard::name(const char cardHolderName[])
	{
		strcpy(m_cardHolderName, cardHolderName);
	}
	void CreditCard::initialize(unsigned long long creditCardNumber, int instCode, int expiryYear, int expiryMonth, int numberInTheBack)
	{
		m_cardNumber = creditCardNumber;
		m_institutionCode = instCode;
		m_expiryYear = expiryYear;
		m_expiryMonth = expiryMonth;
		m_numberInTheBack = numberInTheBack;
	}
	bool CreditCard::isValid() const 
	{
		int count = 1, count1 = 1, count2 = 1, count3 = 1, count4 = 1, count5 = 1;
		if (strlen(m_cardHolderName) >= 1)
			count = 1;
		else
			count = 0;
		if (m_cardNumber >= MIN_CARD_NUMBER && m_cardNumber <= MAX_CARD_NUMBER)
			count1 = 1;
		else
			count1 = 0;
		if (m_institutionCode >= MIN_INST_NUMBER && m_institutionCode <= MAX_INST_NUMBER)
			count2 = 1;
		else
			count2 = 0;
		if (m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR)
			count3 = 1;
		else
			count3 = 0;
		if (m_expiryMonth >= 1 && m_expiryMonth <= 12)
			count4 = 1;
		else
			count4 = 0;
		if (m_numberInTheBack >= 000 && m_numberInTheBack <= 999)
			count5 = 1;
		else
			count5 = 0;
		if (count == 1 && count1 == 1 && count2 == 1 && count3 == 1 && count4 == 1 && count5 == 1)
		{
			return true;
		}
		return false;
	}
	void CreditCard::write(bool displayName, bool displayCardInfo) const
	{
		if (isValid() == true)
		{
			if (displayName == true && displayCardInfo == true)
			{
				cout << "Cardholder: " << m_cardHolderName << endl;
				cout << "Card Number: " << m_cardNumber << endl;
				cout << "Institution: " << m_institutionCode << endl;
				cout << "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl;
				cout << "Number at the back: " << m_numberInTheBack;
			}
			else if (displayName == false && displayCardInfo == true)
			{
				writeCardInfo();
			}
			else if (displayName == true && displayCardInfo == false)
			{
				writeName();
			}
		}
	}
	void CreditCard::writeName() const
	{
		
		{
			cout << "Cardholder: " << m_cardHolderName;
		}
	}
	void CreditCard::writeCardInfo() const
	{
		cout << "Card Number: " << m_cardNumber << endl;
		cout << "Institution: " << m_institutionCode << endl;
		cout << "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl;
		cout << "Number at the back: " << m_numberInTheBack;
	}



}
