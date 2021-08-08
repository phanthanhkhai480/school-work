
// error propagation using the call stack of methods
// the code is compact and easier to understand

public class Propagate {

	static void one() {

       try {
   		    two();
   		    System.out.println( "one: hahaha" );

	       }
		   
	   catch( ArithmeticException e ) {

           e.printStackTrace();
           System.out.println( "*** one: caught here ***" );
		   
           throw new NumberFormatException(); //!!!
       }
	   
	   /* the finally block must go with a try block */
       finally { // the finally block is ALWAYS executed
                 // it is used to clean up things before
                 // the control is passed to another piece of code
			     // (e.g. close a file or close a socket connection)

		   System.out.println( ">>>one: finally block: HERE!" );
	   }

       System.out.println( "one: return to the caller" );
	}

	static void two() {

       try {
	        three();
	        System.out.println( "two:ho-ho-ho" );

           }
 	   catch( ClassCastException e ) {

            e.printStackTrace();
            System.out.println( "###two: caught here caught here ###" );
       }

       System.out.println( "two: return to the caller" );
    }

	static void three() {

	       four();

           System.out.println( "three: return to the caller" );
	}

	static void four() {

           System.out.println( "four: he he he" );

	       int m = 100 / 0;

           System.out.println( "four: return to the caller" );
        }

	public static void main( String[] args ){

        System.out.println( "main: Go For It!");

        try {
		      one();
	    }
	    catch( Exception ex ) { System.out.println( "$$$ main: caught here! $$$" );
		                        ex.printStackTrace(); }

        System.out.println( "main: The End!" );
	}
}
