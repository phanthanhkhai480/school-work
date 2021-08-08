
public class AccountTester {
	public static void main(String[] args) {
		//using regular constructor to passing values
		Account tester[] = new Account[3];
		tester[0] = new Account(null,null,-1);
		tester[1] = new Account("Khai Phan", "100901164", 1000);
		tester[2] = new Account("Peter Liu", "TD12345", 1000.99);
		for(int a = 0; a < tester.length; a++){
			System.out.println(tester[a]);
		}
		
		for(int b = (tester.length-1); b >= 0; b--){
			if(tester[2].equals(tester[b])){
				System.out.println("two objects have the same data contents");
			}
			else{
				System.out.println("two objects do NOT have the same data contents");
			}
		}
	}
}
