#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

namespace ict{

	class Account{
		private:
			double balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:
			// TODO: Write a prototype for constructor which initializes balance
			Account();
			Account(double m_balance);
			// TODDO: Write a function prototype for the virtual function credit
			virtual void credit(double money);
			// TODO: Write a function prototype for the virtual function debit
			virtual bool debit(double money);
			// TODO: Write a function prototype for the virtual function display
			virtual std::ostream& display(std::ostream&) const = 0;
   };
};
#endif
