#ifndef ADAPTER_H
#define ADAPTER_H
#include "linkedlist.h"
#include "queue"

//the Expected interface for a Queue
//FIFO
class Queue{
public:
    Queue(){}
    virtual void enqueue(const int& o)=0;
    virtual void dequeue()=0;
    virtual int front() const=0;
    virtual bool isEmpty() const=0;
    virtual int numItems() const=0;
    virtual ~Queue(){}
};


//class below is not completed... you must structure this as a object adapter
//with appropriate requests and calls inheritance structure etc.
class ObjectAdapter : public Queue{
private:
    DList oa;
public:
	ObjectAdapter(){}
    void enqueue(const int& o) 			{	oa.push_front(o);			}
    void dequeue()						{	oa.pop_back();				}
    int front() const					{	return oa.backData();	}
    bool isEmpty() const				{	return oa.empty(); 	}
	int numItems() const				{	return oa.size();		}
};


//class below is not completed... you must structure this as a class adapter
//with appropriate requests and calls inheritance structure etc.
class ClassAdapter : private DList, public Queue{
private:
public:
    void enqueue(const int& o)			{ 	DList::push_front(o);		}
    void dequeue()						{	DList::pop_back();		}
    int front() const					{	return DList::backData();			}
    bool isEmpty() const				{	return DList::empty();			}
    int numItems() const				{	return DList::size();		}
};
#endif
