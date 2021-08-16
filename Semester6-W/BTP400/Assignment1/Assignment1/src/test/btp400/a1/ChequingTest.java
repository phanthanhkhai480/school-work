/**
 * Chequing class JUnit Testing
 * 
 * @author Carlianz Pura (02/20/2020)
*/

package test.btp400.a1;

import static org.junit.Assert.assertEquals;

import java.math.BigDecimal;

import org.junit.Test;

import com.seneca.accounts.Chequing;

public class ChequingTest {

	Chequing a = new Chequing();
	
	@Test(expected = IllegalArgumentException.class)
	public void constructorNullExceptionTest() {
		a = new Chequing(null, "A1010", 1000, 0.25, 3);
		
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void constructorNegativeServiceChargeExceptionTest() {
		a = new Chequing("Bob Ross", "A1010", 1000, -0.25, 0);
		
	}

	@Test(expected = IllegalArgumentException.class)
	public void constructorNegativeMaxTransactionExceptionTest() {
		a = new Chequing("Bob Ross", "A1010", 1000, 0.25, -3);
		
	}
	
	@Test
	  public void testNegativeWithdraw() {
		Chequing a = new Chequing("Bob Ross", "A1010", 1000, 0.25, 3);
	    boolean val = a.withdraw(-500);
	    assertEquals(false, val);
	  }
	
	@Test
	  public void testExceedMaxTransactions() {
		Chequing a = new Chequing("Bob Ross", "A1010", 1000, 0.25, 3);
		a.deposit(50);
		a.deposit(50);
		a.deposit(50);
		a.withdraw(50);
		int val = a.getCounterTransaction();
	    assertEquals(3, val);
	  }
	
	@Test
	  public void testNegativeBalance() {
		Chequing a = new Chequing("Bob Ross", "A1010", 1000, 0.25, 3);
	    boolean val = a.withdraw(1100);
	    assertEquals(false, val);
	  }
	
	@Test
	  public void testServiceCharge() {
		Chequing a = new Chequing("Bob Ross", "A1010", 1000, 0.25, 3);
		a.deposit(50);
		a.withdraw(50);
	    assertEquals(0.25, a.getTotalServiceCharge(), 0.001);
	  }
	
	@Test
	  public void testCorrectCurrentBalance() {
		Chequing a = new Chequing("Bob Ross", "A1010", 1000, 0.25, 3);
		a.withdraw(200);
		a.deposit(400);
		BigDecimal balance = a.getAccountBalance();
		BigDecimal balance2 = new BigDecimal (1200.00);
	    assertEquals(balance2, balance);
	  }
	
	@Test
	  public void testFinalBalance() {
		Chequing a = new Chequing("Bob Ross", "A1010", 1000, 0.25, 3);
		a.withdraw(200);
		a.deposit(400);
		BigDecimal balance = a.getFinalAccountBalance();
		BigDecimal balance2 = new BigDecimal (1199.75);
	    assertEquals(balance2, balance);
	  }
}
