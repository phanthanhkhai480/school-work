#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <exception>
#include "Utilities.h"
using namespace std;
char Utilities::delimiter = ' ';

Utilities::Utilities()
{
	this->field_width = 1;
}

void Utilities::setFieldWidth(std::size_t fw)
{
	this->field_width = fw;
}

std::size_t Utilities::getFieldWidth() const
{
	return size_t(field_width);
}

const string Utilities::extractToken
	(const std::string& str, std::size_t & next_pos, bool & more)
{
	string temp = "";
	string tmp = str.substr(next_pos);
	temp = tmp.substr(0, tmp.find(delimiter));
	size_t len = temp.size();
	
	try
	{
		if (len > 0)
		{
			if (len > this->field_width)
				this->field_width = len;
		}
		else
		{
			throw "Empty Token!!!";
			more = false;
		}
			
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
	return temp;
}



void Utilities::setDelimiter(const char delim)
{
	delimiter = delim;
}

const char Utilities::getDelimiter() const
{
	return delimiter;
}
