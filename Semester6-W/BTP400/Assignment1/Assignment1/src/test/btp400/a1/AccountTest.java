/**
 * Account class JUnit Testing
 * 
 * @author Carlianz Pura (02/20/2020)
*/

package test.btp400.a1;

import org.junit.Test;

import com.seneca.accounts.Account;

public class AccountTest {
	Account a = new Account();
	
	@Test(expected = IllegalArgumentException.class)
	public void constructorNullExceptionTest() {
		a = new Account(null, "A1010", 1000);
		
	}

	@Test(expected = IllegalArgumentException.class)
	public void constructorNegativeExceptionTest() {
		a = new Account("Bob Ross", "A1010", -1000);
		
	}
}
