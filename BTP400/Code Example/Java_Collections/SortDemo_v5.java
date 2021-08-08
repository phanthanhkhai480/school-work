
// for Java 1.5 and above

import java.util.*;

public class SortDemo_v5 {

	public static void main( String args [] ) {


		// Java interface: Collection; Java class: LinkedList
		//initialize a Collection
		Collection<String> c = new LinkedList <String>();


		// Java interfaces: List, ListIterator
		List<String> clist = (List<String>) c;

		clist.add( 0, "IPC144" );
		clist.add( 1, "OOP344" );
		clist.add( 2, "Xyz???" );
		clist.add( 3, "BPJ444" );
		clist.add( 4, "bAJ544" );
		clist.add( 3, "hi" );
		clist.add( 5, "OOP3" );


        // enhanced for loop
        for( String element : clist )

             System.out.println( element );

        System.out.println( "... sort the list..." );

		// Java class: Collections!
		//it sorts the list in the capital order first and lower case?
		Collections.sort( clist );   // the CompareTo method (the Comparable interface) is used here
		                             // another advanced feature: comparator
		                             // e.g. Collections.sort( geometricList, compareAre
		
		// traversal of the linked list object
		Iterator<String> z = clist.listIterator(); 

		while ( z.hasNext() )

			System.out.println( z.next() );


	}

}



