#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CString.h"

int MAX = 3;

namespace w1
{
	CString::CString() : num{ 0 }, character{ '\0' }
	{
		
	}

	CString::CString(const char* maxNumString) : num(MAX)
	{
		if (maxNumString != nullptr)
		{
			strncpy(character, maxNumString, num);
			character[num] = '\0';
		}
		else
			character[0] = '\0';
	}

	void CString::display(std::ostream & out) const
	{
		out << this->character;
	}

	std::ostream & operator<<(std::ostream& os, const CString& tmp)
	{
		static int tmpnum = 0;
		os << tmpnum << ":";
		tmp.display(os);
		tmpnum++;
		return os;
		// TODO: insert return statement here
	}
}


