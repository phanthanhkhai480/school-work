// Source: Joshua's Bug
// 1. Where are the bugs?
// 2. Read the API of the String class.

public class JavaBug3C {

   public static void main( String [] args ){
   
		String data []= { "Java",
						  " Java",
	                      " ",
	                      "  ", // 2 blank spaces
	                      ""    // empty string!
					    };
						
		//int index = Integer.parseInt( args[0] );
		
		//since first object of data doesn't have any space, only 1 spot
		//will be stored in the result, therefore when we are trying to 
		//access result #2, there is OutOfBoundException
		for (int i=0; i < data.length; i++){
		 System.out.println( data.length);
		     String result [] = data[i].split( " " );
			 
			 System.out.println( "data[" + i + "]:" + data[i] + "\n" +
			                     "result.length = " + result.length );
			 System.out.println( "result[0]:" + result[0] );
			 System.out.println( "result[1]:" + result[1] );
		}
   
   }
}