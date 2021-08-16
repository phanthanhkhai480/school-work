/**
 * GIC class JUnit Testing
 * 
 * @author Carlianz Pura (02/20/2020)
*/

package test.btp400.a1;

import static org.junit.Assert.assertEquals;

import java.math.BigDecimal;

import org.junit.Test;

import com.seneca.accounts.GIC;

public class GICTest {

	GIC a = new GIC();
	
	@Test(expected = IllegalArgumentException.class)
	public void constructorNullExceptionTest() {
		a = new GIC(null, "A1010", 1000, 1.25, 3);
		
	}

	@Test(expected = IllegalArgumentException.class)
	public void constructorNegativeInterestRateExceptionTest() {
		a = new GIC("Bob Ross", "A1010", 1000, -1.25, 1);
		
	}

	@Test(expected = IllegalArgumentException.class)
	public void constructorNegativeInvestmentYearExceptionTest() {
		a = new GIC("Bob Ross", "A1010", 1000, 1.25, -1);
		
	}
	/*
	@Test
	  public void testAccountNoChangeOnWithdrawDeposit() {
		GIC a = new GIC("Bob Ross", "A1010", 1000, 1.25, 1);
	    a.withdraw(-500);
	    BigDecimal val = new BigDecimal(1000);
	    assertEquals(val, a.getAccountBalance());
	  }
	*/
	
	/*
	@Test(expected = UnsupportedOperationException.class)
	  public void testAccountNoChangeOnWithdrawDeposit() {
		GIC a = new GIC("Bob Ross", "A1010", 1000, 1.25, 1);
	    a.deposit(-500);
	  }
	*/
	@Test
	  public void testFalseOnWithdraw() {
		GIC a = new GIC("Bob Ross", "A1010", 1000, 1.25, 1);
	    boolean val = a.withdraw(-500);
	    assertEquals(false, val);
	  }

	@SuppressWarnings("deprecation")
	@Test
	  public void testBalanceAtMaturity() {
		GIC a = new GIC("Bob Ross", "A1010", 1000, 1.5, 2);
		BigDecimal balance = a.getAccountBalance();
		BigDecimal balance2 = new BigDecimal ("1030.22");
		balance2.setScale(2, BigDecimal.ROUND_HALF_EVEN);
	    assertEquals(balance2, balance);
	  }
	
	@Test
	  public void testInterestIncome() {
		GIC a = new GIC("Bob Ross", "A1010", 1000, 1.5, 2);
		double val1 = a.getInterestIncome();
		double val2 = 30.22;
	    assertEquals(val2, val1, 0.001);
	  }
}
