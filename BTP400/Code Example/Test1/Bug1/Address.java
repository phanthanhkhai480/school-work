/**
   @author Igor Krasnyanskiy
   @see <a href="http://www.vogella.com/tutorials/JavaIntroduction/article.html">Vogel's Tutorial</a>
*/

/* Peter Liu's Question: 
   No constructors are implemented here! 
   What default values are stored in an Address object?
   
   updated on 1/23/2020
 */
 
public class Address{
	private String street;
	private String number;
	private String postalCode;
	private String city;
	private String country;
	
	public String getStreet() {
		return 	street;
	}
	
	public void setStreet(String street) {
		this.street = street;
	}
	
	public String getNumber() {
		return number;
	}
	
	public void setNumber(String number) {
		this.number = number;
	}
	
	public String getPostalCode() {
		return postalCode;
	}
	
	public void setPostalCode(String postalCode) {
		this.postalCode = postalCode;
	}
	
	public String getCity() {
		return city;
	}
	
	public void setCity(String city) {
		this.city = city;
	}
	
	public String getCountry() {
		return country;
	}
	
	public void setCountry(String country) {
		this.country = country;
	}
	
	public String toString() {
		return street + " " + number + " " + postalCode + " " + city + " " + country;
	}
}