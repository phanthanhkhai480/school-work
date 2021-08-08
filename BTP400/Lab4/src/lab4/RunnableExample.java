/**
 * NOTE: when doing compile, note that the file does not run as java RunnableExample
 * it has to move back 1 folder and compile as java lab4.RunnableExample
 * when compile .java to .class file, step are normal
 */
package lab4;

public class RunnableExample {
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
		
		//create objects of SearchThreads to pass the array for comparison
		Thread runnableExample = new Thread(new SearchRunnable(data));
		
		//passing data into Runnable method
		System.out.println("+ summary");
		
		//start the Runnable class
		runnableExample.start();
	}
}




















