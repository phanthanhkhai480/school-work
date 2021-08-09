#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here

	SavingsAccount::SavingsAccount(double moneyBalance, double interest)
	{
		setBalance(moneyBalance);
		this->interestRate = interest;
		if (this->interestRate < 0)
			this->interestRate = 0;
	}

	double SavingsAccount::calculateInterest()
	{
		return this->interestRate*getBalance();
	}
	ostream & SavingsAccount::display(ostream & os) const
	{
		os << "Account type: Saving" << endl;
		os.setf(ios::fixed);
		os.precision(2);
		os << "Balance: $ " << getBalance() << endl;
		os << "Interest Rate (%): " << (interestRate * 100) << endl;
		return os;
		// TODO: insert return statement here
	}	
}