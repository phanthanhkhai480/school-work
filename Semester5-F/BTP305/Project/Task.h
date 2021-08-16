// Name: Neel Rathod
// Seneca Student ID: 100443167
// Seneca email: nrathod1@myseneca.ca
// Date of completion: December 2, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef TASK_H
#define TASK_H
#include <deque>
#include <ostream>
#include <string>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item {
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:
	Task(const std::string&);
	Task(Task&) = delete;	//copy constructor
	Task(Task&&) = delete;  //move constructor
	
	Task& operator=(Task&) = delete;	//copy operator
	Task& operator=(Task&&) = delete;   //move operator

	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};

#endif // TASK_H