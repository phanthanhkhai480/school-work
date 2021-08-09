// TODO: include the necessary headers
#include<iostream>
#include <cstring>
#include "kingdom.h"

using namespace std;
// TODO: the westeros namespace
namespace westeros {

	// TODO:definition for display(...) 
	void display(Kingdom &theKingdom)
	{
		cout << theKingdom.m_name << ", population " << theKingdom.m_population << endl;			
	}



 	void display(Kingdom *theKingdom, int count)
	{
		int totalPop = 0;
		cout << "------------------------------" << endl
			<< "Kingdom of Westeros" << endl
			<< "------------------------------" << endl;

		for (int i = 0; i < count; i++)
		{
			cout << (i + 1) << ". " << theKingdom[i].m_name << ", population " << theKingdom[i].m_population << endl;

			totalPop += theKingdom[i].m_population;
		}

		cout << "------------------------------" << endl
			<< "Total population of Westeros: " <<  totalPop << endl
			<< "------------------------------" << endl;
	}

	
	void display(Kingdom *theKingdom, int count , int minPopulation)
	{
		cout << "------------------------------" << endl
			<< "Kingdom of Westeros with more than " << minPopulation << endl
			<< "------------------------------" << endl;

		for (int i = 0; i < count; i++)
		{
			if (theKingdom[i].m_population >= minPopulation)
			{
				cout << theKingdom[i].m_name << ", population " << theKingdom[i].m_population << endl;
			}
		}

		cout << "------------------------------" << endl;

	}
	
	void display(Kingdom *theKingdom, int count,const char *lookFor)
	{

		cout << "------------------------------" << endl
			<< "Searching for kingdom " 
			<< lookFor << " in Westeros" << endl
			<< "------------------------------" << endl;

		int found = -1;

		for (int i = 0; i < count; i++)
		{
			if (strcmp(theKingdom[i].m_name, lookFor) == 0)
			{
				cout << theKingdom[i].m_name << ", population " << theKingdom[i].m_population << endl;
				found = 0;
			}

		}

		if (found == -1)
		{
			cout << lookFor << " is not part of Westeros." << endl;
		}

		cout << "------------------------------" << endl;
	}
}

