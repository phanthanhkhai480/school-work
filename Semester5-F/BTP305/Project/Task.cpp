// Name: Neel Rathod
// Seneca Student ID: 100443167
// Seneca email: nrathod1@myseneca.ca
// Date of completion: December 2, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Task.h"

Task::Task(const std::string& str) : Item(str) {
	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (!m_orders.front().getOrderFillState()) {
			// is there multiple items when its running?
			while (!m_orders.front().getItemFillState(getName())) {
				// is stock aviliable?
				if (!getQuantity())
					throw std::string("***There are no more [") + getName() + "] in stock!***";
				m_orders.front().fillItem(*this, os);
			}
		}
	}
}

bool Task::moveTask() 
{
	if (!m_orders.empty()) 
	{
		if (m_pNextTask) 
		{
			if (m_orders.front().getItemFillState(getName())) 
			{
				*m_pNextTask += std::move(m_orders.front());
				m_orders.pop_front();
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void Task::setNextTask(Task& nextTask) {
	m_pNextTask = &nextTask;
}

bool Task::getCompleted(CustomerOrder& custOrder) {
	if (!m_orders.empty() && m_orders.front().getOrderFillState()) {
		custOrder = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}

void Task::validate(std::ostream& os) {
	os << getName() << " --> ";
	os << (m_pNextTask ? m_pNextTask->getName() : "END OF LINE");
	os << std::endl;
}

Task& Task::operator+=(CustomerOrder&& custOrder) {
	m_orders.push_back(std::move(custOrder));

	return *this;
}