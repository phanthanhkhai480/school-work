#define _CRT_SECURE_NO_WARNINGS
#include "PosApp.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <climits>
#include "NonPerishable.h"
#include "Perishable.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace ict
{
	/*
	ouputs:
	-------------------------------------
	update:
	Please enter the SKU: 1313
	Name:
	Paper Tissue
	Sku: 1313
	Price: 1.22
	Price after tax: 1.38
	Quantity: 194
	Total Cost: 267.45

	Please enter the number of purchased items: 12
	Updated!

	------------------------------
	Please enter the SKU: 3434
	Not found!

	-------------------------------------
	add item:
	Perishable Item Entry:
	Sku: 5656
	Name:
	Honey
	Price: 12.99
	Taxed: y
	Quantity: 12
	Expiry date (YYYY/MM/DD): 1200/10/12
	Invalid Year in Date Entry

	Perishable Item Entry:
	Sku: 5656
	Name:
	Honey
	Price: 12.99
	Taxed: y
	Quantity: 12
	Expiry date (YYYY/MM/DD): 2017/5/15
	Item added.

	--------------------------------------------
	list item:
	 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
	-----|--------|--------------------|-------|---|----|---------|
	   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
	   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
	   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
	   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
	   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
	   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
	-----^--------^--------------------^-------^---^----^---------^
								   Total Asset: $  |       1436.59|
	-----------------------------------------------^--------------^


	--------------------------------------
	printbill:
	v--------------------------------------------------------v
	| 2017/04/02, 12:42                                      |
	| SKU    | Item Name          | Price |TX |Qty |   Total |
	|--------|--------------------|-------|---|----|---------|
	| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
	| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
	| 5656   |Honey               |  12.99| TP|   1|    14.68|
	^--------^--------------------^-------^---^----^---------^
	|                               Total: $  |         22.05|
	^-----------------------------------------^--------------^

	-------------------------------------------------------
	POS:
	Sku: 1212
	v------------------->
	| Salted Butter
	^------------------->
	Sku: 1212
	v------------------->
	| Salted Butter
	^------------------->
	Sku: 1313
	v------------------->
	| Paper Tissue
	^------------------->
	Sku: 1234
	v------------------->
	| Milk
	^------------------->
	Sku: 7654
	Not found!
	Sku: 5656
	v------------------->
	| Honey
	^------------------->
	Sku:
	v--------------------------------------------------------v
	| 2017/04/02, 12:58                                      |
	| SKU    | Item Name          | Price |TX |Qty |   Total |
	|--------|--------------------|-------|---|----|---------|
	| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
	| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
	| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
	| 1234   |Milk                |   3.99|  P|   1|     3.99|
	| 5656   |Honey               |  12.99| TP|   1|    14.68|
	^--------^--------------------^-------^---^----^---------^
	|                               Total: $  |         32.03|
	^-----------------------------------------^--------------^

	------------------------------------------------------
	run:
	The Sene-Store
	1- List items
	2- Add Perishable item
	3- Add Non-Perishable item
	4- Update item quantity
	5- Show Item
	6- POS
	0- exit program
	> 5

	Please enter the SKU: 5656
	v-----------------------------------v
	Name:
	Honey
	Sku: 5656
	Price: 12.99
	Price after tax: 14.68
	Quantity: 10
	Total Cost: 146.79
	Expiry date: 2017/05/15
	^-----------------------------------^

	The Sene-Store
	1- List items
	2- Add Perishable item
	3- Add Non-Perishable item
	4- Update item quantity
	5- Show Item
	6- POS
	0- exit program
	> 5

	Please enter the SKU: 12345
	Not found!

	The Sene-Store
	1- List items
	2- Add Perishable item
	3- Add Non-Perishable item
	4- Update item quantity
	5- Show Item
	6- POS
	0- exit program
	> five

	===Invalid Selection, try again===

	The Sene-Store
	1- List items
	2- Add Perishable item
	3- Add Non-Perishable item
	4- Update item quantity
	5- Show Item
	6- POS
	0- exit program
	> 0

	Goodbye!

	*/
	PosApp::PosApp(const char * filename, const char * billfname)
	{
		strncpy(this->m_filename, filename, 128);
		strncpy(this->m_billfname, billfname, 128);
		loadRecs();
	}

	int PosApp::menu()
	{
		int select;
		do
		{
			if (select < 0 && select > 6)
				select = -1;
			cout << "The Sene-Store" << endl
				<< "1- List items" << endl
				<< "2- Add Perishable item" << endl
				<< "3- Add Non-Perishable item" << endl
				<< "4- Update item quantity" << endl
				<< "5- Show Item" << endl
				<< "6- POS" << endl
				<< "0- exit program" << endl;
			cout << "> ";
			cin >> select;
			cout << endl;
		} while (select < 0 && select > 6);
		return select;
	}

	void PosApp::deallocateItems()
	{
		for (int counter = 0; counter < m_noOfItems; counter++)
			if (m_items[counter])
				delete m_items[counter];
		m_noOfItems = 0;
	}

	void PosApp::loadRecs(){
		deallocateItems();
		std::fstream file;
		file.open(m_filename, ios::in);
		if (file.is_open() == false){
			file.clear();
			file.close();
			file.open(m_filename, std::ios::out);
			file.close();	}
		else	{
			while (file.good() && file.eof() == false)	{
				char temp;
				file >> temp;
				file.ignore(1);
				if (temp == 'P')
					m_items[m_noOfItems] = new Perishable;
				else if (temp == 'N')
					m_items[m_noOfItems] = new NonPerishable;
				if (temp == 'N' || temp == 'P'){
					m_items[m_noOfItems]->load(file);
					m_noOfItems++;	}
			}
		}
		file.close();
	}

	void PosApp::saveRecs()
	{
		std::fstream file;
		file.open(m_filename, ios::out);
		for (int counter = 0; counter < m_noOfItems; counter++)
		{
			if (m_items[counter]->quantity() > 0)
				m_items[counter]->save(file);
		}
		file.close();
		loadRecs();
	}

	int PosApp::searchItems(const char * sku) const
	{
		int itemIndex = 0;
		for (int counter = 0; counter < m_noOfItems; counter++)
		{
			if (strcmp(sku, m_items[counter]->sku()) == 0)
			{
				itemIndex = counter;
				break;
			}
			else
				itemIndex = -1;
		}
		return itemIndex;
	}

	void PosApp::updateQty()
	{
		char sku[MAX_SKU_LEN];
		int quantity;
		int index;
		cout << "Please enter the SKU: ";
		cin >> sku;
		index = searchItems(sku);
		if (index == -1)
			cout << "Not found!" << endl;
		else
		{
			m_items[index]->write(cout, false);
			cout << endl << "Please enter the number of purchased items: ";
			cin >> quantity;
			m_items[index]->quantity(m_items[index]->quantity() + quantity);
			//m_items[index]->operator+=(quantity);
			saveRecs();
			cout << "Updated!" << endl;
		}
	}

	void PosApp::addItem(bool isPerishable) {
		Item * product;
		if (isPerishable == true)
			product = new Perishable;
		else
			product = new NonPerishable;
		product->read(cin);
		cin.ignore();
		if (!cin) 
		{
			cin.clear();
			cin.ignore(10000, '\n');
			product->write(cout, false);
			cout << endl;
		}
		else 
		{
			m_items[m_noOfItems] = product;
			m_noOfItems++;
			saveRecs();
			cout << "Item added." << endl;
		}
	}

	void PosApp::listItems() const
	{
		double sum = 0;
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;		for (int counter = 0; counter < m_noOfItems - 1; counter++)		{			cout.setf(ios::right);			cout.width(4);			cout << counter + 1 << " |";			cout.unsetf(ios::right);			m_items[counter]->write(cout, true);			cout << endl;			sum = sum + (m_items[counter]->cost() * m_items[counter]->quantity());		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
		cout << "                                    Total Asset: $  |";
		cout.width(9);
		cout.setf(ios::right);
		cout << setprecision(2) << fixed << sum << "|" << endl;
		cout.unsetf(ios::right);
		cout << "----------------------------------------------------^---------^" << endl;
	}

	void PosApp::truncateBillFile()
	{
		fstream file;
		file.open(m_billfname, ios::out | ios::trunc);
		file.close();
	}

	void PosApp::showBill()
	{
		Date today;
		char id;
		double sum = 0;
		Item* product;
		fstream file;

		file.open(m_billfname, ios::in);
			cout << "v--------------------------------------------------------v" << endl;
			cout << "| " << today << "                                      |" << endl;
			cout << "| SKU    |  Item Name         | Price |TX |Qty |   Total |" << endl;
			cout << "|--------|--------------------|-------|---|----|---------|" << endl;
			while (!file.fail() && m_noOfItems < MAX_NO_ITEMS)
			{
				file >> id;
				if (id == 'P')
					product = new Perishable;
				else if (id == 'N')
					product = new NonPerishable;
				if (id == 'N' || id == 'P')
				{
					file.get();
					product->load(file);
					cout.unsetf(ios::right);
					cout << "|";
					product->write(cout, true);
					cout << endl;
					sum = sum + ( product->cost() * product->quantity() );	
				}
			}
			cout << "^--------^--------------------^-------^---^----^---------^" << endl;
			cout << "                                Total: $  |";
			cout.width(14);
			cout.setf(ios::right);
			cout << setprecision(2) << fixed << sum << "|" << endl;
			cout.unsetf(ios::right);
			cout << "------------------------------------------^--------------^" << endl;
		file.close();
		truncateBillFile();
		saveRecs();
	}

	void PosApp::addToBill(Item& I)
	{
		int quantity;
		fstream file;
		file.open(m_billfname, ios::out | ios::app);
		quantity = I.quantity();
		I.quantity(1);
		I.save(file);
		I.quantity(quantity - 1);
		saveRecs();
	}

	void PosApp::POS()
	{
		char sku[MAX_SKU_LEN];
		sku[0] = '\0';
		fstream file;
		file.open(m_billfname, ios::out);
		cin.ignore(1000, '\n');
		bool done;
		while (!done)
		{
			cout << "Sku: ";
			cin.getline(sku, MAX_SKU_LEN);
			if (strcmp(sku, "") == 0 && sku[0] == '\0')
			{
				showBill();
				done = true;
			}
			else
			{
				int check = searchItems(sku);
				if (check != -1)
				{
					cout << "v------------------->" << endl;
					cout << "| " << m_items[check]->name() << endl;
					cout << "^------------------->" << endl;
					addToBill(*m_items[check]);
				}
				else
				{
					cout << "Not found!" << endl;
				}
			}
		}
	}

	void PosApp::run()
	{
		char sku[MAX_SKU_LEN];
		int select;
		do
		{
			select = menu();
			if (select == 1)
			{
				listItems();
				cout << endl;
			}
			else if (select == 2)
			{
				addItem(true);
				cout << endl;
			}
			else if (select == 3)
			{
				addItem(false);
				cout << endl;
			}
			else if (select == 4)
			{
				updateQty();
				cout << endl;
			}
			else if (select == 5)
			{
				int check;
				cout << "Please enter the SKU: ";
				cin >> sku;
				check = searchItems(sku);
				if (check == -1)
				{
					cout << "Not Found!" << endl;
				}
				else
				{
					cout << "v-----------------------------------v" << endl;
					m_items[check]->write(cout, false);
					cout << "^-----------------------------------^" << endl;
				}
				cout << endl;
			}
			else if (select == 6)
			{
				POS();
				cout << endl;
			}
			else if (select == 0)
			{
				cout << "Goodbye!!" << endl;
				cout << endl;
			}
			else
			{
				cout << "===Invalid Selection, try again===" << endl << endl;
				cout << endl;
			}
		} while (select != 0);
	}

}