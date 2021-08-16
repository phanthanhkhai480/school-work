#ifndef CUSTOMER_ORDER_H
#define CUSTOMER_ORDER_H
#include <iostream>
#include <string>
#include "Utilities.h"
#include "Item.h"

class Item;

struct ItemInfo
{
	std::string ItemName;
	unsigned int SerialNumber;
	bool FillState;

	ItemInfo(std::string src) : ItemName(src), SerialNumber(0), FillState(false) {};
};

class CustomerOrder
{
	std::string Name;			/*!< type string for customer's name !>*/
	std::string Product;		/*!< type string for customer's product !>*/
	unsigned int ItemCount;		/*!< type int for number of item in order !>*/
	ItemInfo** ItemList;		/*!< object ItemInfo !>*/
	unsigned int field_width;	/*!< maximum display length !>*/

public:
	CustomerOrder();			/*!< default constructor !>*/
	CustomerOrder(std::string&);/*!< customer constructor !>*/
	~CustomerOrder();			/*!< destructor !>*/

	//Object is not allowed to be copied
	CustomerOrder(CustomerOrder&) { throw "ERROR:  Copy is not allows";  };	
		/*!< copy constructor !>*/
		//should throw an exception if called
	
	CustomerOrder& operator=(CustomerOrder&) = delete;
		/*!< copy assignment operator !>*/

	//Object move functionality
	CustomerOrder(CustomerOrder&& abc); /*!< move constructor !>*/

	CustomerOrder& operator=(CustomerOrder&& abc);
		/*!< move assignment operator !>*/
	
	bool getOrderFillState();			
		/*!< function check for FillState of Order !>*/	
		//Returns true if order completely filled, false otherwise

	bool getItemFillState(std::string itemName);
		/*!< function check for specific fill state of an item !>*/
		//Returns true if the given item has been filled
	
	void fillItem(Item& item_, std::ostream& os);
		/*!< function display list of item in order !>*/
		//Fills the customer order item if the inventory on Item is available

	void Display(std::ostream& os);		
		/*!< funtion display !>*/
		//Displays the details of the CustomerOrder to the ostream object provided

};

#endif