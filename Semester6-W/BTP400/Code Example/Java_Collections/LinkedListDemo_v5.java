
// for JDK 1.5 and above

/* Linked List:
	- duplicate elements are allowed
	- precise control on where each element is inserted (i.e. positional sequence)
		- use previous( ), next( ), add( )
	- performance of the operations
 */

import java.util.*;

public class LinkedListDemo_v5 {

	public static void main( String args [] ) {


		// Java interface: Collection; Java class: LinkedList
		LinkedList <String> clist = new LinkedList<String> ();


		clist.add( 0, "IPC144" );
		clist.add( 1, "OOP244" );
		clist.add( 2, "xyz???" );
		clist.add( 3, "BPJ444" );
		clist.add( 4, "BAJ544" );
		clist.add( 3, "hi" );
		//when an object is adding in between the list, the lower object
		//will automatically shift down 1 position

		ListIterator little = clist.listIterator( ); // start at the beginning

		for (int k=1; k <= clist.size(); k++)

			     System.out.println( "k: " + k + " current element: " + little.next() );


        System.out.println( "\n... traversing from the end of the iterator" );

		//ListIterator will display reservely
		for (int j=1; j <= clist.size(); j++)

			 if ( little.hasPrevious() )

				  System.out.println( "j: " + j + " previous element: " + little.previous() );


		// another iterator
		ListIterator middle = clist.listIterator( 4 );
		//set cursor position at iterator 4

        System.out.println( "\n... middle (anotehr iterator)s: the cursor position is at 4" +
                            "\n........ traversing backward" );
		
		//start from position 4 and going back to 0
        while ( middle.hasPrevious() )
		        System.out.println( "middle: " + middle.previous() );

        System.out.println( "....... traversing forward" );

		//start from position 0 and going upward to end
		while ( middle.hasNext() )
		        System.out.println( "middle: " + middle.next() );


		System.out.println( "... done" );
	}

}





