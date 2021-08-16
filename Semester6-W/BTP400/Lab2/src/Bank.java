import java.util.*;

public class Bank {
	private ArrayList<Account> m_bank;
	private String bank_name;
	
	/**
	 * default/no-argument constructor
	 * set bank_name to default 
	 * @return nothing
	 */
	public Bank() {
		this("Seneca@York");
		m_bank = new ArrayList<Account>();
	}	
	
	/**
	 * one argument constructor
	 * @param bank_name contains Bank Name for the program
	 * @return nothing
	 */
	public Bank(String m_bank_name) {
		this.bank_name = m_bank_name;
		m_bank = new ArrayList<Account>();
	}	

	/**
	 * addAccount function will check for an existing duplicate account number and avoid adding
	 * @param newAccount contains Account type to be add into ArrayList of m_bank
	 * @return boolean if added successfully
	 */
	public boolean addAccount(Account newAccount) {
		boolean m_add = false;
		
		if(newAccount.getFullName().equals("") || 
		   newAccount.getAccountNumber().equals("") ||
		   newAccount.getAccountBalance() < 0) {
			return false;
		}
		
		if(m_bank.size() == 0) {
			m_add = true;
		}
		else {
			for(int a = 0; a < m_bank.size(); a++) {
				//loop in each m_bank position and fetch the data
				//convert it into Account type
				Account temp = m_bank.get(a);
				
				//check if an existing account number is exist
				if(newAccount.getAccountNumber().equals(temp.getAccountNumber())	)
					return false;
				
				//if doesn't, add the account
				else
					m_add = true;
			}
		}
		if(m_add == true) {
			m_bank.add(newAccount);
		}
		return m_add;
	}	
	
	/**
	 * toString method, display the value
	 * @return nothing
	 */
	public String toString() {
	   	  int m = m_bank.size();
	   	  String s = "*** Welcome to the Bank of " + this.bank_name + " ***\n" ;
	   	  s += "It has " + m + " account(s)\n";
	   	  for (int a = 0; a < m; a++) {
	   		  Account temp = m_bank.get(a);
	   		  s += a+1 + ". number: " + temp.getAccountNumber() + 
	   				  	 ", name: " + temp.getFullName() + 
	   				  	 ", balance: $" + temp.getAccountBalance() + "\n"; 
	   	  }
	   	  return s;
	   }
	
	/**
	 * equals method, compare the passing value with the stored value
	 * @param contains string of bank name
	 * @param instance of Object class to be compare
	 * @return boolean if Object is match or not
	 *  	
	 */
	//check equals for 2 Bank object
	public boolean equals(Object tester){
		boolean check = false;

		if ( tester instanceof Bank ) {
			Bank z2 = (Bank) tester;
			if ( ( z2.getBank_name().equals(this.bank_name)) &&
			     (z2.m_bank.equals(this.m_bank))	)
			     check = true;
		}
		return check;
	}
	
	/**
	 * 
	 * @param m_balance
	 * @return array of position where the account balance is match with m_balance
	 */
	public int[] searchByBalance (int m_balance) {
		//initialize an array of matching account found
		int m_result[] = new int[m_bank.size()];
		
		//initialize the position of the array
		int position = 0;
		
		//check for possible matching account
		for(int a = 0; a < m_bank.size(); a++) {
			Account temp = m_bank.get(a);
			if(temp.getAccountBalance() == m_balance) {
				m_result[position] = a;
				position++;
			}
		}

		//int temp = m_result.length;
		int[] m_temp = new int[position];
		for(int b = 0; b < position; b++) {
			m_temp[b] = m_result[b];
		}
		
		if(m_temp.length == 0)
			System.out.println("\n*** NO ACCOUNT FOUND ***");
		else if(m_temp[1] > 0) {
			System.out.println("We have found " + m_temp.length + " account(s) whose balance is $" + m_balance);
			for(int c = 0; c < m_temp.length; c++) {
				Account test = m_bank.get(m_temp[c]);
				System.out.println(c+1 + ". number: " + test.getAccountNumber() + ", name: " + test.getFullName()); 
			}
		}	
		
		//return result
		//if no result is found, array length automatically will be 0
		return m_temp;
	}
	
	public ArrayList<Account> sortAscending() {         
	    Collections.sort(this.m_bank);        
	    return this.m_bank;     
	  }    
	
	/**
	 * bank_name getter
	 * @return bank_name String value
	 */
	public String getBank_name() {
		return bank_name;
	}

	/**
	 * bank_name setter
	 * @param m_name contain bank_name to be passed into current bank_name var
	 */
	public void setBank_name(String m_name) {
		this.bank_name = m_name;
	}
	
}
