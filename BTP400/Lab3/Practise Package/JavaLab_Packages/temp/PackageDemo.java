package seneca.summer2004;
//import seneca.summer2004.*;

// the default package is used here (i.e. no package name)
public class PackageDemo {

   private May a;
   private August b;

   public PackageDemo() { a = new May();
                          b = new August();
                        }

   public String toString() { return a.toString() + "\n" + b.toString(); }

   public static void main( String args [] ) {

      PackageDemo pd = new PackageDemo();

      System.out.println( pd );
   }

}

// two ways of compiling and executing this class
// option 1:
//          - put the "summer2004" folder in the "seneca" folder and put
//                the "seneca" folder in the current working directory
//          - javac PackageDemo.java
//          - java  PackageDemo
// option 2:
//			- put the "seneca" folder somewhere else(e.g. in the "c:\elsewhere" folder)
//          - javac -classpath .;c:\elsewhere PackageDemo.java
//			- java  -classpath .;c:\elsewhere PackageDemo