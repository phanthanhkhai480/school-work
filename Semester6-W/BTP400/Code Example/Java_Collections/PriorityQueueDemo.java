
import java.util.*;

public class PriorityQueueDemo {

	public static void main( String args [ ] ){

		Customer one = new Customer( "John Doe", 3 ),
			 two = new Customer( "Paul Newman", 7 ),
			 three = new Customer( "Mary Lewis", 1 ),
			 four = new Customer( "Anne Schultz", 2 );

		PriorityQueue<Customer> customerQueue = new PriorityQueue<Customer>();

		customerQueue.offer( one );
		customerQueue.offer( two );
		customerQueue.offer( three );
		customerQueue.offer( four );

		while ( customerQueue.size() > 0 )

		        System.out.println( customerQueue.remove() );
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