

// Java API of Hashtable (v 1.6)
// - keys and values must NOT be null
// - performance criteria for storing and retrieving elements
// - it implements the Map interface

// put, get, keys, elements
// the enumeration interface

// all the keys are unique

import java.util.*;

class HashtableDemo2 {

 public static void main( String [] args) {

    Hashtable<String, String>

       table = new Hashtable<String, String>( );  // key-value pairs


   table.put( "AKL", "Auckland, New Zealand" );
   table.put( "FRA", "Frankfurt, Germany" );
   table.put( "GLA", "Glasgow, Scotland" );
   table.put( "LAX", "Los Angeles, California, USA" );
   table.put( "PHL", "Philadelphia, Pennsylvania, USA" );
   table.put( "CALG", "Calgary, Alberta, Canada" );
   table.put( "VCR", "Vancouver, British Columbia, Canada" );
   table.put( "HKG", "Hong Kong, China" );

   table.put( "CALG", "what is this?" );
   table.put( "CALG", "I don't know!" );

   String key [] = { "FRA", "CALG" };

   String description_value [] = new String[ key.length ];

   for (int i=0; i < key.length; i++) {

	        description_value[i] = table.get( key[i] );

            if ( description_value[i] != null)

                  System.out.println( "... key: " + key[i] +
                                      "\n....... value retrieved: " + description_value[i] );
   }

	//Enumeration <String> enumKeys = table.keys();

	// the keys
	for ( Enumeration<String> enumKeys = table.keys(); enumKeys.hasMoreElements(); )

          System.out.println( "city code(key): " + enumKeys.nextElement() );


	//Enumeration <Integer> enumValues = table.elements();

	// the values
		for ( Enumeration<String> enumValues = table.elements(); enumValues.hasMoreElements(); )

       		  System.out.println( "city description(value): " + enumValues.nextElement() );

    // Part 2
    Hashtable<String, Employee>

       etable = new Hashtable<String, Employee>( );  // key-value pairs

       etable.put( "Peter Liu", new Employee( 12345, "Peter Liu", "70 The Pond", "1990") );
       etable.put( "Ruth Parker", new Employee( 98765, "Ruth Parker", "1 George St.", "1972" ) );
       etable.put( "John Doe", new Employee( 65432, "John Doe", "909 Dundas", "1965" ) );

       Employee z = etable.get( "Ruth Parker" );

       System.out.println( "\n\n... retrieve an employee from the hashtable:\n" + z );

} // end main

} // class
