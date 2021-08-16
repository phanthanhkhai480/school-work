/**
   @author Igor Krasnyanskiy
   @see <a href="http://www.vogella.com/tutorials/JavaIntroduction/article.html">Vogel's Tutorial</a>
   
   updated by Peter Liu on 1/23/2020
*/
public class Person{
	private String firstName;
	private String lastName;
	private int age;
	private Address address;
	
	public Person(String a, String b, int value) {
		firstName = a;
		lastName = b;
		age = value;
	}
	public String getFirstName() {
		return firstName;
	}
	
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	
	public int getAge() {
		return age;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	
	public Address getAddress() {
		return address;
	}
	
	public void setAddress(Address address) {
		this.address = address;
	}
	
	public String toString() {
	   // return firstName + " " + lastName + " " + age + " " + address;
		
	   //Harika's code!
	   return firstName + " " + lastName + " " + age + " " + address.toString();
	}
}

