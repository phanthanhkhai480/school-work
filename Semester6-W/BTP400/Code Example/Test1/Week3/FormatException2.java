
import javax.swing.*;
import java.awt.event.*;

class FormatException2 {

	public static void main(String[] args) {

		String s = JOptionPane.showInputDialog( null, "How many people are waiting?" );


		int value = -1234;

		try {
				value = Integer.parseInt( s );

		}
		catch( NumberFormatException nfe ) {

				System.out.println( "1.Error: invalid input!( " + s + ")" );
				System.out.println( "2.toString() from the Throwable class:\n" + nfe );       
		}

		System.out.println( "3. value: " + value );
	}

}