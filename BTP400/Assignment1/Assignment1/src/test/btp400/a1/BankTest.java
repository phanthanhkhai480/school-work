/**
 * Bank class JUnit Testing
 * 
 * @author Carlianz Pura (02/20/2020)
*/

package test.btp400.a1;

import static org.junit.Assert.*;

import java.math.BigDecimal;
import java.util.Arrays;

import org.junit.Test;

import com.seneca.accounts.Account;
import com.seneca.accounts.Chequing;
import com.seneca.accounts.GIC;
import com.seneca.business.Bank;

public class BankTest {

	Bank a = new Bank();
	
	@Test(expected = IllegalArgumentException.class)
	public void constructorNullExceptionTest() {
		a = new Bank(null);
		
	}
	
	@Test
	  public void testSearchByBalance() {
		Bank myNewBank = new Bank();
		myNewBank.addAccount(new Chequing("Bob Ross", "A1010", 1000, 0.25, 3));
		BigDecimal val = new BigDecimal(1000);
		Account[] actual = myNewBank.searchByBalance(val);
		Chequing[] expected = new Chequing[1];
		expected[0] = new Chequing("Bob Ross", "A1010", 1000, 0.25, 3);
		assertEquals(Arrays.toString(expected), Arrays.toString(actual));
	  }
	
	@Test
	  public void testSearchByAccount() {
		Bank myNewBank = new Bank();
		myNewBank.addAccount(new Chequing("Bob Ross", "A1010", 1000, 0.25, 3));
		String name = "Bob Ross";
		Account[] actual = myNewBank.searchByAccountName(name);
		Chequing[] expected = new Chequing[1];
		expected[0] = new Chequing("Bob Ross", "A1010", 1000, 0.25, 3);
		assertEquals(Arrays.toString(expected), Arrays.toString(actual));
	  }

	@Test
	  public void testGetTaxableAccounts() {
		Bank myNewBank = new Bank();
		myNewBank.addAccount(new GIC("Bob Ross", "A1010", 1000, 1.5, 2));
		myNewBank.addAccount(new Chequing("Mary Ryan", "A1111", 1000, 0.25, 3));
		myNewBank.addAccount(new GIC("Bob Ross2", "A1012", 2002, 1.2, 2));
		Account[] actual = myNewBank.getTaxableAccounts();
		GIC[] expected = new GIC[2];
		expected[0] = new GIC("Bob Ross", "A1010", 1000, 1.5, 2);
		expected[1] = new GIC("Bob Ross2", "A1012", 2002, 1.2, 2);
		assertEquals(Arrays.toString(expected), Arrays.toString(actual));
	  }
	
}
