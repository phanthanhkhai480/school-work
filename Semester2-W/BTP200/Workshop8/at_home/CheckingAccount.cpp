#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here  

	CheckingAccount::CheckingAccount(double balance, double transaction)
	{
		setBalance(balance);
		this->transactionFee = transaction;
		if (this->transactionFee < 0)
			this->transactionFee = 0;
	}

	void CheckingAccount::chargeFee(double balance, double transaction)
	{
		balance -= this->transactionFee;
	}

	void CheckingAccount::credit(double money)
	{
		//chargeFee(money, this->transactionFee);
		Account::credit(money);
	}

	bool CheckingAccount::debit(double money) 
	{
		bool one = Account::debit(this->transactionFee);
		bool two = Account::debit(money);
		bool three = Account::debit(this->transactionFee);
		if (one == true && two == true && three == true)
			return getBalance();
		else
			return money;
	}

	std::ostream & CheckingAccount::display(std::ostream &os) const
	{
		os << "Account type: Checking" << endl;
		os.setf(ios::fixed);
		os.precision(2);
		os << "Balance: $ " << getBalance() << endl;
		os << "Transaction Fee: " << this->transactionFee << endl;
		return os;
		// TODO: insert return statement here
	}

}