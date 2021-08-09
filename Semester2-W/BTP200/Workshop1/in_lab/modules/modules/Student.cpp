#include <iostream>
#include "Student.h"

using namespace std;

namespace seneca
{
	void setStudentToEmptyState(Student* pStudent)
	{
		pStudent->m_studentNumber = 0;
		pStudent->m_name[0] = '\0';
	}

	void displayStudent(Student* pStudent)
	{
		if (pStudent->m_name[0] != '\0')
		{
			cout << "The name is: " << pStudent->m_name
			cout << "(#" << pStudent->m_studentNumber << ")" << endl;
		}
		else
		{
			cout << "No Student!" << endl;
		}
	}
}
