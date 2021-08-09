// TODO: add header guard
#ifndef CONTACT_H
#define CONTACT_H
namespace communication
{// TODO: add namespace here
	class Contact
	{
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
	public:
		// TODO: add the default constructor here
		Contact();
		// TODO: add the constructor with parameters here
		Contact(const char* name, long long* phoneNumber, int numberOfPhone);
		// TODO: add the destructor here
		~Contact();
		// TODO: add the display function here
		void display() const;
		// TODO: add the isEmpty function here
		bool isEmpty() const;
		int getCountryCode(long long phonenumber) const;
		int getAreaCode(long long phonenumber) const;
		int getNumberLeft(long long phonenumber) const;
		int getNumberRight(long long phonenumber) const;
		Contact(const Contact&);
		Contact& operator=(const Contact&);		
		void addPhoneNumber(long long phoneNumber);
	};
}
#endif