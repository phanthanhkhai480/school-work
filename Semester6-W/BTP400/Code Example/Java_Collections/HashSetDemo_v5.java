
/* Hash set:
	- a set of unique elements
	- no duplicate elements are allowed
	- a set, backed by a hash table (HashMap instance)
	- performance of the operations
 */

 /* The Iterator interface allows one to visit (i.e. iterate over) all the elements in a collection.
 	One does not need to know how or where the elements are stored!
  */

import java.util.*;

public class HashSetDemo_v5 {

	public static void main( String args [] ) {


		// Java interface: Collection; Java class: HashSet
		
		// with duplicates
		String [] dataArray = { "java", "JDK", "python", "java", "JDK" };
		
		List<String> aList = Arrays.asList(dataArray);
		
		// no duplicates
		HashSet <String> c = new HashSet <>(aList);

		System.out.println( "1. size of the HashSet: " + c.size() );

		// Java interface: Iterator
		Iterator it = c.iterator();

		while ( it.hasNext() )

		    System.out.println( it.next() );

		// add duplicate elements?
		c.add( new String("java") );						// added?
		c.add( new String("java") );
		c.add( new String("java") );

		System.out.println( "2. size: " + c.size() );

		Iterator it2 = c.iterator();

		while ( it2.hasNext() )

		   System.out.println( it2.next() );
	}

}



