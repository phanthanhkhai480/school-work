#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
#include <fstream>
#include <iostream>

class Utilities 
{
	size_t field_width;		/*!< attribute to set max field width for display !>*/ 
	static char delimiter;	/*!< delimiter use to break string !>*/

public:
	Utilities();	 /*!< Default Constructor !>*/
	void setFieldWidth(size_t);		/*!< set field_width with a value !>*/
	size_t getFieldWidth() const;	/*!< function return field_width length !>*/
	const std::string extractToken(const std::string&, size_t&, bool&);
		/*!< function break down string, begin a certain position and stop at deliminator !>*/	
	static void setDelimiter(const char);
		/*!< set delimiter to break down string !>*/
	const char getDelimiter() const;
		/*!< function return delimiter !>*/
};

#endif