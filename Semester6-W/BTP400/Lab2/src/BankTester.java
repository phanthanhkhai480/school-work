

public class BankTester {
	public static void main(String[] args) {
		Bank m_bank = new Bank("Khai Phan");
		
		String accountNames[] = {   "John Doe", "Mary Ryan", "Peter Liu","John Doe", "Peter Liu" };
		String accountNumbers[] = { "A1234",    "B5678",     "C9999",    "A1234",    "D8901" };
		int accountBalances[] = {    1000,       3000,        5000,       7000,       3000 };
		Account tester[] = new Account[5];
		
		//display for test case a)
		System.out.println(m_bank);
		
		//add Account elements into m_bank type
		for(int a = 0; a < tester.length; a++) {
			tester[a] = new Account(accountNames[a], accountNumbers[a], accountBalances[a]);
			m_bank.addAccount(tester[a]);
		}
		
		//display for test case b)
		System.out.println(m_bank);
		
		//display for test case c)
		//call addAccount with a null reference
		//remember, the value when create the temp has been initialized from null to ""
		Account temp = new Account(null, null, -1);
		System.out.println("Adding Account(null, null, -1)...: " + m_bank.addAccount(temp) + "\n");
		
		//display for test case d)	
		m_bank.searchByBalance(3000);
		
		//display for test case e)
		m_bank.searchByBalance(-1111);
		
		//displaying for test case 3)
		System.out.println(m_bank.equals(m_bank));

		m_bank.sortAscending();
		System.out.println("\n" + m_bank);
		
		
		
	}

}
