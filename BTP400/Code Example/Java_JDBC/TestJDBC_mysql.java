
/* Sources: IBM textbook, Horstmann
   Modified by Peter Liu (Nov. 11, 2002; July 26 2007)

   Purpose: Retrieve data from a MySQL database table
            - database name: accounts
            - table name: Account
 */


 /* Step 1: load the JDBC driver */
 /* Step 2: connect to the database
 		       datasbase URL:
			   		         jdbc:<subprotocol>:<system url>/<collection name> */
/*  Step 3: Prepare the SQL statement object
	Step 4: Execute the SQL statement object */
/*  Step 5: Analyze(Navigate) the query result(the ResultSet) */
/*  Setp 6: Close the connection */

// JDBC interfaces: Connection, Statement, ResultSet


import java.sql.*;

public class TestJDBC_mysql  {

	static final String drivername
	                            = "com.mysql.jdbc.Driver"; // JDBC driver (a class name)

    static final String sysName = "zenit.senecac.on.ca";        // database server

                  //btp400_151b45 : fqBE2447 (Winter 2015)
    static final String dbName  = "btp400_151b45";         // database name

    static final String userid =  "btp400_151b45";
    static final String password = "fqBE2447";

    private Connection conn;                          // database connnection


    public static void main(String args[]) {

        System.out.println("running a JDBC application...");

        TestJDBC_mysql test = new TestJDBC_mysql(); 	/* load the JDBC driver */

        if ( test.testConnect( sysName, dbName ) )      /* test the connection */

             test.testQueryAll();			 			/* make SQL queries */

        System.exit(0);
    }


    public TestJDBC_mysql() { // Step 1: load the JDBC driver

	   try {
	           Class.forName( drivername );  // load the Java class(i.e. JDBC driver) at run time
	   }
	   catch( ClassNotFoundException ec) { ec.printStackTrace();
	                                       System.out.println( "MySQL JDBC driver not found!" );
					                       System.exit(1);
					                     }


        System.out.println("JDBC class found");
    }


    public boolean testConnect(String sys, String databaseName) {

        System.out.println( "Connecting to the MySQL server: " + sys + "...");

        try
        {
	  		/* Step 2: connect to the database
		     		   datasbase URL:
			   		   jdbc:<subprotocol>:<system url>/<collection name> */

          conn = DriverManager.getConnection( "jdbc:mysql:" +
					      					  "//" + sys +
                                              "/"  + databaseName,
                                              userid, password
                                            );
        }

        catch ( SQLException exc )  /* SQLException */
        {
          System.out.println( "connection failed with: " +
                              exc.getMessage() );
          return false;
        }

        System.out.println( "database connection-OK" );

        return true;
    }

    public boolean testQueryAll() {

		/*  Step 3: Prepare the SQL statement object
	        Step 4: Execute the SQL statement object */

		// drop the table if it already exists!

		System.out.println( "dropping a table if it exists..." );

		try {
			  Statement dropTable = conn.createStatement();

		      dropTable.executeUpdate( "DROP TABLE " +
						      		   "Test" ); 	      // table name: Test
			  dropTable.close();
		}
        catch( SQLException e ) { }

        System.out.println( "creating a database table..." );

        try {
            // SQL statements: create a table and insert data

         	Statement stat = conn.createStatement();

         	stat.executeUpdate( "CREATE TABLE Test (ACTOR CHAR(20), COUNTRY CHAR(20) )" );

				    			 		// What if there's SQL syntax error? e.g. missing ')'

			stat.executeUpdate( "INSERT INTO Test ( ACTOR, COUNTRY ) VALUES( 'Romeo', 'UK' )" );

			stat.executeUpdate( "INSERT INTO Test ( ACTOR, COUNTRY ) VALUES( 'Juliet', 'UK' )" );

			System.out.println( "querying the database table..." );

		    // SQL statement: database query
        	ResultSet rs = stat.executeQuery( "SELECT * FROM Test" );

					 			// an SQLException is thrown if the table name
					 			// is incorrect

	 	 	/* Step 5: Analyze(Navigate) the query result(the ResultSet) */

         	System.out.println("\n******* The Result of the Query *******");

         	while ( rs.next() ) {

            	System.out.println( "actor's name: " + rs.getString(1) +

            						" country name: " + rs.getString(2) );

			}

	 		rs.close();   // close the ResultSet object
	 		stat.close(); // close the Statement object
        }
        catch ( SQLException exc )
        {
           System.out.println( " query failed with: " + exc.getMessage() );
           return false;
        }
		finally { // always executed

		   	System.out.println( "\nclose the database connection..." );

		   	try { if (conn != null )
		     			 conn.close(); // close the database connection
		   		}
		     catch (SQLException se ) { se.printStackTrace(); }
		}

        System.out.println( "DONE" );

        return true;

    } // end testQueryAll

    public void getMetadata( ResultSet rs ) {

		/* Retrieve the metadata of a table */
		System.out.println( "meatdata info:" );

		try {
				ResultSetMetaData rsmeta = rs.getMetaData();

				int columnCount = rsmeta.getColumnCount();

				System.out.println( "number of columns: " + columnCount );

				for (int i=1; i <= columnCount; i++)
   		 				System.out.println( "column name: " + rsmeta.getColumnName(i) +
                      		     			"\n data type: " + rsmeta.getColumnTypeName(i) );
			}
		catch( SQLException e ) { e.printStackTrace(); }
   }

} // end TestJDBC_mysql
