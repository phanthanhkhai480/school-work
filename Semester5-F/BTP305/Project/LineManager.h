// Name: Neel Rathod
// Seneca Student ID: 100443167
// Seneca email: nrathod1@myseneca.ca
// Date of completion: December 2, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <vector>
#include <deque>
#include <iostream>
#include "Task.h"
#include "CustomerOrder.h"


class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	size_t m_firstTask;
	size_t m_lastTask;

public:
	LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};

#endif // LINEMANAGER_H