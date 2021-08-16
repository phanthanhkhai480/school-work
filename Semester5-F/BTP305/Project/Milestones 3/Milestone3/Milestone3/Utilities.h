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














//Multiple Inheritance
class Emitter {};	class Shape {};
class LitObj : public Emitter {};
class Cube : public Shape {};
class LitCub : public Cube, public LitObj {};
//Diamond Problem
//2 class inherited the same base class
class NLitObj : virtual public Emitter {};
class NCube : virtual public Shape {};
//this way, only 1 constructor is called
class NLitCube : public Cube, public LitObj {
  NLitCube(const char* n, double l, long c) :
	NCube(n, l), Name(n), NLitObj(n, c) {};	};


template<typename T>
DataTable<T>::DataTable(std::ifstream & abc,
	const int& wdt, const int& decimal)
{	this->width = wdt; this->decimalCount = decimal;
	T x_tmp, y_tmp;

	if (abc.is_open() == true) 
	{	while (abc.good()) 
		{	abc >> x_tmp >> y_tmp;
			if (!abc.fail())
			{	x_int.push_back(x_tmp);
				y_int.push_back(y_tmp);
			}	}	}	}



void SecureData::code(char key) {
	int div = this->nbytes / 4;
	auto connect1 = std::bind(converter, text + div * 3, 
		key, this->nbytes - (div * 3), Cryptor());
	std::thread c1(connect1);
	auto connect2 = std::bind(converter, text + div * 2, 
		key, this->nbytes - (div * 2), Cryptor());
	std::thread c2(connect2);
	auto connect3 = std::bind(converter, text + div, 
		key, div, Cryptor());
	std::thread c3(connect3);
	c3.join();	c2.join();	c1.join();
}

