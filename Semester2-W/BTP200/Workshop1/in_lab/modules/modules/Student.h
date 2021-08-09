#ifndef STUDENT_H
#define STUDENT_H

namespace seneca
{
	class Student
	{
	public:
		char m_name[32];
		int m_studentNumber;
	};

	void setStudentToEmptyState(Student*);
	void displayStudent(Student*);
}

#endif