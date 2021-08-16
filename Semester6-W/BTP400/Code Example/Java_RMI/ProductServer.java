// Source of idea:
// Core Java 2, Vol. II, p. 267

// a server program

import java.rmi.*;
import java.rmi.server.*;

public class ProductServer {

   public static void main(String[] args) {

      try {
	   System.out.println( "Starting a server..." );

	   ProductImpl p1 = new ProductImpl( "Blackwell Toaster", 55.99 );
	   ProductImpl p2 = new ProductImpl( "Panasonic Microwave Oven", 234.99 );

	   System.out.println( "Binding remote objects to rmi registry" );

	   /*
	   // use of rmi URL
       Naming.rebind( "rmi://localhost:6666/toaster", p1 );   // <name, reference>
                                                              // e.g.("toaster",p1)
       Naming.rebind( "rmi://localhost:6666/microwave", p2 );
	   */
	   
	   // for localhost only
	   java.rmi.registry.Registry registry = 
	        java.rmi.registry.LocateRegistry.createRegistry(6666);
			
       registry.rebind( "toaster", p1 );
	   registry.rebind( "microwave", p2 );
	   
	   System.out.println( "These remote objects are waiting for clients..." );
      }

      catch( Exception e ) {
	                        System.out.println( "Error: " + e );
      }

      System.out.println( "... bye bye" );
      System.out.println( "... the main thread is put into a wait state!!!" );

      /* a separate thread is started after a remote object has been created */
   }
}
