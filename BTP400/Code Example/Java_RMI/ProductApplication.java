
// a stand-alone Java application

public class ProductApplication
{
	public static void main(String[] args) {

	   System.out.println( "Running a stand-alone Java application...\n" +
						   "creating 2 objects...\n" );

	   ProductApp p1 = new ProductApp( "Blackwell Toaster" );
	   ProductApp p2 = new ProductApp( "Panasonic Microwave Oven" );


	   System.out.println( p1.getProductName() );
	   System.out.println( p2.getProductName() );

	   System.out.println( "\nWould you like to purchase these products?" );
	}
}


class ProductApp {

	private String productName;

	public ProductApp( String s ) {

		productName = s;
	}

	public String getProductName() {

		return "*** Product Name: " + productName + " ***";
	}


}