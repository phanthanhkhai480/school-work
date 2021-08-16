#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <deque>
#include "Item.h"
#include "CustomerOrder.h"


class Task : public Item
{
	std::deque<CustomerOrder> Orders;
		/*!< current set of orders in deque type in a task !>*/
	Task* pNextTask;
		/*!< pointer type to next available task !>*/
public:
	Task(std::string&);								
		/*!< Custom Constructor !>*/
	Task(Task&) = delete;	/*!< Uninitialized copy constructor !>*/
	Task& operator=(Task&) = delete;	/*!< Uninitialized copy assignment !>*/
	Task(Task&&) = delete; /*!< Uninitialized move constructor !>*/
	Task& operator=(Task&&) = delete;	/*!< Uninitialized move assignment !>*/

	void RunProcess(std::ostream& os);					
		//This function fills the last order on the order queue
		/*!< fill last order on order queue !>*/
	
	bool MoveTask();								
		//This function moves the completed task to the next part of the assembly line
		/*!< move move completed task to next part !>*/
	
	void setNextTask(Task& task);						
		//Sets up the pointer to the next task if the tasks names line up
		/*!< set the next available task for the order  !>*/
	
	bool getCompleted(CustomerOrder &src);
		/*!< complete the order on queue !>*/

	void Validate(std::ostream& os);
		/*!< validate the next available task !>*/
	
	Task& operator+=(CustomerOrder&& newOrder);				
		/*!< move an order to the front of the queue !>*/
};

#endif