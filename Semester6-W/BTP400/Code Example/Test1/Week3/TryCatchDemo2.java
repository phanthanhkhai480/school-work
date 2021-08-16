// one try block
// multiple catch blocks
// only one catch block will be used!

// command lines: java TryCatchDemo2
//                java TryCatchDemo2 34
//                java TryCatchDemo2 hi there
//                java TryCatchDemo2 hello

public class TryCatchDemo2{

	public static void main( String[] args )
	{
		int   num = 13, denom = 0, result= -9999;
		int[] array = { 22,33,44 };

		System.out.println ("...Run the code again with these three test cases: 34, 'hi, there', 'hello'" );
		try {
			 //result = num / args.length;

			 //if ( args.length == 2)

			      //result = array[ num ];

			 result = Integer.parseInt( args[0] );
		}

		catch( ArithmeticException error ){ // superclass: RuntimeException

			System.out.println( "1. Error!" );
			System.out.println( "2.\n" + error );
			result = 111;
		}

		catch( IndexOutOfBoundsException error ){ // superclass!
                                                  // RuntimeException: superclass of IndexOutOfBoundsException
			System.out.println( "3. Error!" );
			System.out.println( "4.\n" + error );
			result = 222;
		}

        catch( Exception error ) { // the superclass of all specific exceptions!!!

			System.out.println( "5. Any Error?" );
			System.out.println( "6.\n" + error );
			result = 333;
		}

		System.out.println( "...result: " + result );
		System.out.println( "...bye bye" );
	}
}