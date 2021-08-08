
// for Java 1.4 and below

/* Linked List:
	- duplicate elements are allowed
	- precise control on where each element is inserted (i.e. positional sequence)
		- use previous( ), next( ), add( )
	- performance of the operations
 */

import java.util.*;

public class LinkedListDemo {

	public static void main( String args [] ) {


		// Java interface: Collection; Java class: LinkedList
		Collection c = new LinkedList();


		// Java interfaces: List, ListIterator
		List clist = (List) c;

		clist.add( 0, "IPC144" );
		clist.add( 1, "OOP244" );
		clist.add( 2, "xyz???" );
		clist.add( 3, "BPJ444" );
		clist.add( 4, "BAJ544" );
		clist.add( 3, "hi" );

		ListIterator little = clist.listIterator( ); // start at the beginning

		for (int k=1; k <= clist.size(); k++)

			     System.out.println( "k: " + k + " current element: " + little.next() );


		for (int j=1; j <= 5; j++)

			 if ( little.hasPrevious() )

				  System.out.println( "j: " + j + " previous element: " + little.previous() );


		// another iterator
		ListIterator middle = clist.listIterator( 4 );

		System.out.println( "middle: " + middle.previous() );
		System.out.println( "middle: " + middle.previous() );

		System.out.println( "done" );
	}

}




