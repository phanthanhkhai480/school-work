// Java Bug #3A (Source: Dan)

import java.util.ArrayList;

public class JavaBug3A {

	public static void main( String args []){

		ArrayList<String> alist = new ArrayList<>();

		alist.add( "Java" );
		alist.add( new String("Bug") );
		alist.add( "3A" );
		
	
		
		// Error #1
		// line 3 will lead to OutOfBoundException since size start at 1 and arrat start at 0
		// if we fix at line 3 to have (counter-1), result will be 3A and Bug, since the last
		// position in the alist has been remove, which is Java (older value will be push in +1)
		// for (int i=0; i < alist.size(); i++) {

			// System.out.println( "i: " + i );
			
			 // int counter = alist.size();
			 // //System.out.println( counter-1 );
			
			 // String e = alist.remove(counter-1);
			
			 // System.out.println( e );
		 // }

		// Interesting Output
		// this will display Java and 3A because the order is Java, Bug and 3A, after
		// the method display Java, the object Java will be remove and Bug with 3A will
		// be shift to front 1 position, therefore that is how 3A is display
		// for (int i=0; i < alist.size(); i++) {

			 // System.out.println( "i: " + i );
			
			 // String e = alist.remove(i);
			
			 // System.out.println( e );
		// }
			
		// Error #2

          for (String e: alist)
		      System.out.println( e );
			  
			  //caused ConCurrentModificationException
		  for (String e: alist) {
		          alist.remove(e);
		  }
		
	}
}