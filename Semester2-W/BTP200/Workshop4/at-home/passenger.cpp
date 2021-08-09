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
		this->m_departureDay = -1;
		this->m_departureMonth = -1;
		this->m_departureYear = -1;
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
		if (this->m_destination[0] == '\0' || this->m_name[0] == '\0' || this->m_departureDay == 0 || this->m_departureMonth == 0 || this->m_departureYear == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger& other) const
	{
		int day = 1, month = 1, year = 1;
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
	Passenger::Passenger(const char * name, const char * destination, int years, int months, int days)
	{
		if ((name == nullptr || name[0] == '\0') || (destination == nullptr || destination[0] == '\0') ||
			(years < 2017 || years > 2020) ||
			(months < 1 || months > 12) ||
			(days < 1 || days > 31))
		{
			edit();
		}
		else
		{
			strcpy(this->m_name, name);
			strcpy(this->m_destination, destination);
			this->m_departureDay = days;
			this->m_departureMonth = months;
			this->m_departureYear = years;
		}
			
	}
	
	void Passenger::travelWith(const Passenger* arrPassengers, int size)
	{
		int check = 0;
		for (int counter = 0; counter < size; counter++)
		{
			int hold = canTravelWith(arrPassengers[counter]);
			if (hold == 1)
				check++;
		}
		if (check == 0)
		{
			cout << "Nobody can join "; 
			this->display(true);
			cout << " on vacation!" << endl;
		}
		else if (check == size)
		{
			cout << "Everybody can join "; 
			this->display(true);
			cout << " on vacation!" << endl;
			this->display(true);
			cout << " will be accompanied by ";
			for (int counter1 = 0; counter1 < size; counter1++)
			{
				arrPassengers[counter1].display(true);
				if (check > 1)
				{
					cout << ", ";
					check--;
				}
			}
			cout << "." << endl;
		}
		else		
		{
			this->display(true);
			cout << " will be accompanied by ";
			for (int counter2 = 0; counter2 < size; counter2++)
			{
				if (this->canTravelWith(arrPassengers[counter2]))
				{
					arrPassengers[counter2].display(true);
					if (check >= 2)
					{
						cout << ", ";
						check--;
					}
				}
			}	
			cout << "." << endl;
		}
	}
}

