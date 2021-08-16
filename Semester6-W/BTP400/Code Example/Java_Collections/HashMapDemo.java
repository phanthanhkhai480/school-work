

// HashMap
// - a dictionary of key/value pairs that are not ordered
// - keys and values must NOT be null
// - keys do not have duplicates
// - performance criteria for storing and retrieving elements
// - it implements the Map interface

// put, get, keys, elements

// all the keys are unique

import java.util.*;

class HashMapDemo {

 public static void main( String [] args) {

    HashMap<String, String>

       hashMap = new HashMap<String, String>( );  // key-value pairs


   hashMap.put( "AKL", "Auckland, New Zealand" );
   hashMap.put( "FRA", "Frankfurt, Germany" );
   hashMap.put( "GLA", "Glasgow, Scotland" );
   hashMap.put( "LAX", "Los Angeles, California, USA" );
   hashMap.put( "PHL", "Philadelphia, Pennsylvania, USA" );
   hashMap.put( "CALG", "Calgary, Alberta, Canada" );
   hashMap.put( "VCR", "Vancouver, British Columbia, Canada" );
   hashMap.put( "HKG", "Hong Kong, China" );

   hashMap.put( "CALG", "what is this?" );
   hashMap.put( "CALG", "A Mysterious City!" ); // key - no duplicates!

   // retrieve all the values from the HashMap
   Collection c = hashMap.values();
   
   // use an iterator on a Java collection
   Iterator iterator = c.iterator();
   while ( iterator.hasNext() ) {
           System.out.println( iterator.next() );
   }
   
   // retrieve all the keys from the HashMap
   Collection keySet = hashMap.keySet();
   
   // use an iterator on a Java collection
   iterator = keySet.iterator();
   while ( iterator.hasNext() ) {
           System.out.println( iterator.next() );
   }
   
   // retrieve some values
   String key [] = { "FRA", "CALG" };

   String description_value [] = new String[ key.length ];

   for (int i=0; i < key.length; i++) {

	        description_value[i] = hashMap.get( key[i] );

            if ( description_value[i] != null)

                 System.out.println( "... key: " + 
				                     key[i] +
                                     "\n........ value retrieved: " + 
									 description_value[i] );
   }
   
    // Part 2: a HashMap of keys and object references
	
    HashMap<String, Employee>

       etable = new HashMap<String, Employee>( );  // key-value pairs

       etable.put( "Peter Liu", new Employee( 12345, "Peter Liu", "70 The Pond", "1990") );
       etable.put( "Ruth Parker", new Employee( 98765, "Ruth Parker", "1 George St.", "1972" ) );
       etable.put( "John Doe", new Employee( 65432, "John Doe", "909 Dundas", "1965" ) );

       Employee z = etable.get( "Ruth Parker" );

       System.out.println( "\n\n... retrieve an employee from the HashMap:\n\n" + z );

 } // end main

} // class
