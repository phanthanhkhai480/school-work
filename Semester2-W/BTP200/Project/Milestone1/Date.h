// compilation safegaurds
#ifndef ICT_DATE_H_
#define ICT_DATE_H_
#include <iostream>
// ict namespace 
namespace ict {
   // Date defined Error values
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
#define HOUR_ERROR 5
#define MIN_ERROR 6

   class Date {
   private:
      // member variables
	   int m_year;
	   int m_mon;
	   int m_day;
	   int m_hour;
	   int m_min;
	   int m_readErrorCode;
	   bool m_dateOnly;

     // private methods
      int value()const;
	  void errCode(int errorCode);
	  void set(int year, int month, int day, int hour, int min);
	
   public:
      // constructors
	   Date();
	   Date(int, int, int);
	   Date(int , int , int , int , int = 0);
	   void set();
      // operator ovrloads
	   bool operator==(const Date& D)const;
	   bool operator!=(const Date& D)const;
	   bool operator<(const Date& D)const;
	   bool operator>(const Date& D)const;
	   bool operator<=(const Date& D)const;
	   bool operator>=(const Date& D)const;

	  // methods
	   int errCode() const;			//Returns the m_readErrorCode value.
	   bool bad() const;			//Returns true if m_readErrorCode is not equal to zero. 
	   bool dateOnly() const;		//Returns the m_dateOnly attribute.
	   void dateOnly(bool value);	//Sets the m_dateOnly attribute to the �value� argument. Also if the �value� is true, then it will set m_hour and m_min to zero.
       int mdays() const;

      // istream  and ostream read and write methods
	  std::istream& read(std::istream& is = std::cin);
	  std::ostream& write(std::ostream& ostr = std::cout)const;

   };
   // operator<< and >> overload prototypes for cout and cin
   std::ostream &operator << (std::ostream &os, const Date& other);
   
   std::istream &operator >> (std::istream &is, Date& other);
   
}

#endif