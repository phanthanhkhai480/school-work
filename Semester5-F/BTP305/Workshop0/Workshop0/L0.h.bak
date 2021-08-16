#include <stdio.h>

// provide interface documentation comment
/*!
 * Constant number of Student
 */
const int NO_OF_STUDENTS = 5;


// describe the class here....
/*!
 * Class Person contain attribute of Student Name
 * Class Student contain attribute of Student Number
 * Class Person Inherited class Student
 */
// is this an example of weak or strong encapsulation
/*!
* This is an example of weak encapsulation as there is
* no privacy to restrict the access. Which mean if other
* class inherited class Student it will also have permission
* to used all the function and attribute no matter it needs it
* not, easy to change data value
*/

struct Person {
	char *name;		//attribute name
	std::ostream& display(std::ostream&); //display function
};
struct Student : public Person {

	// place interface documentation for each
	// class member
	Student(char*, int); //constructors

	int  number;	//attribute name
	std::ostream& display(std::ostream&);	//display function

};
#pragma once
