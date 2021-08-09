#define _CRT_SECURE_NO_WARNINGS
#include "PosApp.h"
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "NonPerishable.h"
#include "Perishable.h"
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace ict
{

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
	    if (select < 0 && select > 7)
		    select = -1;
		cout << "The Sene-Store" << endl
			<< "1- List items" << endl
			<< "2- Add Perishable item" << endl
			<< "3- Add Non-Perishable item" << endl
			<< "4- Update item quantity" << endl
			<< "5- Show Item" << endl
			<< "6- POS" << endl
			<< "7- Sort" << endl
			<< "0- exit program" << endl;
		    cout << "> ";
		    cin >> select;
		    cout << endl;
	    } while (select < 0 && select > 7);
	    return select;
    }

int PosApp::sort()
{
	int select;
	do
	{
		if (select < 0 && select > 4)
			select = -1;
		cout << "Sort on:" << endl
			<< "1- Sku" << endl
			<< "2- Item Name" << endl
			<< "3- Price" << endl
			<< "4- Quantity" << endl
			<< "0- exit program" << endl;
		cout << "> ";
		cin >> select;
		cout << endl;
	} while (select < 0 && select > 4);
	return select;
}
   
void PosApp::deallocateItems()
{
    for (int counter = 0; counter < m_noOfItems; counter++)
	    if (m_items[counter])
		    delete m_items[counter];
    m_noOfItems = 0;
}
    
void PosApp::loadRecs()
{
	 deallocateItems();
	 std::fstream file;
	 file.open(m_filename, ios::in);
	 if (file.is_open() == false)
	 {
	    file.clear();
	    file.close();
	    file.open(m_filename, std::ios::out);
	    file.close();
	 }
	 else
	 {
	    while (file.good() && file.eof() == false)
	    {
		    char temp = '\0';
		    file >> temp;
		    file.ignore(1);
		    if (temp == 'P')
			    m_items[m_noOfItems] = new Perishable;
		    else if (temp == 'N')
			    m_items[m_noOfItems] = new NonPerishable;
			if (temp == 'N' || temp == 'P')
			{
			    m_items[m_noOfItems]->load(file);
			    m_noOfItems++;
			}
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
			    cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		
			    for (int counter = 0; counter < m_noOfItems; counter++)
		
			    {
				    cout.setf(ios::right);
			
				    cout.width(4);
			
				    cout << counter + 1 << " |";
			
				    cout.unsetf(ios::right);
			
				    m_items[counter]->write(cout, true);
			
				    cout << endl;
			
				    sum = sum + (m_items[counter]->cost() * m_items[counter]->quantity());
		
			    }
			    cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
			    cout << "                               Total Asset: $  |";
			    cout.width(14);
			    cout.setf(ios::right);
			    cout << setprecision(2) << fixed << sum << "|" << endl;
			    cout.unsetf(ios::right);
			    cout << "-----------------------------------------------^--------------^" << endl;
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
		    cout << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		    cout << "|--------|--------------------|-------|---|----|---------|" << endl;
		    while (!file.fail() && !file.eof() && m_noOfItems < MAX_NO_ITEMS)
		    {
			//id = '\0';
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
		        cout << "|                               Total: $  |";
		        cout.width(14);
		        cout.setf(ios::right);
		        cout << setprecision(2) << fixed << sum << "|" << endl;
		        cout.unsetf(ios::right);
		        cout << "^-----------------------------------------^--------------^" << endl;
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

		void PosApp::sortSku()
		{
			Item* temp;
			char select;
			cout << "Ascending? (y/n) ";
			cin >> select;
			if (select == 'y' || select == 'Y')
			{
				for (int counter = m_noOfItems - 1; counter > 0; counter--)
				{
					for (int count = 0; count < counter; count++)
					{
						if (strcmp( m_items[count]->sku() , m_items[count + 1]->sku()) > 0)
						{
							temp = m_items[count];
							m_items[count] = m_items[count + 1];
							m_items[count + 1] = temp;
						}
					}

				}

			}
			else if (select == 'n' || select == 'N')
			{
				for (int counter = m_noOfItems - 1; counter > 0; counter--)
				{
					for (int count = 0; count < counter; count++)
					{
						if (strcmp(m_items[count]->sku(), m_items[count + 1]->sku()) < 0)
						{
							temp = m_items[count];
							m_items[count] = m_items[count + 1];
							m_items[count + 1] = temp;
						}
					}

				}
			}
			else
				cout << "Not found!";
		}

		void PosApp::sortName()
		{
			Item* temp;
			char select;
			cout << "Ascending? (y/n) ";
			cin >> select;
			if (select == 'y' || select == 'Y')
			{
				for (int counter = m_noOfItems - 1; counter > 0; counter--)
				{
					for (int count = 0; count < counter; count++)
					{
						if (strcmp(m_items[count]->name(),m_items[count + 1]->name()) > 0)
						{
							temp = m_items[count];
							m_items[count] = m_items[count + 1];
							m_items[count + 1] = temp;
						}
					}

				}

			}
			else if (select == 'n' || select == 'N')
			{
				for (int counter = m_noOfItems - 1; counter > 0; counter--)
				{
					for (int count = 0; count < counter; count++)
					{
						if (strcmp(m_items[count]->name(), m_items[count + 1]->name()) < 0)
						{
							temp = m_items[count];
							m_items[count] = m_items[count + 1];
							m_items[count + 1] = temp;
						}
					}
				}
			}
			else
			{
				cout << "Not found!" << endl;
			}
		}

		void PosApp::sortPrice()
		{
			Item* temp;
			char select;
			cout << "Ascending? (y/n) ";
			cin >> select;
			if (select == 'y' || select == 'Y')
			{
				for (int counter = m_noOfItems - 1; counter > 0; counter--)
				{
					for (int count = 0; count < counter; count++)
					{
						if (m_items[count]->price() > m_items[count + 1]->price())
						{
							temp = m_items[count];
							m_items[count] = m_items[count + 1];
							m_items[count + 1] = temp;
						}
					}

				}

			}
			else if (select == 'n' || select == 'N')
			{
				for (int counter = m_noOfItems - 1; counter > 0; counter--)
				{
					for (int count = 0; count < counter; count++)
					{
						if (m_items[count]->price() < m_items[count + 1]->price())
						{
							temp = m_items[count];
							m_items[count] = m_items[count + 1];
							m_items[count + 1] = temp;
						}
					}
				}
			}
			else
			{
				cout << "Not found!" << endl;
			}
		}

		void PosApp::sortQuantity()
		{
			Item* temp;
			char select;
			cout << "Ascending? (y/n) ";
			cin >> select;
			if (select == 'y' || select == 'Y')
			{
				for (int counter = m_noOfItems - 1; counter > 0; counter--)
				{
					temp = '\0';
					select = '\0';
					for (int count = 0; count < counter; count++)
					{
						if (m_items[count]->quantity() > m_items[count + 1]->quantity())
						{
							temp = m_items[count];
							m_items[count] = m_items[count + 1];
							m_items[count + 1] = temp;
						}
					}

				}

			}
			else if (select == 'n' || select == 'N')
			{
				for (int counter = m_noOfItems - 1; counter > 0; counter--)
				{
					for (int count = 0; count < counter; count++)
					{
						temp = '\0';
						select = '\0';
						if (m_items[count]->quantity() < m_items[count + 1]->quantity())
						{
							temp = m_items[count];
							m_items[count] = m_items[count + 1];
							m_items[count + 1] = temp;
						}
					}
				}
			}
			else
			{
				cout << "Not found!" << endl;
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
				else if (select == 7)
				{
					int choice;
					do
					{
						choice = sort();
						if (choice == 1)
						{
							sortSku();
							cout << endl;
						}
						else if (choice == 2)
						{
							sortName();
							cout << endl;
						}
						else if (choice == 3)
						{
							sortPrice();
							cout << endl;
						}
						else if (choice == 4)
						{
							sortQuantity();
							cout << endl;
						}
						else if (choice == 0)
							cout << "Aborted!" << endl << endl;
						else
							cout << "===Invalid Selection, try again===" << endl << endl;
					} while (choice != 0);
				}
			    else if (select == 0)
			    {
				    cout << "Goodbye!" << endl;
				    cout << endl;
			    }
			    else
			    {
				    cout << "===Invalid Selection, try again===" << endl << endl;
			    }
		    } while (select != 0);
	    }
    
}
