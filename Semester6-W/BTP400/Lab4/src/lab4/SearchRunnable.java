package lab4;

import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;

class SearchRunnable implements Runnable {
	//take the search argument for searching
	private String search = RunnableExample.M_SEARCHWORD;
	//create local 2D array to store data
	private String[][] dataArray = {};
	//int counter for checking
	int counter = 0, count = 0;
	//create temp string to concatenate result in row
	String temp = "";
	//create an arrayList to hold data result
	ArrayList<String> dataStore = new ArrayList<String>();
	
	/**
	 * One-Argument Constructor, to receive the data information
	 * @param information
	 */
	public SearchRunnable(String[][] information) {		this.dataArray = information;	}
	
	/**
	 * run method for the Runnable Thread
	 */
	public void run() {
		//check if the search string is null or empty
		if(this.search != null || this.search != "") {
			while (count < 1) {
				//if not, proceed to check true/false for the string information
				for(int a = 0; a < this.dataArray.length; a++) {
					for(int b = 0; b < this.dataArray[a].length; b++) {
						//if string in data contain search string
						//add to string then add string to ArrayList
						if(this.dataArray[a][b].contains(search)) {
							temp+= dataArray[a][b] + ", ";
							counter++;
						}
					}
					//add string into ArrayList
					dataStore.add(temp);
					//set value back to default for another counter
					temp = "";
				}
				
				//loop to display string value stored in ArrayList
				for(int e = 0; e < this.dataStore.size(); e++) {
					//set interval time between each display
					try {
						ThreadLocalRandom generator = ThreadLocalRandom.current();
						long random = generator.nextLong(100,2000);
						Thread.sleep(random);
					} catch( InterruptedException error) { }
					
					//display information about the rows
					//if rows .get(e) doesn't have any string
					if(dataStore.get(e).equals(""))
						System.out.print("  row " + (e+1) + ": " + "***");
					//if rows .get(e) does have string
					else 
						System.out.print("  row " + (e+1) + ": " + dataStore.get(e));			
					System.out.println();	
				}
				count++;
			}
		}	
		//display last line of the output, result
		System.out.println("+ total number of strings found: " + counter + "\n");
	}
}