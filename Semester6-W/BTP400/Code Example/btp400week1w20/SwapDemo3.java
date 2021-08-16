/* a demo on passing-by-value in Java
   - primitive data types
   - reference types (class, interface, array, enumeration)
     https://www.oreilly.com/library/view/java-8-pocket/9781491901083/ch04.html
   
   updated on 1/09/2020
*/

public class SwapDemo3 {


	public void swap( Employee a, Employee b ) {

	     Employee t;

	     t = a;   a = b;   b = t;

	     System.out.println( "inside swap..." );
	     System.out.println( a );
	     System.out.println( b );
	}


	public static void main(String[] args) {


		SwapDemo3 sd = new SwapDemo3();

		Employee one = new Employee( 12345, "John Doe", "70 The Pond", "1999" ),
		         two = new Employee( 98765, "Mary Green", "45 King Street", "2007");

		System.out.println( one.toString() + two.toString() );

        System.out.println( "...swap swap swap" );

		sd.swap( one, two );

		System.out.println( "...back in main" );

		System.out.println( one );
		System.out.println( two );
	}
}



