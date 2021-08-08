// Source of ideas: Deitel & Deitel

// Java Streams (functional programming)
// - stream pipelines
// - terminal Stream operations
// - intermediate Stream operations
// - Warning: Java streams CANNOT be reused.

/* IntStream (API): Java Interface
   - A sequence of primitive int-valued elements supporting sequential and 
     parallel aggregate operations. This is the int primitive specialization 
	 of Stream. 

 */
import java.util.stream.IntStream;

public class IntStreamLambda {

   public static void main( String args [] ){
   
       int [] dataSet = { 99, 88, 77, 66, 55, 44, 33, 22,11 };
	   
	   // a stream pipeline (functional programming)
	   IntStream.of( dataSet )     // convert the array into a stream of integers 
	            .forEach( element -> System.out.print( element + " " ) ); 
				          // lambda expression
				          // functional interface: IntConsumer + accept(int value)
				
	   System.out.println();
	   
	   // reduce the stream of integers to its sum
	   // - reduce: a terminal Stream operation
	   System.out.println( "sum: " +
	      IntStream.of( dataSet )
	                .reduce( 0, (one, two) -> one + two ) ); 
					         // lambda expression
					         // functional interface: IntBinaryOperator + 
							 //                       applyAsInt(int left, int right)
					
	   // intermediate stream operations
	   // - map the stream of integers into (n/11)
	   // - select odd integers from the new stream (filter)
	   System.out.println( "... map all the elements to (n/11) and select odd integers" );
	   
	   IntStream resultStream
	      = IntStream.of( dataSet )
	                 .map( x -> x/11 )  // functional interface: IntUnaryOperator
			         .filter( y -> y % 2 != 0 );
					         // functional interface: IntPredicate

	   double avg = resultStream.average().orElse(0.0); // average(): a terminal operation
       System.out.println( "average: " + avg );	
	   
	   /* run-time error:
	   Exception in thread "main" java.lang.IllegalStateException: stream has already 
	   been operated upon or closed
        at java.util.stream.AbstractPipeline.evaluate(Unknown Source)
        at java.util.stream.IntPipeline.collect(Unknown Source)
        at java.util.stream.IntPipeline.average(Unknown Source)
        at IntStreamLambda.main(IntStreamLambda.java:53)
		*/
		// resultStream.forEach( z -> System.out.print( z + " " ) );
       
	   // streams cannot be reused
       System.out.println( "sorted sequence:" );
	   IntStream.of( dataSet )
	            .map( x -> x/11 ) 
			    .filter( y -> y % 2 != 0 )
				.sorted() // intermediate operation
                .forEach( m -> System.out.print( m + " " ) );	// terminal operation   
   }
}