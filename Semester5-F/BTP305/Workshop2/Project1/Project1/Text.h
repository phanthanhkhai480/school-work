// Workshop 2 - Copy and Move Semantics
// Text.h
// Author:  Khai Phan
// Date:    2018-09-20


#ifndef TEXT_H
#define TEXT_H
#include <string>

/*!
* a namespace dedicated to the workshop
*/
namespace w2
{
	/*!
	* a class dedicated to the workshop
	*/
	class Text
	{
		size_t record;						/*!< unsigned int calculated number of character in file */
		std::string* txt;					/*!< Stores data into object with records */ 
	public:
		Text();								/*!<Default constructor */ 
		Text(const std::string& abc);		/*!<Custom constructor */ 
		Text(const Text& abc) ;				/*!<Copy constructor */ 
		Text& operator=(const Text& abc);	/*!<Copy Assignment Operator */ 
		Text(Text&& abc);					/*!<Move constructor */ 
		Text& operator=(Text&& abc);		/*!<Move Assignment Operator */ 
		~Text();							/*!<Destructor */ 
		size_t size() const;				/*!<Return number of record */ 
	};
}


#endif

