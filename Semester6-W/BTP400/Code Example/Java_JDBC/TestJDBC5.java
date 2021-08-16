
/* Sources: IBM textbook, Horstmann
   Modified by Peter Liu (Nov. 11, 2002)

   Purpose: Create a database table.
            - database name/collection name: MYJDBC (AS/400 library name)
	        - table name: Test

            Note: The library MYJDBC has been created already.
 */


 /* Step 1: load the JDBC driver */
 /* Step 2: connect to the database
 		       datasbase URL:
			   		         jdbc:<subprotocol>:<system url>/<collection name> */
/*  Step 3: Prepare the SQL statement object
	Step 4: Execute the SQL statement object */
/*  Step 5: Analyze(Navigate) the query result(the ResultSet) */
/*  Setp 6: Close the connection */


import java.sql.*;

public class TestJDBC5  {

	static final String drivername
	                       = "com.ibm.as400.access.AS400JDBCDriver"; // JDBC driver (a class name)

    static final String sysName = "odin.senecac.on.ca";   // database server

    static final String dbName  = "MYJDBC";		  		  // database(or collection) name

    private Connection conn;                              // database connnection


    public static void main(String args[]) {

        System.out.println("Inside TestJDBC5");

        TestJDBC5 test = new TestJDBC5(); 		 		/* load the JDBC driver */

        if ( test.testConnect( sysName, dbName ) )      /* test the connection */

             test.testQueryAll();			 			/* make SQL queries */

        System.exit(0);
    }


    public TestJDBC5() { // Step 1: load the JDBC driver

	   try {
	           Class.forName( drivername );  // load the Java class(i.e. JDBC driver) at run time
	   }
	   catch( ClassNotFoundException ec) { ec.printStackTrace();
	                                       System.out.println( "DB2 JDBC driver not found!" );
					                       System.exit(1);
					                     }


        System.out.println("JDBC class found");
    }


    public boolean testConnect(String sys, String databaseName) {

        System.out.println( "Connecting to database server: " + sys + "...");

        try
        {
	  		/* Step 2: connect to the database
		     		   datasbase URL:
			   		   jdbc:<subprotocol>:<system url>/<collection name> */

          conn = DriverManager.getConnection( "jdbc:as400:" +
					      					  "//" + sys +
                                              "/"  + databaseName );
        }

        catch ( SQLException exc )  /* SQLException */
        {
          System.out.println( "connection failed with: " +
                              exc.getMessage() );
          return false;
        }

        System.out.println( "connection OK" );

        return true;
    }

    public boolean testQueryAll() {

        System.out.println("querying all...");

		/* drop the table if it already exists! */

        try {
	     		Statement dropTable = conn.createStatement();

             	dropTable.executeUpdate( "DROP TABLE " +
				      					 "Test" ); 	      // table name: Test
	     		dropTable.close();
        }
        catch( SQLException e ) { }


        try
        {
	 		/*  Step 3: Prepare the SQL statement object
	    		Step 4: Execute the SQL statement object

            	SQL statements: create a table and insert data */

         	Statement stat = conn.createStatement();

	 	 	stat.executeUpdate( "CREATE TABLE Test (Actor CHAR(20), Country CHAR(20) )" );

	    			 		// What if there's SQL syntax error? e.g. missing ')'

	 	 	stat.executeUpdate( "INSERT INTO Test ( Actor, Country ) VALUES( 'Romeo', 'UK' )" );

	 	 	stat.executeUpdate( "INSERT INTO Test ( Actor, Country ) VALUES( 'Juliet', 'UK' )" );

	 	 	/* SQL statement: database query */
        	ResultSet rs = stat.executeQuery( "SELECT * FROM Test" );

					 			// an SQLException is thrown if the table name
					 			// is incorrect

	 	 	/* Step 5: Analyze(Navigate) the query result(the ResultSet) */

         	System.out.println("Here is the query result:");

         	while ( rs.next() ) {

            	System.out.println( "actor: " + rs.getString("Actor") +

            						" country: " + rs.getString("Country") );

			}

	 		rs.close();   // close the ResultSet object
	 		stat.close(); // close the Statement object
        }

        catch ( SQLException exc )
        {
           System.out.println( " query failed with: " +
                               exc.getMessage() );
           return false;
        }

		finally {

		   	System.out.println( "close the database connection..." );

		   	try { if (conn != null )
		     			conn.close(); // close the database connection
		   		}
		     catch (SQLException se ) { se.printStackTrace(); }
		}

        System.out.println( "query done" );

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

} // end TestJDBC5
