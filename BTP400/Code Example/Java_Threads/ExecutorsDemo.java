/* 1. use an executor to execute two different threads
   2. High-Level Concurrency Objects (The Java Tutorials):
      https://docs.oracle.com/javase/tutorial/essential/concurrency/highlevel.html
   3. Vogel's Tutorial: https://www.vogella.com/tutorials/JavaConcurrency/article.html
   
   updated on 3/05/2020
*/

import java.util.concurrent.Executors; // a Java class
import java.util.concurrent.ExecutorService; // a Java interface

public class ExecutorsDemo {

   public static void main(String[] args) {

      ExecutorService executorService = Executors.newCachedThreadPool();
	  
	  executorService.execute( new CoffeeRunnable( "coffee request task" ) );
	  
	  executorService.execute( new TeaRunnable( "tea request task" ) );

      System.out.println( "*** " + Thread.currentThread().getName() + " : THE STORE IS CLOSED ***" );
   }
}

// a better design: one class for CoffeeRunnable and TeaRunnable
class CoffeeRunnable implements Runnable {

    private static int count = 0;
	private String taskName;

    public CoffeeRunnable(String s) { taskName = s; }

    // implement the run() method
    public void run() {

        while (true) {
                       try { Thread.sleep(1000); }
                       catch( InterruptedException e ) { }

                       count++;
					   System.out.println( count + ": " + taskName +
                                                   " : coffee please!!" );
                     }
    }
}

class TeaRunnable implements Runnable {

    private static int num=0;
	private String taskName;

	public TeaRunnable(String s) { taskName = s; }
	
    // implement the run() method
    public void run() {
                	while (true) {

                           try { Thread.sleep( 1500 ); }      // a static method
                           catch( InterruptedException e) { }

                           num++;
						   System.out.println( "\t\t<" + num + "> " + taskName +
                                               " : tea please!" );
                        }
    		      }
}