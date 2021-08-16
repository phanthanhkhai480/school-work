// an example on Java objects

// constructor
// instance variables, static variable
// methods: getters and setters
// keywords: this,new

public class Employee {

    public static int numberOfEmployees;

    private int    employeeID;
    private String employeeName;
    private String address;
    private String startingYear;

    // constructors
    public Employee( int id, String name, String addr, String year) {

	    employeeID = id;
        employeeName = name;

        setAddress( addr );

        startingYear = year;

        numberOfEmployees++;
    }

    public Employee( ) { this( 10000, "unknown", "unknown", "unknown"); }

    // setters
    public void setAddress( String address ) { this.address = address;  }

    public void setEmployeeID( int id ) { employeeID = id; }

    public void setEmployeeName( String name ) { employeeName = name; }

    public void setStartingYear( String year ) { startingYear = year; }

    // getters
    public String getAddress() { return address; }

	public int getEmployeeID() { return employeeID; }

	public String getEmployeeName() { return employeeName; }

	public String getStartingYear() { return startingYear; }

    // the toString( ) method
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


	// the static main method
    public static void main(String args[]) {

         Employee phil, george;

         System.out.println( "\t number of employees: " + Employee.numberOfEmployees +"\n" );

         phil = new Employee( 10023, "Phil Coulthard",
                                     "70 The Pond, Seneca@York", "2002" );


         george = new Employee( 10089, "George Farr",
                                       "678, IBM Toronto Lab", "1980" );

         System.out.println( phil );    // System.out.println( phil.toString() );
         System.out.println( george );  // System.out.println( george.toString() );

         System.out.println( "\t number of employees: " + Employee.numberOfEmployees );


         	Employee z = new Employee();
         System.out.println( z + "number of employees: " + Employee.numberOfEmployees );

         phil = george;
         System.out.println(phil +"\n" + george );

  }
}









