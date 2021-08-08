// Source of idea: Core Java 2, Vol. II, p. 270

// a client program

import java.rmi.*;
import java.rmi.server.*;

public class ProductClient
{
	public static void main(String[] args) {


       String url = "rmi://localhost:6666/";

	   try {
			System.out.println( "Running a client application..." );

 			System.out.println( "+++ retrieving bindings from the RMI Registry\n" +
			                    "  + these services have been registered with the RMI Registry:" );
              
			// use of RMI URL
 			String names[] = Naming.list( "rmi://localhost:6666" );

			// retrieve bindings from the RMI Registry
 			for(int k=0; k < names.length; k++)
    				System.out.println( "....... " + names[k] );
 
			System.out.println( "\n+++ get remote references\n" +
			                    "  + bind local object variables to remote objects..." );

            //use of RMI URL
			Product c1 = (Product) Naming.lookup( url + "toaster" );
			Product c2 = (Product) Naming.lookup( url + "microwave" );

            // for localhost only
			/*
            java.rmi.registry.Registry registry = 
			     java.rmi.registry.LocateRegistry.getRegistry(6666);
				 
            Product c1 = (Product) registry.lookup( "toaster" );
			Product c2 = (Product) registry.lookup( "microwave" );
		    */
			
			// invocation of remote methods
            System.out.println( "\nproduct descriptions:" );
			System.out.println( c1.getDescription() ); // remote method call
			System.out.println( c2.getDescription() );

			System.out.println( "\nprice information:" );
			System.out.println( c1.getPrice() ); // remote method call
			System.out.println( c2.getPrice() );
	   }

	   catch( Exception e ) {
				 System.out.println( "Error " + e );
 	   }

	   System.out.println( "\nRMI client: THE END!" );
	}
}

/* lookup
	- look up a remote object
	- obtain the reference to the remote object (i.e. a reference to a stub for the remote object)
	- remote objects are registered with a remot object registry
	  - the Naming class provides methods for storing and obtaining remote references
*/

/* a stub
     - maintain an internal reference to the remote object and
       forward a remote method call throught the remote reference layer
*/