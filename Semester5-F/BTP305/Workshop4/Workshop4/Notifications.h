/*! \file Notification.h
// \brief BTP305 Workshop 4: Containers
// \details    Longer description of file
// \version 1.0
// \date 2018
// \author Khai Phan
// \copyright GNU Public License.
//
//
**/

#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include "Message.h"
#include <vector>

/*!
* a namespace dedicated to the workshop
*/
namespace w5
{
	class Notifications
	{
		//std::vector<Message> noti;
		Message* noti;		/*!< type data of Message with attribute noti !>*/
	public:
		Notifications();	/*!< Defaul Constructor !>*/
		Notifications(const Notifications& abc);	/*!<Copy constructor */
		Notifications& operator=(const Notifications& abc);	 /*!<Copy Assignment Operator */
		Notifications(Notifications&& abc);			/*!<Move constructor */  
		Notifications operator=(Notifications&& abc);		/*!<Move Assignment Operator */ 
		~Notifications();	/*!<Destructor */ 
		void operator+=(const Message& msg);	/*!<Add data to arrays */ 
		void display(std::ostream& os) const;	/*!<Display data */ 
	};
}

#endif