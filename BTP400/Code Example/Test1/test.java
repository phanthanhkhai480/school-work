//Questions and Exercises: Classes
//Consider the following class:
public class IdentifyMyParts {
    public static int x = 7; 
    public int y = 3; 
}
//What are the class variables?	Variable X
//What are the instance variables? Variable Y
//What is the output from the following code:
	IdentifyMyParts a = new IdentifyMyParts();
	IdentifyMyParts b = new IdentifyMyParts();
	a.y = 5;
	b.y = 6;
	a.x = 1;
	b.x = 2;
	System.out.println("a.y = " + a.y); //5
	System.out.println("b.y = " + b.y);	//6
	System.out.println("a.x = " + a.x);	//2
	System.out.println("b.x = " + b.x);	//2
	System.out.println("IdentifyMyParts.x = " + IdentifyMyParts.x);
//since x is always static, it will just stored the last modified number and 
//references that values across all classes that use it. Therefore, all the value are





//Questions and Exercises: Objects
//What's wrong with the following program? Rectangle doesn't initializes the default contructor,
//--therefore, myRect is declared but never been registered to the momory
public class SomethingIsWrong {
    public static void main(String[] args) {
        Rectangle myRect;
        myRect.width = 40;
        myRect.height = 50;
        System.out.println("myRect's area is " + myRect.area());
    }
}

//The following code creates one array and one string object. 
//How many references to those objects exist after the code executes?
//--1 from the array pointing to the String and 1 from the String placing in the array
//Is either object eligible for garbage collection?
//--none of them is eligible since they all have references to a position

	String[] students = new String[10];
	String studentName = "Peter Parker";
	students[0] = studentName;
	studentName = null;
	
//How does a program destroy an object that it creates?
//--the program does not explicitly destroy the object, it only assign null values to the object (or sometimes 0)
//--and the JVM will automatically collect the garbage.
//Fix the program called SomethingIsWrong shown in Question 1.
public class SomethingIsWrong {
    public static void main(String[] args) {
        Rectangle myRect = new Rectangle();
        myRect.width = 40;
        myRect.height = 50;
        System.out.println("myRect's area is " + myRect.area());
    }
}
//Given the following class, called NumberHolder, write some code that creates an instance of the class, initializes its two member variables, and then displays the value of each member variable.
public class NumberHolder {
    public int anInt;
    public float aFloat;
}

public static void main(String[] args) {
	NumberHolder temp = new NumberHolder();
	temp.anInt = 10;
	temp.aFloat = 20f;
	System.out.println(temp.anInt);
	System.out.println(temp.aFloat);
}




https://docs.oracle.com/javase/tutorial/java/IandI/QandE/interfaces-questions.html
//Questions and Exercises: Interfaces
//What methods would a class that implements the java.lang.CharSequence interface have to implement?
//What is wrong with the following interface? interface shouldn't have any implemented method
public interface SomethingIsWrong {
    void aMethod(int aValue){  System.out.println("Hi Mom");    }
}

//Fix the interface in question 2.
public interface SomethingIsWrong {	void aMethod(int aValue);	}

//Is the following interface valid? No because interface should have at least 1 unimplemented method
public interface Marker {}

//methods are desired to implemented in interface should declared at default in the beginning





//Questions and Exercises: Inheritance
//Consider the following two classes:
public class ClassA {
    public void methodOne(int i) {	}
    public void methodTwo(int i) {  }
    public static void methodThree(int i) {	}
    public static void methodFour(int i) { }
}

public class ClassB extends ClassA {
    public static void methodOne(int i) {	}
    public void methodTwo(int i) {    }
    public void methodThree(int i) {    }
    public static void methodFour(int i) {    }
}
//Which method overrides a method in the superclass?
//Which method hides a method in the superclass?
//What do the other methods do?
























