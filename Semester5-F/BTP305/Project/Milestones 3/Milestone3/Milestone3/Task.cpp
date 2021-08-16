#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Task.h"
using namespace std;

//pass string abc directly to Item constructor
Task::Task(std::string & abc) : Item(abc)
{
	this->pNextTask = nullptr;
}


//check for if any unfilled item
//find unfilled item and fill it
void Task::RunProcess(std::ostream & os)	
{
	if (!Orders.empty())
	{
		if (!Orders.front().getOrderFillState())
		{
			while (!Orders.front().getItemFillState(getName()))
			{
				Orders.front().fillItem(*this, os);
			}
		}
	}
}


//check if Orders is unempty and pNextTask is empty
//check for fillstate of the item, if true pass to nextTask
//remove the item from Orders queue if fillstate is true
bool Task::MoveTask()	
{
	if (!Orders.empty())
	{
		/*
		if (pNextTask != nullptr)
			pNextTask == nullptr;
		*/
		if (Orders.front().getItemFillState(getName()))
		{
			*pNextTask += move(Orders.front());
			Orders.pop_front();
		}		
		return true;
	}
	else
		return false;
}

//set task object to pNextTask
void Task::setNextTask(Task & task)	
{
	pNextTask = &task;
}


//check for Orders in queue
//remove last item and pass to argument
bool Task::getCompleted(CustomerOrder & src)
{
	if (!Orders.empty() && Orders.front().getOrderFillState()) 
	{
		src = move(Orders.front());
		Orders.pop_front();
		return true;
	}
	else 
		return false;
}


//validate if there is any existing order and next order
void Task::Validate(std::ostream & os)	
{
	os << getName();
	if (pNextTask != nullptr)
		os << "Next Task: " << pNextTask->getName();
	os << endl;	
}


//pass newOrder to the front of the queue
Task & Task::operator+=(CustomerOrder && newOrder)
{
	Orders.push_back(move(newOrder));
	return *this;	
}









//Composition Class
#include "Name.h"
//sub-object
//default copy and assignment rules apply
//sufficient copy constructor, assignment
//opererator and destructor
Name name;	 //sub-object declare
Person::Person(const char* n, int a) :
	name{ n }, age{ a } {}

//pointer
//has to set new object, assignment
//operato destroy and create new one
//destructor responsible to destroy it last
Name* name; //pointer declare
Person::Person(const char* n, int a) :
	name{ new Name(n) }, age{ a } {}
Person& Person::operator=(const Person&) {}
Person::~Person() { delete name; }

//Aggregations Class
//modify entity of an instances
int main() {
	Name jane("Jane");
	Name john("John");
	Club c;
	c += jane;
	c += john;
	c -= john;	}
//john will be remove from club

//Association Class
//modify entity without affecting them
void book(Course& c, Room& r) {
	c.book(r) {
		if (room) room->unbook()
		room = &r;
	}
	r.book(c) {
		if (course) course->unbook()
		course = &c;
	}	}
int main() {
	Room t2108("T2108");
	Room t2109("T2109");
	book(courseA, t2108);
	book(courseA, t2109);	}
//course change room, room will still there