// Functional Programming in Java
// Source: http://winterbe.com/posts/2014/07/31/java8-stream-tutorial-examples/

import java.util.ArrayList;
import java.util.Arrays;

public class ListStream {

    public static void main( String [] args ){
	 
	 
	   String [] words = { "apple", "bee", "aroma","coin", "bat", "celery" };
	   
       ArrayList<String> wordList = new ArrayList<String>( Arrays.asList(words) );
	   
	   // functional programming/declarative programming: "what" vs "how"
       wordList
		.stream()                           // Java 8 stream; the Collection interface
		.filter( s -> s.startsWith("b") )		//filter array that contain string start wtih b
		.map( String::toUpperCase )				//send all the found one to upperCase
		.sorted()								//sort them in order
		.forEach( System.out::println );    // terminal condition: internal iteration

	}
}