/**
 * NOTE: when doing compile, note that the file does not run as java ThreadExample
 * it has to move back 1 folder and compile as java lab4.ThreadExample
 * when compile .java to .class file, step are normal
 */

package lab4;

import java.util.ArrayList;

public class ThreadExample {
	static String M_SEARCHWORD = "java";
	
	public static void main(String[] args) {
		
		//string of existing data
		String [][] data = {
				 { "java", "I love java", "c++", "python" },
				 { "c programs", "cookies", "java developers", "oops"},
				 { "john", "doe", "mary", "mark holmes"},
				 { "hello java java", "byebye", "java again?", "java what?"},
				 { "toronto", "montreal", "quebec city", "calgary"}
				 };
		
		//display the first line of output
		System.out.print("+ search word: " + M_SEARCHWORD + "\n");
		
		//create temp string to concatenate result in row
		String temp = "";
		
		//counter to keep track of all found object
		int counter = 0;
		
		//create an arrayList to hold data result
		ArrayList<String> dataStore = new ArrayList<String>();
		
		//create objects of SearchThreads to pass the array for comparision
		SearchThread[] threads = new SearchThread[data.length];
		
		//passing array data into SearchThread to analyze data
		for(int a = 0; a < data.length; a++) {
			threads[a] = new SearchThread(data[a], M_SEARCHWORD);
			
		}
		
		//joining point, wait for the threads to finish its task before continue
		try {
			System.out.println("+ summary");
			for(int b = 0; b < data.length; b++) {
				//System.out.print("  row " + (b+1) + ": ");
				threads[b].start();
				threads[b].join();
				temp = threads[b].getResult();
				counter += threads[b].getCount();
				dataStore.add(temp);
						
				//display information about the rows
				//if rows .get(e) doesn't have any string
				if(dataStore.get(b).equals(""))
					System.out.print("  row " + (+1) + ": " + "***");
				//if rows .get(e) does have string
				else 
					System.out.print("  row " + (b+1) + ": " + dataStore.get(b));			
				System.out.println();	
			}
		} catch (InterruptedException error) {	}
		//display last line of the output, result
		System.out.println("+ total number of strings found: " + counter + "\n");
	}
}
