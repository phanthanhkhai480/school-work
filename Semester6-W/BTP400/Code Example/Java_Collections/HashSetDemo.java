
// for Java 1.4 and below

import java.util.*;

public class HashSetDemo {

	public static void main( String args [] ) {


		// Java interface: Collection; Java class: HashSet
		Collection c = new HashSet();

		for (int k=1; k <= 7; k++)

			c.add( new Integer(k) );


		System.out.println( "size of the hash table: " + c.size() );

		// Java interface: Iterator
		Iterator it = c.iterator();

		while ( it.hasNext() )

		    System.out.println( it.next() );

		// duplicate elements?

		c.add( new Integer(1) );						// added?

		System.out.println( "size: " + c.size() );

		Integer z = new Integer(100);

		c.add( z );										// added?
		c.add( z );										// added?


		System.out.println( "done" + " size: " + c.size() );

		Iterator it2 = c.iterator();

		while ( it2.hasNext() )

		   System.out.println( it2.next() );

	}

}

/* Hash set:
	- a set of unique elements
	- no duplicate elements are allowed
	- performance of the operations
 */

 /* The Iterator interface allows one to visit (i.e. iterate over) all the elements in a collection.
 	One does not need to know how or where the elements are stored!
  */

