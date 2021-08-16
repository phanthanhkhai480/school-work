#include <iostream>
#include <cstring>
#include "process.h"

	void process(char* tmpcharacter, std::ostream & out)
	{
		w1::CString tmp(tmpcharacter);
		out << tmp << std::endl;
	}
