/*!\File Letter.h
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
#ifndef LETTER_H
#define LETTER_H
#include <string.h>

namespace sict
{
	enum class Letter {A,B,C,D,E,F,G,H,I};
	/*!< Represent Enum class for 
	Range of Grades!>*/
	char* convertion(const Letter& N) 	{
	/*!< Return Grade Letter 
	equivalent to Grade !>*/
		char* tmp = new char[3];
		if (N == Letter::A)	{
			strcpy_s(tmp,3,"A+");
			return tmp;		}
		else if (N == Letter::B)	{
			strcpy_s(tmp,3,"A");
			return tmp;		}
		else if (N == Letter::C)	{
			strcpy_s(tmp,3,"B+");
			return tmp;		}
		else if (N == Letter::D)	{
			strcpy_s(tmp,3,"B");
			return tmp;		}
		else if (N == Letter::E)	{
			strcpy_s(tmp,3,"C+");
			return tmp;		}
		else if (N == Letter::F)	{
			strcpy_s(tmp,3,"C");
			return tmp;		}
		else if (N == Letter::G)	{
			strcpy_s(tmp,3,"D+");
			return tmp;				}
		else if (N == Letter::H)	{
			strcpy_s(tmp,3,"D");
			return tmp;		}
		else if (N == Letter::I)	{
			strcpy_s(tmp,3,"F");
			return tmp;		}
	}
}

#endif