
/* ArrayList (Java 1.6, 1.5)
   - methods: add, get, remove, to Array
   - Java API (Java Generics)
   
   updated on 1/16/2020
*/

import java.util.*;  // What does it mean?

public class Company3 {

   private ArrayList<Employee> employees;

   private String name;

   public Company3() { this( "Seneca"); }

   public Company3( String name ){

   	  this.name = name;

   	  employees = new ArrayList<Employee>();
   }

   public boolean hire( Employee person ) {

   	   boolean done = true;

   	   employees.add( person );

   	   return done;
   }

   public String toString() {

   	  int m = employees.size();

   	  String s = name + " has " + m + " employee(s).\n";

   	  for (int k=0; k < m; k++) {

		   Employee emp = employees.get(k);

   		   s += emp; // s+= emp.toString();
      }

   	  return s;
   }

   public Employee layoff( int m ) { return (Employee) employees.remove(m); }

   Employee[] getEmployees( ) { // work with an array of employees instead of a list of employees
	                            Employee [] empArray = new Employee [employees.size()]; // size 0?

                                return employees.toArray( empArray );
                              }

public static void main( String[] arg ) {


		Company3 c = new Company3( "Seneca@York" );

		System.out.println( c );

		c.hire( new Employee( 1001, "John Doe", "111 The Pond", "2003" ) );
		c.hire( new Employee( 2002, "Mary Cunha", "222 Leslie", "2001" ) );
		c.hire( new Employee( 3003, "George Sas", "333 Don Mills", "2008") );

		System.out.println( c );
		
		// Part 2
        Employee [] t = c.getEmployees();

		for (int k=0; k<t.length; k++) {

		      System.out.println( "[" + (k+1) + "] " + t[k].getAddress() );
	    }
        
		// Part 3
        System.out.println( "\n... start laying off employees\n" );

        for (int j=1; j<=3; j++) {

             c.layoff(0);
             System.out.println( c );
        }

        // what is returned by getEmployees when the the list is empty?
        /*
        t = c.getEmployees();
        System.out.println( ".... t.length: " + t.length );
        */

	}
}