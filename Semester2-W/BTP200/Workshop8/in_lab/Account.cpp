#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	Account::Account()
	{
		this->balance = 0;
	}
	Account::Account(double m_balance)
	{
		this->balance = m_balance;
		if (this->balance < 0)
			this->balance = 0;
	}
	// credit (add) an amount to the account balance
	void Account::credit(double money)
	{
		balance += money;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double money)
	{
		if (money <= this->balance)
		{
			balance -= money;
			return true;
		}
		else
			return false;
	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}