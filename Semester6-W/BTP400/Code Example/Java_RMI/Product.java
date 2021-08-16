// Source of idea: Core Java 2, Vol. II, p. 267

import java.rmi.*;

public interface Product extends Remote
{
	public String getDescription() throws RemoteException;

	public double getPrice() throws RemoteException;
}