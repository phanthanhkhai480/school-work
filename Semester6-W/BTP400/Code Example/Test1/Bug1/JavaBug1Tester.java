/**
   @author Igor Krasnyanskiy
   @see <a href="http://www.vogella.com/tutorials/JavaIntroduction/article.html">Vogel's Tutorial</a>
*/

/* Debugging task: Identify three bugs.
   1. Igor's question: What will happen to Jim Knof's address?
   2. Harika's bug: NullPointerException! 
   
   updated on 1/23/2020
 */
public class JavaBug1Tester {
	public static void main(String[] args){
	
		Person pers = new Person("Jim", "Knopf", 31);
		
		pers.setAge(32);
		
		//System.out.println( pers );  // Warning: Where is the Address object?
		
		Address address = new Address();
		
		address.setCity("Heidelberg");
        address.setCountry("Germany");
        address.setNumber("104");
        address.setPostalCode("69214");
        address.setStreet("Musterstr.");
		
		pers.setAddress(address);
		
		System.out.println( pers );
		
		address = null;
		pers.setAddress(address);
		
		// Question 2: What is going to happen here?
		// this will set the address.number to 105 and replace what it has before,
		// NOTE: this was place at the end of the function before, therefore it has no use
		// so I move it here to see if the value change or not (it changed)
		pers.getAddress().setNumber("105");
		 
		// Question 1: What will happen to Jim Knof's address?
		// since the passing value already stored in the Person as well as the Address,
		// changing the address to null will lead to NullPointerException
		System.out.println( pers );
		
		
	}
}