#include<iostream>
#include"kingdom.h"
using namespace std;

namespace westeros
{
	void display(Kingdom &pKingdom) 
	{
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}

}