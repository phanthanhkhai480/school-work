import java.math.BigDecimal;

/**
* Application to display user information
* with associated bank account and their account balance
*
* @author Khai Phan (01/13/2020)
*/
public class Account implements Comparable<Account> {
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
		//this("","",0);
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
	public String toString() {
		String s;
		String rounding = String.format("%.2f", this.account_balance);
	       s =  "Account Name  : " + this.full_name + "\n" +
	    		"Account Number: " + this.account_number + "\n" +
	            "Balance       : $" + rounding + "\n ";
	       return s;
	}
	
	/**
	 * equals method, compare the passing value with the stored value
	 * @param instance of Account class
	 * @return boolean
	 */
	@Override
	public boolean equals(Object acc) {
		if(this == acc)
			return true;
		if(acc == null)
			return false;
		if(this.getClass() != acc.getClass())
			return false;
		
		Account acc2 = (Account)acc;
		BigDecimal amount1 = new BigDecimal(acc2.account_balance);
		BigDecimal amount2 = new BigDecimal(this.account_balance);
		return ((acc2.full_name.equals(this.full_name)) && 
				(acc2.account_number.equals(this.account_number)) && 
				(amount1 == amount2)); 
	}
	
	/**
	 * hashCode method, use to calculate all the variable value altogether
	 * @return value integer support for equals()
	 */
	@Override
	public int hashCode() {
		return (int) (this.full_name.hashCode() * this.account_number.hashCode() * (double)account_balance);
	}
	
	@Override
	public int compareTo(Account temp) {
		int m_compare = temp.getAccountNumber().compareTo(account_number);
		//System.out.println(temp.getAccountNumber() + " - " + this.account_number + " = " + m_compare);
		return m_compare;
	}
	
	/**
	 * full_name getter
	 * @return full_name string
	 */
	public String getFullName() {
		return this.full_name;
	}
	/**
	 * account_number getter
	 * @return account_number string
	 */
	public String getAccountNumber() {
		return this.account_number;
	}
	/**
	 * account_balance getter
	 * @return account_balance value
	 */
	public double getAccountBalance() {
		return this.account_balance;
	}
	/**
	 * full_name setter
	 * @param name contain to be passed into current full_name
	 */
	public void setFullName(String name) {
		this.full_name = name;
	}
	/**
	 * account_number setter
	 * @param accNum contain account number to be passed into current account_number
	 */
	public void setAccountNumber(String accNum) {
		this.account_number = accNum;
	}
	/**
	 * account_balance setter
	 * @param accBalance contain account balance to be passed into current account_balance
	 */
	public void setAccountBalance(double accBalance) {
		this.account_balance = accBalance;
	}

}
