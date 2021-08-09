#ifndef ICT_CHECKINGACCOUNT_H__
#define ICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
		private:
			double transactionFee;

			// TODO: chargeFee subtract transaction fee form the balance

		public:
			CheckingAccount(double balance, double transaction);
			// TODO: constructor initializes balance and transaction fee
			void chargeFee(double balance, double transaction);
			// TODO: Write a function prototype to override credit function
			void  credit(double money);
			// TODO: Write a function prototype to override debit function
			bool debit(double money);
			// TODO: Write a function prototype to  override display function
			std::ostream& display(std::ostream&) const;
	};
};
#endif
