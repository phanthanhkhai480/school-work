#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
#include <cstring>
#include <fstream>

namespace w1
{
	class CString
	{
		const int num;
		char character[4];
	public:
		CString();
		CString(const char* store);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& os, const CString& tmpnum);
}


#endif

