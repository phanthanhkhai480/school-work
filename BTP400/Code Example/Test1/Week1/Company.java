

public class Company {

   private Employee [] employees;       // field (instance variable)
   private String name;
   private int numberOfPositions;


   public Company( String name, int n ){

   	  this.name = name;

   	  employees = new Employee[n];

   	  numberOfPositions = n;
   }

   public boolean hire( Employee person ) {

   	  boolean done = true;

   	   if ( numberOfPositions > 0 ) {


   		    employees[ employees.length - numberOfPositions] = person;

   		    numberOfPositions--;
   	   }

   	   else done = false;

   	   return done;
   }

   public String toString() {

   	  int m = employees.length - numberOfPositions;

   	  String s = name + " has " + m + " employees.\n\n";

   	  for (int k=0; k < m; k++)

   		   s += employees[k].toString();

   	  return s;
   }


	public static void main( String[] arg ) {

		//initialize the object c in type of Company
		Company c = new Company( "Seneca@York", 500 );
		//display the object
		System.out.println(c);
		//add new object to Company
		c.hire( new Employee( 1001, "John Doe", "111 The Pond", "2003" ) );
		c.hire( new Employee( 2002, "Mary Cunha", "222 Leslie", "2001" ) );
		//display employee information
		System.out.println(c);


	}
}