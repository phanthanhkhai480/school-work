//TODO: add header guards here
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: holiday namespace here

namespace holiday
{
	// TODO: declare the class Passenger here
	class	Passenger
	{
		char m_name[32];
		char m_destination[32];
		int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
	public:
		Passenger();
		void edit();
		Passenger(const char* name, const char* destination);
		bool isEmpty() const;
		bool canTravelWith(const Passenger& other) const;
		void display(bool onlyNames = false) const;
	};
	
	// TODO: add the class the attributes,
	//       the member function already provided,
	//       and the member functions that you must implement
}
#endif













































