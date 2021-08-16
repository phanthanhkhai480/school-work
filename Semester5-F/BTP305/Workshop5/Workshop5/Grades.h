/*!\File Grades.h
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
#ifndef GRADES_H
#define GRADES_H
#include <string>
#include <fstream>
#include <iomanip>

namespace sict
{
	class Grades
	{
		std::string* studentNumber;	/*!< string type variable studentNumber !>*/
		float* grades;				/*!< float type variable of grades !>*/
		char** gradeLetter;			/*!< array of char type variable of gradeLetter !>*/
		int count;					/*!< int type variable of count !>*/	
	public: 
		Grades();					/*!< Default Constructor !>*/
		Grades(const char* file);	/*!< Custom Constructor !>*/
		Grades(const Grades& abc) = delete;	/*!< Unimplemented Copy Constructor !>*/
		Grades& operator=(const Grades& abc) = delete;	/*!< Unimplemented Copy Assignment Operator !>*/
		Grades(Grades&& abc) = delete;		/*!< Unimplemented Move Constructor !>*/
		Grades& operator=(const Grades&& abc) = delete;	/*!< Unimplemented Move Assignment Operator !>*/
		~Grades();
		
		template<typename Func>		/*!< Display Template !>*/
		void displayGrades(std::ostream& os, Func F) const	{
		for (int i = 0; i < this->count; i++)	{
			os  << std::right << std::setw(8) 
				<< studentNumber[i] << ' ' << std::fixed 
				<< std::setprecision(2) << std::setw(5) << grades[i];
			gradeLetter[i] = convertion(F(grades[i]));
			os  << " " << std::left << std::setw(3) 
				<< gradeLetter[i] << std::endl;	}			}
	};
}

#endif
