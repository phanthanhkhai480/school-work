#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <iomanip>
#include "Utilities.h"

const unsigned int CODE_WIDTH = 5;

class Item
{
	std::string name;			/*!< variable of type string hold product name !>*/
	unsigned serialNumber;		/*!< variable of type unsigned int hold product serial !>*/
	unsigned int Quantity;		/*!< variable of type unsigned int hold product quantity !>*/
	std::string description;	/*!< variable of type string hold product description !>*/
	unsigned int field_width;	/*!< variable of type unsigned int hold display length!>*/

public:
	Item(const std::string& record);	
		/*!< custom constructor parses data from string !>*/
	const std::string& getName() const;	
		/*!< function return product name !>*/	
	const unsigned int getSerialNumber() const;	
		/*!< function return product serial !>*/	
	const unsigned int getQuantity() const;		
		/*!< function return product quantity !>*/	
	void updateQuantity();		/*!< function update product quantity !>*/	
	void display(std::ostream&, bool) const;
		/*!< display function !>*/
};

#endif