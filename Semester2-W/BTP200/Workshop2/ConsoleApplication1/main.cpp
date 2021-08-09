#include <iostream>
#include "kingdom.h"
using namespace std;
using namespace westeros;

int main(void)
{
	int count = 0; // the number of kingdoms in the array
	// TODO: declare the pKingdoms pointer here (don't forget to initialize it to null)
	Kingdom* pKingdoms = nullptr;
	cout << "==========" << endl
		<< "Input data" << endl
		<< "==========" << endl
		<< "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();
	// TODO: allocate dynamic memory here for the pKingdoms pointer
	pKingdoms = new Kingdom[count];
	for (int i = 0; i < count; ++i)
	{
		// TODO: add code to accept user input for the pKingdoms array
		cout << "Enter the name for kingdom #" << i+1 << ": ";
		cin >> pKingdoms[i].m_name;
		cout << "Enter the number people living in " << pKingdoms[i].m_name << ": ";
		cin >> pKingdoms[i].m_population;
	}
	cout << "==========" << endl << endl;
	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The first kingdom of Westeros" << endl
		<< "------------------------------" << endl;
	display(pKingdoms[0]);
	cout << "------------------------------" << endl << endl;
	// TODO: deallocate the dynamic memory here
	delete[] pKingdoms;
	return 0;
}