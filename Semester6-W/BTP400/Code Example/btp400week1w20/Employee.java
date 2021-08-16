/*  An example of a Java class and Java objects.
    1. constructor
    2. fields/instance variables, static variable
    3. methods: getters, setters, toString
    4. keywords: this, new, static
    5. object variables (variables of reference types) and references

    updated on 1/16/2020
*/

public class Employee {

    public static int numberOfEmployees; // a static variable

    private int    employeeID;
    private String employeeName;
    private String address;
    private String startingYear;


    public Employee(int id, String name, String addr, String year) {

	    employeeID = id;
        employeeName = name;

        setAddress( addr );

        startingYear = year;

        numberOfEmployees++;
    }

    public Employee() { this(10000, null, null, null); };

    public void setAddress( String address ) {

       this.address = address;
    }

    public String getAddress() { return address; }

    public String toString() {

       String s;

       s =    "*****************************************\n" +
              "*           Employee Information        *\n" +
	          "*****************************************\n" +
              "ID: " + employeeID + "\n" +
              "Name: " + employeeName + "\n" +
              "Address: " + address + "\n" +
              "Starting Year: " + startingYear + "\n\n";

       return s;
    }

    public static void main( String args[] ) {


         Employee phil, george;      // two object variables, not object names as in C++

         phil = new Employee();      // object creation at run time
         System.out.println( phil );
         System.out.println( "\t number of employees: " + Employee.numberOfEmployees +"\n" );

         // Part 2
         phil = new Employee( 10023, "Phil Coulthard",
                                     "70 The Pond, Seneca@York", "2002");


         george = new Employee( 10089, "George Farr",
                                       "678, IBM Toronto Lab", "1980" );

         System.out.println( phil );
         System.out.println( george );

         System.out.println( "\t number of employees: " + Employee.numberOfEmployees );

        // a special case about the default constructor:
	    // The Java compiler creates the default constructor if
        // does not have *any* constructors
  }
}
