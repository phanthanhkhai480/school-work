#ifndef SICT_Fraction_H__
#define SICT_Fraction_H__

#include <iostream>

using namespace std;

namespace sict
{
class Fraction
{
private:
	int num;			    // Numerator
	int denom;			  // Denominator
	int gcd();			  // returns the greatest common divisor of num and denom
	int max();        // returns the maximum of num and denom
	int min();        // returns the minimum of num and denom
public:
	void reduce();     // simplifies a Fraction number by dividing the 
                           // numerator and denominator to their greatest common divisor 
	Fraction();                             // default constructor
	Fraction(int n , int d=1); 		         // construct n/d as a Fraction number
	void display() const;    
	bool isEmpty() const;     

	// member operator functions

	// TODO: write the prototype of member operator+= function HERE
	Fraction operator+=(Fraction other);
	// TODO: write the prototype of member operator+ function HERE
	Fraction operator+(Fraction) const;
	// TODO: write the prototype of member operator* function HERE
	Fraction operator*(Fraction&);
	 friend bool operator != (Fraction& f1, Fraction& f2);
	friend bool operator == (Fraction& f1, Fraction& f2);
	explicit operator double() { return 1.0*num/denom; }
	//explicit operator int() { return 1 * num / denom; }
	Fraction operator*(int x);
	operator int() { return( num / denom); }
	friend ostream& operator<<(ostream& os, Fraction &f1);

};
}
#endif
