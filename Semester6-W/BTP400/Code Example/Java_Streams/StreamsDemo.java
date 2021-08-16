import java.util.*;
import java.util.stream.*;

// Source: Cay Horatmann

class StreamsDemo{

    public static void main(String args[]){
	
	   List<String> words = new ArrayList<>();
	   
	   words.add( "BTP400" ); words.add("JAVA"); words.add("StReaM API");
	   words.add( "Java 9" ); words.add( "C++");
	   
	   /* 1 */
	   
	   // use of a sequential stream
	   // a pipeline of two aggregate operations
	   
	   long wordCount = words.stream()       // the data source of a stream
              .filter(w -> w.length() > 4)   // the Stream API: an intermediate operation
              .count();                      // the Stream API: a terminal operation
			  
	   System.out.println( "word count: " + wordCount );
	   
	   /* 2 */
	   List<String> lowercaseWords = words.stream()
          .map(String::toLowerCase)
          .collect(Collectors.toList());
		  
	   System.out.println( lowercaseWords );
		  
	   /* 3 */
	   
	   // Integer [], not int []!
	   Integer [] integerArray = { 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12 };
	   
       Collection<Integer> values = Arrays.asList(integerArray);

       Integer sum = values.stream()
                            .reduce(0, (x, y) -> x + y);
							
	   System.out.println( "sum = " + sum );
	   

	}
}