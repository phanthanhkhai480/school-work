import java.util.*;

public class ArrayTester {
	public static void main(String[] args) throws Exception {
		
		
		//create instances variable of tester with 7 datas array
		Account tester[] = new Account[7];
		tester[0] = new Account("Peter Liu", "A12345", 5000);
		tester[1] = new Account("Peter Liu", "A67890", 6000);
		tester[2] = new Account("Abraham Lincoln", "Z6789", 7777);
		tester[3] = new Account("Peter Liu", "A12345", 5000);
		tester[4] = new Account("Khai Phan", "E3333", 9000);
		tester[5] = new Account("Abraham Lincoln", "Z6789", 7777);
		tester[6] = new Account("Abraham Lincoln", "Z6789", 7777);
		int[] m_temp = new int[tester.length]; Arrays.fill(m_temp, 1);
		boolean[] duplicated = new boolean[tester.length]; Arrays.fill(duplicated, false);
		int position = 1;
		
		
		//Account tester1[] = new Account[tester.length];
		System.out.println("COUNTING SUMMARY");
		System.out.println("+ total number of account(s): " + tester.length);
		
		//comparing the first one++ with the rest of the arrays
		 for(int a = 0; a < tester.length; a++) {
			 //take the 2nd one and onward for comparasion 
			 for(int b = a+1; b < tester.length; b++) {
				 //check if the 1st++ and 2nd++ are equals
				 if(	(tester[a].getAccountNumber().equals(tester[b].getAccountNumber() )	) &&
						(tester[a].getFullName().equals(tester[b].getFullName() )	) && 
						(tester[a].getAccountBalance() == tester[b].getAccountBalance() )	)	{
					 //check for status of the 2nd one and onward
					 if(duplicated[b] == false) {
						//set duplicated if it is duplicated
						duplicated[b] = true;
						//counter increase by 1
						m_temp[a]++;
					 }
				 }
			 }
		 }
		 
		 for(int c = 0; c < tester.length; c++){
			 if(duplicated[c] == false){
				 String rounding = String.format("%.2f", tester[c].getAccountBalance());
				 System.out.println(position + ". " + tester[c].getFullName() + ", " 
						 							+ tester[c].getAccountNumber() + ", "
						 							+ rounding + ": " + m_temp[c]);
				 position++;
			 }
		 }
	}	
}
