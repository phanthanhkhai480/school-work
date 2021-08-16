/**
* Main method to create a Banking app with multiple functionality
*
* @author Khai Phan (02/20/2020)
*/
//Khai   Phan; B2222; 7000.00; 0.35;4
//Khai Phan; C3333; 500; 5;3


package com.btp400;

import java.math.BigDecimal;
import java.util.Scanner;

import com.seneca.accounts.Account;
import com.seneca.accounts.Chequing;
import com.seneca.accounts.GIC;
import com.seneca.accounts.Taxable;
import com.seneca.business.Bank;

public class FinancialApp {
	public static void main(String[] args) throws Exception {
		Bank myNewBank = new Bank();
		int option = 0;
		String display = "";
		loadBank(myNewBank);
		
		while(option != 7)
		{
			displayMenu(display);
			option = menuChoice();
			
			switch (option) {
				//Open an Account (Done)
			  case 1:
			    Scanner option1 = new Scanner(System.in);
			    System.out.print("Please enter the account type (CHQ/GIC)> ");
			    String account = option1.nextLine();
			    String account_type = account.toUpperCase();
			    
			    //if user want to open a Chequing Account
			    if(account_type.equals("CHQ")) {
			    	System.out.print("Please enter account information at one line\n" + 
				    		   "(e.g. John M. Doe ; A1234 ; 1000.00 ; 0.25 ; 3) " + "\n");
				    String account_info = option1.nextLine();
				    String[] temp = account_info.split(";"); 
				    for(int a = 0; a < temp.length; a++)
				    	temp[a] = temp[a].trim().replaceAll("\\s+"," ");

				    myNewBank.addAccount(new Chequing(String.valueOf(temp[0]), String.valueOf(temp[1]), 
				    		Double.valueOf(temp[2]), Double.valueOf(temp[3]), Integer.valueOf(temp[4])));
				    System.out.println(myNewBank);
				    
				//if user want to open a GIC account
			    } else if(account_type.equals("GIC")) {
			    	 System.out.print("Please enter account information at one line\n" + 
					    		"(e.g. John M. Doe ; A1234 ; 1000.00 ; 1.5 ; 2) " + "\n");
					    String account_info = option1.nextLine();
					    String[] temp = account_info.split(";"); 
					    for(int a = 0; a < temp.length; a++) 
					    	temp[a] = temp[a].trim().replaceAll("\\s+"," ");
					    	
					    myNewBank.addAccount(new GIC(String.valueOf(temp[0]), String.valueOf(temp[1]), 
					    		Double.valueOf(temp[2]), Double.valueOf(temp[3]), Integer.valueOf(temp[4])));
					    System.out.println(myNewBank);
			    } else
			    	System.out.println("Command not accepted!" + "\n");

			    break;
			  
			    //Close an Account (Done)
			  case 2:
			    Scanner option2 = new Scanner(System.in);
			    System.out.print("Please enter account number> ");
			    String account_name2 = option2.nextLine();
			    Account temp2 = myNewBank.searchByAccountNumber(account_name2);
			    if(temp2 != null) {
			    	 System.out.print("Are you sure you want to delete account " + account_name2 + "? (Y/N)> ");
					    String checking = option2.nextLine();
					    
					    if(checking.equals("Y") || checking.equals("y")) {
					    	myNewBank.removeAccount(account_name2);
					    	System.out.println("Account deleted!" + "\n");
					    }
					    	
					    else if(checking.equals("N") || checking.equals("n"))
					    	System.out.println("Cancelled!" + "\n");
					    
					    else
					    	System.out.println("Command not accepted!" + "\n");
			    } 
			    else
					System.out.println("Account not exist!\n");
			    break;
			    
			    //Deposit Money (Done)
			  case 3:
				Scanner option3 = new Scanner(System.in);
				System.out.print("Please enter account number> ");
				String account_name3 = option3.nextLine();
				
				Account temp3 = myNewBank.searchByAccountNumber(account_name3);
				
				if(temp3 != null) {
					System.out.print("Please enter deposit amount> ");
					double mDeposit = option3.nextDouble();
					temp3.deposit(mDeposit);
				} 
				else
					System.out.println("Account not exist!\n");
				

				break;
			    
			    //Withdraw Money (Done)
			  case 4:				  
				Scanner option4 = new Scanner(System.in);
				System.out.print("Please enter account number> ");
				String account_name4 = option4.nextLine();
				
				Account temp4 = myNewBank.searchByAccountNumber(account_name4);
				
				
				if(temp4 != null) {
					double amount = 0;
					while(amount < 1) {
						System.out.print("Enter withdraw amount> ");
						amount = option4.nextDouble();
					}
					boolean checking5 = temp4.withdraw((amount));
					if(checking5)
						System.out.println("Withdraw Successfully!\n");
				} 
				
				else
					System.out.println("Account not exist!\n");

				break;
			    
			    //Display Account (Done)
			  case 5: 
			    Scanner option5 = new Scanner(System.in);
			    System.out.println("1) Display all accounts with the same account name");
			    System.out.println("2) Display all accounts with the same final balance");
			    System.out.println("3) Display all accounts opened at the bank.");
			    System.out.print("Option> ");
			    int select5 = option5.nextInt();
			    
			    if(select5 == 1) {
			    	Scanner temp_5 = new Scanner(System.in);
			    	System.out.print("Please enter account name> ");
					String account_name5 = temp_5.nextLine();
					if(!account_name5.equals("")) {
						Account[] temp5 = myNewBank.searchByAccountName(account_name5);
				    	for(int i = 0; i < temp5.length; i++)
				    		displayAccount(temp5[i]);
					}
			    }
			    
			    else if(select5 == 2) {
			    	Scanner temp_5 = new Scanner(System.in);
			    	System.out.print("Please enter account balance> ");
			    	double account_balance5 = temp_5.nextDouble();
			    	if(account_balance5 > 0) {
			    		BigDecimal balance5 = new BigDecimal(account_balance5);
			    		Account[] temp5 = myNewBank.searchByBalance(balance5);
			    		for(int i = 0; i < temp5.length; i++)
				    		displayAccount(temp5[i]);
			    	}
			    } 
			    
			    else if(select5 == 3)
			    	System.out.println(myNewBank); 
			    
			    else 
			    	 System.out.println("Command not accepted!" + "\n");

			    break;
			    
			    //Display a tax statement
			  case 6:
				  String stringName;
				  FinancialApp fp = new FinancialApp();
				  Account[] temp6 = myNewBank.getTaxableAccounts();
				  int[] counter6 = new int[(temp6.length) - 1];
				  
				  for(int a = 0; a < (temp6.length) - 1; a++) {
					  for(int b = 0; b < (temp6.length) - 1; b++) {
						  if(temp6[a].getFullName().equals(temp6[b].getFullName()))
							  counter6[a]++;
					  }
				  }
				  
				  for(int i = 0; i < temp6.length-1; i++) {
					  stringName = fp.taxStatement((Taxable)temp6[i]);
					  System.out.println("[" + counter6[i] + "]"); 
					  System.out.println(stringName); 
				  }
			    break;
			    
			    //Exit (Done)
			  case 7:
				 System.out.println("Thank You!" + "\n");
			    break; 
			}
		}
	}
	
	/**
	 * load pre-defined data into array, with 2 Chequing Accounts and 2 GIC Accounts
	 * @param bank
	 */
	static void loadBank(Bank bank) {
		bank.addAccount(new Chequing("John Doe","A1111",10000.00, 0.25, 5));
		bank.addAccount(new GIC("John Doe","D1234",6000.00, 1.5, 2));
		
		bank.addAccount(new Chequing("Mary Ryan","C0005",10000.00, 0.25, 5));
		bank.addAccount(new GIC("Mary Ryan","E1234",15000.00, 2.5, 4));
	};
	
	/**7
	 * create a display menu for user to select
	 * @param bankName 
	 */
	static void displayMenu(String bankName) {
		bankName += "Welcome to Seneca@York Bank!" 	+ "\n" +
					"1. Open an account.		 "  + "\n" +
					"2. Close an account.		 " 	+ "\n" +
					"3. Deposit money.			 "  + "\n" +
					"4. Withdraw money.			 " 	+ "\n" + 
					"5. Display account.		 "  + "\n" +
					"6. Display a tax statement. " 	+ "\n" + 
					"7. Exit.					 "  ;	
		System.out.println(bankName);
	};
	
	/**
	 * record the option user choose
	 * @return the option that user selected
	 */
	static int menuChoice() {
		int option = 0;
		Scanner select = new Scanner(System.in);  // Create a Scanner object
		System.out.print("Please enter your choice> ");
		option = select.nextInt(); 
		return option;
	};
	
	/**
	 * display account information to user
	 * @param account
	 */
	static void displayAccount(Account account) {	System.out.println(account);	};
	
	public String taxStatement( Taxable a ) {

	      return a.createTaxStatement();
	   }
}