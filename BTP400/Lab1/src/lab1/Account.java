/**
* Application to display user information
* with associated bank account and their account balance
*
* @author Khai Phan (01/13/2020)
*/
package lab1;

public class Account {
	private String full_name = "";
	private String account_number = "";
	private double account_balance = 0;
	
	/**
	 * default constructor with no arguments
	 * @return nothing
	 */
	public Account() {
		this.full_name = "";
		this.account_number = "";
		this.account_balance = 0;
	}

	/**
	 * constructor with 3 arguments
	 * @param fullname contains user's full name
	 * @param accountNumber contain user's account number
	 * @param accounBalance contain user's balance with associated account
	 * @return nothing
	 */
	public Account(String fullName, String accountNumber, double accountBalance) {
		if(fullName == null)
			this.full_name = "";
		else
			this.full_name = fullName;
		
		if(accountNumber == null)
			this.account_number = "";
		else
			this.account_number = accountNumber;
		
		if(accountBalance < 0)
			this.account_balance = 0;
		else
			this.account_balance = accountBalance;
	}
	
	
	/**
	 * toString method, display the value
	 * @return nothing 
	 */
	
	public String toString(){
		String s;
		String rounding = String.format("%.2f", this.account_balance);
	       s =  "Account Name  : " + this.full_name + "\n" +
	    		"Account Number: " + this.account_number + "\n" +
	            "Balance       : $" + rounding + "\n\n";
	       return s;
	}
	
	
	/**
	 * full_name getter
	 * @return full_name string
	 */
	public String getFullName(){
		return this.full_name;
	}
	/**
	 * account_number getter
	 * @return account_number string
	 */
	public String getAccountNumber(){
		return this.account_number;
	}
	/**
	 * account_balance getter
	 * @return account_balance value
	 */
	public double getAccountBalance(){
		return this.account_balance;
	}
	/**
	 * full_name setter
	 * @param name contain  to be setted into current full_name
	 */
	public void setFullName(String name){
		this.full_name = name;
	}
	/**
	 * account_number setter
	 * @param accNum contain account number to be setted into current account_number
	 */
	public void setAccountNumber(String accNum){
		this.account_number = accNum;
	}
	/**
	 * account_balance setter
	 * @param accBalance contain account balance to be setted into current account_balance
	 */
	public void setAccountBalance(double accBalance){
		this.account_balance = accBalance;
	}
	
}
