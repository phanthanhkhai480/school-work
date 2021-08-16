#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "LineManager.h"
using namespace std;

LineManager::LineManager(std::string & filename, 
	std::vector<Task*>& taskObj, std::vector<CustomerOrder>& order)
{
	AssemblyLine = taskObj;
	for (size_t c = 0; c < order.size(); ++c)
		ToBeFilled.push_back(move(order[c]));
	
	ifstream file(filename);
	Utilities abc;
	string temp, temp1, temp2;
	size_t pos = 0;
	bool check = true, priority = true;

	while (!file.eof())
	{
		getline(file, temp);
		temp1 = abc.extractToken(temp, pos, check);
		pos = temp1.size() + 1;

		//if next task is available
		if (pos <= temp.size())
			temp2 = abc.extractToken(temp, pos, check);

		for (size_t a = 0; a < AssemblyLine.size(); ++a)
		{
			if (AssemblyLine[a]->getName() == temp1)
			{
				if (priority)
				{
					currentTask = a;
					priority = !priority;
				}
				if (temp2.empty() == false)
				{
					for (size_t	b = 0; b < AssemblyLine.size(); ++b)
					{
						if (AssemblyLine[b]->getName() == temp2)
						{
							AssemblyLine[a]->setNextTask(*taskObj[b]);
							break;
						}
					}
				}
				else
					nextTask = a;
				break;
			}
		}
		pos = 0;
		check = true;
		temp1.clear();
		temp2.clear();	
	}

	
	
}

bool LineManager::Run(std::ostream &os)
{
	CustomerOrder check;
	bool temp = true;

	if (!ToBeFilled.empty())
	{
		*AssemblyLine[currentTask] += move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	if (!Completed.empty())
	{
		if (AssemblyLine[nextTask]->getCompleted(check))
			Completed.push_back(move(check));
	}
		
	for (size_t a = 0; a < AssemblyLine.size(); ++a)
		AssemblyLine[a]->RunProcess(os);

	for (size_t b = 0; b < AssemblyLine.size(); ++b)
	{
		if (AssemblyLine[b]->MoveTask())
			temp = false;
	}

	cout << "ToBeFilled: "<< ToBeFilled.size() << endl;
	cout << "Completed: " << Completed.size() << endl;
	cout << "Assembly: " << AssemblyLine.size() << endl;

	//display Completed item for checking
	if (!Completed.empty())
	{
		for (size_t c = 0; c < Completed.size(); ++c)
		{
			os << "COMPLETED" << endl;
			Completed[c].Display(os);
		}
	}

	return temp;
}