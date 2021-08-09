/* Author	: Khai Phan
Date	: Oct. 17, 2016
Revision: 
Template Credit: Dr. Elnaz Depisheh
Workshop: #6 in-Lab */

#include <stdio.h>
#define MAX 5 
struct account
{
	long account_number;				
	double balance;				
};
void clear(void);
void clear(void)
{
	while (getchar() != '\n');
}
// Function to add an amount if positive-valued //Option 1
double balanceUp(double balance, double amount)
{
    if (amount > 0 )
        balance = balance + amount;
    return balance;
}


// Function to calculate the interest rate //Option 3
double interestCalc(double balance, double rate)
{
	double result;        
		result = balance*(rate/100);
    return result;
}


//Function to calculate service fee //Option 2
double balanceDown(double balance, double amount)
{
	int balance2;
	if (amount > 0 )
        balance2 = balance - amount;
    return balance2;
}


int main()
{
	const int nosClients = 5;							// Number of accounts
	int option, counter;
	long account_number;
	double amount, rate, charge, balance, balance2, result, result2, result3, fee;
	struct account Account[MAX] = { { 11111111, 123.45 },{ 22222222, 12365.50 },{ 33333333,0 },{ 44444444,1475 },{ 55555555,25000.65 } };
	printf("***** Welcome to Savings Account Banking *****\n\n");
	do
	{
		printf("1.) Deposit \n");
		printf("2.) Withdraw\n");
		printf("3.) Apply monthly interest earnings to all accounts\n");
		printf("4.) Apply service charges to all accounts\n");
		printf("5.) Account Summary\n");
		printf("0.) Log out\n\n");
		
		printf("Please enter an option to continue: ");
		scanf("%d",&option);
		
		switch (option)
		{
		case 0: // Exit the program
			break;

                
                
		case 1: //Deposit Money
			printf("-- Make	a deposit --\n Type your bank Account Number (8-digits):");
			scanf("%ld", &account_number);
				for (counter = 0; counter < MAX; counter++){
					if (account_number == Account[counter].account_number){	
						printf("The account %8ld has %.3lf dollar\n", Account[counter].account_number, Account[counter].balance);
						printf("Enter amount of money to deposit(CAD):");
						scanf("%lf", &amount);
						clear();
						balance = balanceUp(Account[counter].balance, amount);
						Account[counter].balance = balance;
						printf("The account balance is now %lf\n", Account[counter].balance);
						counter = MAX;
						}
					else
					printf("The account does not exist\n");
					counter = MAX + 1;
				}
				
			break; 

                
                
		case 2: // Withdraw funds
				printf("-- Withdrawal Fund --\n Type your bank Account Number (8-digits):");
				scanf("%ld", &account_number);
				for (counter = 0; counter < MAX; counter++){
				if (account_number == Account[counter].account_number){	
					printf("The account %8ld has %.3lf dollar\n", Account[counter].account_number, Account[counter].balance);
					printf("Enter amount of money to withdrawal(CAD):");
					scanf("%lf", &amount);
					if (amount > Account[counter].balance)
					{ 
						printf("Unable to process, Exceed Balance\n");
						break;	} 
					else
					{	
					balance2 = balanceDown(Account[counter].balance, amount);
					Account[counter].balance = balance2;
					printf("The account balance is now %lf\n", Account[counter].balance);
					counter = MAX +1; }
					}
				else
					printf("The account does not exist\n");
				}
				
			break;

           
		case 3: // Apply interest earnings to all accounts
				printf("Account#    New	Balance	  Interest Earnings(M)\n");
				printf("--------   	-----------   ---------------------\n");
				
				for (counter = 0; counter < MAX; counter++){
					if (balance <= 500){
						rate = 0.99;
						Account[counter].balance = Account[counter].balance + interestCalc(Account[counter].balance, rate);
					}
					else if (balance > 500 && balance <= 1500){
						rate = 1.66;
						Account[counter].balance = Account[counter].balance + interestCalc(Account[counter].balance, rate);
					}
					else{
						rate = 2.49;
						Account[counter].balance = Account[counter].balance + interestCalc(Account[counter].balance, rate);
					}
					result2 = interestCalc(Account[counter].balance, rate);
				
					printf("%ld     %.3lf     	%.3lf\n", Account[counter].account_number, Account[counter].balance, result2);
				}
			break; 

                
                
		case 4: // Apply Service Charges
				printf("-- Apply service charges to all accounts --\n");
				printf("Account#  		New Balance  		Service charges(M)\n --------  		-----------  		--------------\n");
                for (counter = 0; counter < MAX; counter++){
					if (Account[counter].balance <= 1500 && Account[counter].balance > 7.5)
					{
						fee = 7.5; 
						Account[counter].balance = Account[counter].balance - 7.5 ; 
					}
					else if (Account[counter].balance > 1500)
					{	
						fee = 2.5;
						Account[counter].balance = Account[counter].balance - 2.5;						; 
					}
				printf("%8ld	   %11.2lf     %19.2f\n", Account[counter].account_number, Account[counter].balance, fee);
				}
            break;

                
                
		case 5: // Display Account Information
                printf("Account#	Balance\n-------- 	----------\n");
				for(counter = 0; counter < MAX; counter++)
                printf("%ld 		%.3lf\n", Account[counter].account_number, Account[counter].balance);
			break; 

		default:
			printf("Error: Please enter a valid option to continue\n");
			break;
		}
	} while (option != 0);
		printf("Invalid.");

	return 0;
}