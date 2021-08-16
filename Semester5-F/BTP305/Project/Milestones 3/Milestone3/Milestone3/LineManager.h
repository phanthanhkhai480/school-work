#ifndef LINE_MANAGER_H
#define LINE_MANAGER_H
#include <iostream>
#include <deque>
#include <fstream>
#include <vector>
#include "CustomerOrder.h"
#include "Task.h"

class LineManager
{
	std::vector<Task*> AssemblyLine;
		/*!< array of current task in assembly line !>*/
	std::deque<CustomerOrder> ToBeFilled;
		/*!< array of deque type unfilled order !>*/
	std::deque<CustomerOrder> Completed;
		/*!< array of deque type for filled order !>*/
	unsigned int CustomerOrder_Count;		
		/*!< count number of item in array !>*/
	size_t currentTask;
		/*!< temp value for current task !>*/
	size_t nextTask;
		/*!< temp value for next task  !>*/

public:
	//Constructor sets the assembly line up by setting up the tasks pNextTask information
	//and moves all the CustomerOrder objects into the ToBeFilled queue
	LineManager(std::string& filename, std::vector<Task*>& taskObj, std::vector<CustomerOrder>& order);
		/*!< Custom Constructor !>*/	

	//Processes each assembly line task and moves the CustomerOrders through the line
	//Returning true if all items have been completed
	bool Run(std::ostream&);
		/*!< check if all of the item has been filled !>*/
};

#endif