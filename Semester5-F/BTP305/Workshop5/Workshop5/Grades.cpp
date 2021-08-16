/*!\File Grades.cpp
// \Brief BTP305 Workshop 5: Lambda Expression
// \Details    Longer description of file
// \Version 1.0
// \Date 16/10/2018
// \Author Khai Phan
// \copyright GNU Public License.
//
//
**/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grades.h"
using namespace std;

namespace sict
{
	Grades::Grades()
	{
		this->studentNumber = nullptr;
		this->grades = 0;
		this->gradeLetter = nullptr;
		this->count = 0;
	}

	Grades::Grades(const char * file)
	{
		ifstream f(file);
		if (!f.is_open())
			throw "Couldn't open file or file is not exit";
		else
		{
			string temp;
			while (getline(f, temp))
				this->count++;
			f.clear();
			f.seekg(0,ios_base::beg);

			this->studentNumber = new string[this->count];
			this->grades = new float[this->count];
			this->gradeLetter = new char*[this->count];

			for (int i = 0; i < this->count; i++)
			{
				getline(f, temp);
				this->studentNumber[i] = 
					temp.substr(0, temp.find(' '));
				this->grades[i] = 
					stof(temp.substr(temp.find(' '))); //return parsing value in float
				this->gradeLetter[i] = nullptr;
			}

			f.close();
		}
	}

	Grades::~Grades()
	{
		delete[] this->grades;
		delete[] this->studentNumber;
		delete[] this->gradeLetter;
	}

}

