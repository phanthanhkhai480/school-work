
public class StringDemo3 {

   public static void main(String [] args) {

      String s1 = "   Java 2 for C++ Programmers  ";

      String word1, word2;


		//display the words and its length
      System.out.println( "s1:" + s1 + ":" + s1.length() );

		//remove all of the white spaces
      s1 = s1.trim();

		//display the words and its length after remove all of the white spaces
      System.out.println( "s1:" + s1 + ":" + s1.length() );

      // Part 2
	  //create a new words using substring, from position 0 to 6)
      word1 = s1.substring(0, 6);  // indices: 0, 6-1

		//create a new word using substring, from position 6 to the end
      word2 = s1.substring(6);

		//display the substrings
      System.out.println( "word1:<" + word1 + ">\nword2:<" + word2 + ">" );
		
		//initialize the starting string finder
      int start = s1.indexOf( "C++" );

		//initialize the ending string finder, until found the word or up for max 10 letter
      int end   = s1.indexOf( "ram", 10 );  // case sensitive
		
		//start substring the word
      word2 = s1.substring( start, end );
		
		//display the result
      System.out.println( word2 );

   }
}