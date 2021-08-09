// TODO: add your headers here
#include<iostream>
#include<cstring>
#include "passenger.h"
// TODO: add the namespaces that you will be using here
using namespace std;
// TODO: holiday namespace here
namespace holiday
{
	// TODO: add the default constructor here
	Passenger::Passenger()
	{
		edit();
	}
	void Passenger::edit()
	{
		this->m_name[0] = '\0';
		this->m_destination[0] = '\0';
		this->m_departureDay = 0;
		this->m_departureMonth = 0;
		this->m_departureYear = 0;
	}
	// TODO: add the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination)
	{ 
		if (name == nullptr || name[0] == '\0' || destination == nullptr || destination[0] == '\0')
		{
			edit();
		}
		else
		{
			strcpy(m_name, name);
			strcpy(m_destination, destination);
			this->m_departureDay = 1;
			this->m_departureMonth = 7;
			this->m_departureYear = 2017;
		}

	}

	// TODO: add the isEmpty() function here
	bool Passenger::isEmpty() const
	{
		if (this->m_destination[0] == '\0' || this->m_name[0] == '\0')
			return true;
		return false;
	}

	// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger& other) const
	{
		int day = 0, month = 0, year = 0;
		int check = strcmp(this->m_destination, other.m_destination);
		if (this->m_departureDay == other.m_departureDay)
		{
			day = 1;
		}
		if (this->m_departureMonth == other.m_departureMonth)
		{
			month = 1;
		}	
		if (this->m_departureYear == other.m_departureYear)
		{
			year = 1;
		}
		if (check == 0 && day == 1 && month == 1 && year == 1)
			return true;
		return false;

	}

	// below is the member function already provided
	// TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
					<< "The journey will start on "
					<< this->m_departureYear << "-"
					<< this->m_departureMonth << "-"
					<< this->m_departureDay
					<< "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}
	}

}