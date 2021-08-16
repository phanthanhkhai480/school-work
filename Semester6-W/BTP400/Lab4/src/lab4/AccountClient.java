package lab4;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class AccountClient {

	public static void main(String[] args) {
		Socket AccountClient;
		
		try {
			//connect to server via an IP address/server name with a port number
			AccountClient = new Socket( InetAddress.getByName( "localhost" ), 5678 );
			System.out.println( "Connected to " + AccountClient.getInetAddress().getHostName() );
			
			//create input/output stream to the socket
			//this will help transfer the input from client to server
			//and output from server back to client
			ObjectInputStream  oisFromServer= new ObjectInputStream( AccountClient.getInputStream()  );
			ObjectOutputStream oosToServer = new ObjectOutputStream( AccountClient.getOutputStream() );    
			System.out.println( "I/O streams connected to the socket" );
			
			//initialize the object
			Account account = new Account("Khai Phan", "A1111", 1000.00);
			//create scanner object to receive input and pass to server
			Scanner object = new Scanner(System.in);
			//string object to hold in put and pass into server
			String command = "";
			//set exit condition
			boolean programQuit = false;
			
			try {		
				
				//oosToServer.writeDouble(testing);
				//oosToServer.flush();
				//check if the server respond any error from the client
				//command = (String) oisFromServer.readObject();
				//System.out.println("Respond from Server: " + command);
				
				while(!programQuit) {
					//passing Account object to the server
					oosToServer.writeObject(account);
					oosToServer.flush();
					
					//read the String input
					System.out.print("What would you like to do with the account?: ");
					command = object.nextLine();
					//convert the input to lowerCase and pass the option to server
					command.toLowerCase();
					oosToServer.writeObject(command);
					//if the input is quit, set quit condition for the program
					if(command.equals("quit"))
						programQuit = true;
					else {	
						account = (Account) oisFromServer.readObject();
						System.out.println(account);
					}
				}
			} catch( EOFException eof ) 		{ System.out.println( "The server has terminated connection!" ); }
			  catch(IOException e ) 			{ e.printStackTrace(); } 
			  catch (ClassNotFoundException e) 	{ e.printStackTrace();	}	
			
				 //close the socket with the server
			     System.out.println( "\nClient: closing the connection..." );		
			     oosToServer.close();
			     oisFromServer.close();
			     AccountClient.close();	
			     object.close();
		     
		} catch( IOException ioe ) 	{ ioe.printStackTrace(); }
	}
}
