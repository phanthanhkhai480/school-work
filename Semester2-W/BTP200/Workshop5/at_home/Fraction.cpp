#include <iostream>
#include "Fraction.h"

using namespace std;

namespace sict
{
Fraction::Fraction()
{
	denom =-1;              // safe empty state
}
Fraction::Fraction(int n, int d) // n: numerator, d: denominator
{ 
	if(n >= 0 && d > 0)
	{
		num = n;
		denom = d;
		reduce();
	}
	else
		denom =-1;              // set to safe empty state
}
int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
{
	int mn = min();                                        // min of num and denom
	int mx = max();                                        // mX of num and denom

	for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
		if( mx % x == 0 && mn % x == 0)
			return x;
	return 1;
}

void Fraction::reduce()                                         // simplify the Fraction number  
{
	int tmp = gcd();
	num /= tmp;
	denom /= tmp;
}

int Fraction::max ()
{
	return (num >= denom) ? num : denom; 
}

int Fraction::min()
{
	return (num >= denom) ? denom : num; 
}

// in_lab

// TODO: write the implementation of display function HERE
void Fraction::display() const
{
	if (this->denom <= 0)
	{
		cout << "Invalid Fraction Object!";
	}
	else if (denom == 1)
		cout << this->num;
	else
		cout << this->num << "/" << this->denom;
}

// TODO: write the implementation of isEmpty function HERE
bool Fraction::isEmpty() const
{
	if (denom <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// TODO: write the implementation of member operator+= function HERE
Fraction Fraction::operator+=(Fraction other)
{
	//B += E
	// B ---> this
	// E ---> other
	int check = this->isEmpty();
	int check1 = other.isEmpty();
	if (check == 0 || check1 == 0)
	{
		this->num = (this->num)*(other.denom) + (this->denom)*(other.num);
		this->denom = (this->denom)*(other.denom);
		reduce();
	}
	return *this;
}

// TODO: write the implementation of member operator+ function HERE
Fraction Fraction::operator+(Fraction other) const
{
	//B += E
	// B ---> this
	// E ---> other
	Fraction another(-1);
	bool check = this->isEmpty();
	bool check1 = other.isEmpty();
	if (check == false && check1 == false)
	{
		another.num = (this->num)*(other.denom) + (this->denom)*(other.num);
		another.denom = (this->denom)*(other.denom);
		another.reduce();
	}

	return another;
}
Fraction Fraction::operator*(int x) {
	int numtmp, denomtmp;
	numtmp = this->num*x;
	denomtmp = this->denom;
	return Fraction(numtmp,denomtmp);
}
// TODO: write the implementation of member operator* function HERE
Fraction Fraction::operator*(Fraction& other)
{
	//B += E
	// B ---> this
	// E ---> other
	Fraction t;

	int check = this->isEmpty();
	int check1 = other.isEmpty();
	if (check == 0 && check1 == 0)
	{
		t.num = (this->num)*(other.num);
		t.denom = (this->denom)*(other.denom);
		t.reduce();
	}
	return t;
}

bool operator!=(Fraction& f1, Fraction& f2)
{
	f1.num = f1.num*f2.denom;
	f1.denom = f1.denom*f2.denom;
	f2.num = f2.num*f1.denom;
	f2.denom = f1.denom*f2.denom;
	if ((f1.num != f2.num) || (f1.denom != f2.denom))
		return true;
	else
		return false;
}

bool operator == (Fraction& f1 , Fraction& f2)
{
	
	f1.num = f1.num*f2.denom;
	f1.denom = f1.denom*f2.denom;
	f2.num = f2.num*f1.denom;
	f2.denom = f1.denom*f2.denom;
	if ((f1.num == f2.num) && (f1.denom == f2.denom))
	{
		return 1;
	}
	else
		return 0;
}
ostream& operator << (ostream& os, Fraction &f1){
	if (f1.denom <= 0)
	{
		cout << "Invalid Fraction Object!";
	}
	else if (f1.denom == 1)
		cout << f1.num;
	else
		cout << f1.num << "/" << f1.denom;
	return os;
}
}