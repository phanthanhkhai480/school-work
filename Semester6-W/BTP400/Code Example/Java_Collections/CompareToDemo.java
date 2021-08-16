
import java.util.*;

// use the generic compareTo method
public class CompareToDemo {

	public static void main( String args [ ] ){

		Customer one = new Customer( "John Doe", 3 ),
			 two = new Customer( "Paul Newman", 7 ),
			 three = new Customer( "Mary Lewis", 1 ),
			 four = new Customer( "Anne Schultz", 3 );


		if (one.compareTo(two) < 0)
			System.out.println( one + "\n<<< is less than >>>\n" + two );

		if (two.compareTo(three) > 0)
			System.out.println( two + "\n<<< is greater than >>>\n" + three );

		if (one.compareTo(four) == 0)
		    System.out.println( one + "\n<<< is equal to >>>\n" + four );

    }
}

// define the natural ordering of customers

class Customer implements Comparable {

	private String name;
	private int    priority;

	public Customer( String name, int priority ){
		this.name = name;
		this.priority = priority;
	}

	public String toString() {

		return "name: " + name + " priority: " + priority;
	}

	public int compareTo( Object z ){

		return this.priority - ((Customer)z).priority;
	}
}