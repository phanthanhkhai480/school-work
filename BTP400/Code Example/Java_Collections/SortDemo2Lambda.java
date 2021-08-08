
// Focus: Comparator (functional interface), lambda expression

import java.util.*;

public class SortDemo2Lambda {

	public static void main( String args [] ) {

		// Java interfaces: List, Comparator
		
		List<String> clist = new ArrayList<String>();

		clist.add( "Toronto" );
		clist.add( "Dallas" );
		clist.add( "Halifax" );
		clist.add( "Washington D.C." );
		clist.add( "Calgary" );
		clist.add( "Vancouver" );
		clist.add( "Prince Rupert" );
		clist.add( "Palm Beach" );


		// use of a comparator (i.e. a Comparator object)
		// Collections.sort( clist, new CityNamesComparator() );   
		
		//use the Collection as a container to contain the List Array (clist)
		//and the method compare to compare the object

		// Part 2: use of a lambda expression
		Collections.sort( clist, (c1, c2) -> { return c1.length() - c2.length(); } );
		
		                          // OR (c1, c2) -> c1.length() - c2.length()
		//implement the method right into the argument by using the -> operator
		
		for (String element: clist)
		     System.out.println( element + ", length: " + element.length() );
			 
	}// end main

}

class CityNamesComparator implements java.util.Comparator<String>{

    // compare the lengths of two strings (vs comapreTo in the String class)
    public int compare(String s1, String s2) {
	   return (s1.length() - s2.length() );
	}
}



