#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double interestRate; // interest rate (percentage)
		public:
			SavingsAccount(double, double);
			double calculateInterest();
			std::ostream& display(std::ostream&) const;
			// TODO: put prototypes here

   };
};
#endif
