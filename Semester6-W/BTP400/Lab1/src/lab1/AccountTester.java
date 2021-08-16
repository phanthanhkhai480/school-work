package lab1;

public class AccountTester {
	public static void main(String[] args) {
		Account tester1 = new Account(null,null,-1);
		Account tester2 = new Account("Khai Phan", "100901164", 1000);
		Account tester3 = new Account("Peter Liu", "TD12345", 1000.99);
		System.out.println(tester1);
		System.out.println(tester2);
		System.out.println(tester3);
	}
}
