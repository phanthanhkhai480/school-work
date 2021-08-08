package lab4;

import java.io.*;
import java.net.*;

public class AccountServer {
	
	public static void main(String[] args) {
		ServerSocket AccountServer;
		
		try {
			//create a server socket with a distinct port number so client can connect
			AccountServer = new ServerSocket(5678);
			
			//create a socket if an attempt is made to a server
		    System.out.println( "listening for a connection..." );
	        Socket socketConnection = AccountServer.accept();
	        
	        //create input/output stream to the socket
			//this will help transfer the input from client to server
			//and output from server back to client
	        ObjectOutputStream oosToClient = new ObjectOutputStream( socketConnection.getOutputStream() );
			ObjectInputStream  oisFromClient= new ObjectInputStream( socketConnection.getInputStream()  );
			System.out.println( "I/O streams connected to the socket" );
			
			//initialize the object
			Account account = new Account();
			Account temp = new Account();
			//string object to hold in when received from client
			String command = "", command1 = "", command2 = "";
			//set exit condition
			boolean programQuit = false;
			
			//testing object
			double amount = 0;
			
			try {
				System.out.println("Welcome to Bank@Seneca!");
			
				while(!programQuit) {
					
					//receive new create object from client
					temp = (Account) oisFromClient.readObject();
					//check client passing conditions
					if(!temp.getAccountNumber().equals("") || 
					   !temp.getFullName().equals("") || 
					   !(temp.getAccountBalance().intValue() == 0)) {			
						account = (Account) temp;
							
						//receive user option from Client
						System.out.print("Waiting for command: ");
						command = (String) oisFromClient.readObject();
						
						//check for condition of the command and perform operations
						if(command.contains(" ")) {
							command1 = command.substring(0, command.indexOf(" ")).trim();
							command2 = command.substring(command.indexOf(" ")).trim();
							amount = Double.parseDouble(command2);	
							
							if(command1.equals("deposit")) {
								account.deposit(amount);
								System.out.print("Deposit " + amount + "\n");
							}
							else if(command1.equals("withdraw")) {
								account.withdraw(amount);
								System.out.print("Withdraw " + amount + "\n");
							}
							else
								System.out.println();
						}
						//check for quit conditions
						else if(command.equals("quit")) {
							System.out.println("Client is quiting...");
							programQuit = true;
						}
						
						//if the command is something else, print this
						else
							System.out.println("Wrong Command!");

						System.out.println(account);
						oosToClient.writeObject(account);
						oosToClient.flush();

					} else {	System.out.println("Account Error!");	}
				}
	
			} catch( ClassNotFoundException cnf ) 	{ cnf.printStackTrace(); }
			  catch( EOFException eof ) 			{ System.out.println("*** The client has terminated connection ***" ); }
			  catch( IOException e ) 				{ e.printStackTrace();    }	 

				//close the socket with the server
				System.out.println( "\nServer: closing the connection..." );	
				oosToClient.close();
				oisFromClient.close();	      
				socketConnection.close();	   
			
		} catch(IOException e ) 	{ e.printStackTrace();     }	
	}
}
