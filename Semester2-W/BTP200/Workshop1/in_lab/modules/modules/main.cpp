#include <iostream>
#include "Student.h"
#include "College.h"

using namespace std;
using namespace seneca;
using namespace york;

int main(void)
{
	Student theStudent;
	setStudentToEmptyState(&theStudent);
	displayStudent(&theStudent);

	College theCollege;
	setStudentToEmptyState(&theCollege);
	displayStudent(&theCollege);
	
	
	// PRACTICE: add a function that initializes a "College" instance
	//   to the empty state by initializing every element of the
	//   "m_arrStudents" array.
	// setCollegeToEmptyState(&theCollege);
	return 0;
}
