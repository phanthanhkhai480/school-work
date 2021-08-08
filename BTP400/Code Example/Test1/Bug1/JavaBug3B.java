
// Java Bug #3B (Source: Brian)

// raw type: the default type of the elements 

import java.util.ArrayList;

public class JavaBug3B {

	public static void main(String args []) {

		ArrayList alist = new ArrayList();
		
		alist.add( new Account("A123", 100) );
		alist.add( new Account("B456", 200) );
		alist.add( new Account("C789", 300) );
		
		// an enhanced for loop
		//for ( Object s: alist)  // vs (String s: alist)
		      //System.out.println( s );
		
		// this will display all the balance belong to alist account,
		// from a123 -> b456 -> c789
		for (int k=0; k < alist.size(); k++)

             System.out.println( alist.get(k).getBalance() );
   }

}

// an incomplete Java class
class Account {
	private String accountNumber;
	private int    balance;
	
	public Account() { this("", 0); }
	
	public Account(String id, int amount){
		accountNumber = id;
		balance = amount;
	}
	
	// toString() method: NOT OVERRIDEN!
	
	int getBalance() { return balance; }
	
	// MORE CODE NEEDED...
}