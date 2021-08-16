/*! \file Message.h
// \brief BTP305 Workshop 4: Containers
// \details    Longer description of file
// \version 1.0
// \date 2018
// \author Khai Phan
// \copyright GNU Public License.
//
//
**/

#ifndef MESSAGE_H
#define MESSAGE_H
#include <fstream>
#include <string>

namespace w5
{
	class Message
	{
		std::string mess; /*!< type data of string with an array !>*/
		std::string user;	/*!< type data of string with an array !>*/
		std::string reply;	/*!< type data of string with an array !>*/
		std::string tweet;	/*!< type data of string with an array !>*/
	public:
		Message();	/*!<Default constructor */ 
		Message(std::ifstream& in, char c); /*!<Custom constructor */ 
		bool empty() const;	/*!<Check for empty data */ 
		void display(std::ostream& os) const;	/*!<Display data */ 
	};
}

#endif