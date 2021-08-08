// Source of idea: Core Java 2, Vol. II, p. 267

// implementation of the remote interface

import java.rmi.*;
import java.rmi.server.*;

public class ProductImpl extends UnicastRemoteObject
			 implements Product {

	private String name;
	private double price;

	public ProductImpl( String s, double p ) throws RemoteException
	{
		name = s;
		price = p;
	}

	public String getDescription() throws RemoteException
	{
		return "*** Product Name: " + name + " ***";
	}

	public double getPrice() throws RemoteException
	{
		return price;
	}

}