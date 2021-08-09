#include<iostream>
#include<cstring>
#include"kingdom.h"
using namespace std;

namespace westeros
{
	void display(Kingdom &pKingdom)
	{		
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}
	void display(Kingdom pKingdom[], int num)
	{
		int sum = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros" << endl;
		cout << "------------------------------" << endl;
		for (int counter = 0; counter < num; counter++)
		{
			cout << counter + 1 << ". " << pKingdom[counter].m_name << ", population " << pKingdom[counter].m_population << endl;
			sum = sum + pKingdom[counter].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of Westeros: " << sum << endl;
		cout << "------------------------------" << endl;
	}
	void display(Kingdom pKingdom[], int num1, int min)
	{
		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros with more than " << min << " people" << endl;
		cout << "------------------------------" << endl;
		for (int counter = 0; counter < num1; counter++)
		{
			if (pKingdom[counter].m_population >= min)
			{
				cout << pKingdom[counter].m_name << ", population " << pKingdom[counter].m_population << endl;
			}
		}
		cout << "------------------------------" << endl;
	}
	void display(Kingdom pKingdom[], int num2, const char* name)
	{
		int found = 1;
		cout << "------------------------------" << endl;
		cout << "Searching for kingdom " << name << " in Westeros" << endl;
		cout << "------------------------------" << endl;
		for (int counter = 0; counter < num2; counter++)
		{
			if (strcmp(name, pKingdom[counter].m_name) == 0) 
			{
				cout << pKingdom[counter].m_name << ", population " << pKingdom[counter].m_population << endl;
				found = 0;
			}			
		}
		if(found==1)
			cout << name << " is not part of Westeros." << endl;
		cout << "------------------------------" << endl;
	}
}