#include <cstring>
#include<string>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict{
    
    
    //////////////////////////////////////////////////////
    //
    // Default Constructor
    // String::String(int capacity);
    //
    // initialize the string with an internal buffer capacity of 
    // "capacity." 
    // default capacity is 1 (minimum needed for an empty string)
    //
    // 
    String::String(int capacity)
	{
		this->m_pString = new char[capacity];
		this->m_pString[0] = '\0';
		this->m_capacity = capacity;
    }

    //////////////////////////////////////////////////////
    //
    // String::String(const char* p, int capacity);
    //
    // Construct a String from a char array
    // Should initialize the internal buffer to at least 
    // the length of the string need to hold pSource, 
    // or capacity, whichever is greater.
    //
    // 
    String::String(const char* pSource, int capacity)
	{
		int len = strlen(pSource);
		if (capacity > (len + 1))
		{
			this->m_pString = new char[capacity];
			this->m_capacity = capacity;
		}
		else
		{
			this->m_capacity = (len + 1);
			this->m_pString = new char[this->m_capacity];
		}
		strcpy(this->m_pString, pSource);
    }

    //////////////////////////////////////////////////////
    //
    // String::String(const String &s, int capacity);
    //
    // Copy constructor
    //
    // Construct a String from another String
    //
    // 
	String::String(const String& other, int capacity)
	{
		this->m_pString = new char[capacity];
		strcpy(this->m_pString, other);
	}
    
    //////////////////////////////////////////////////////
    //
    // String::resize(int newsize)
    //
    // resize the internal buffer to the value given
    // do NOT shrink the string buffer smaller than 
    // that needed to hold the existing string!
    // (length + 1);
    //    
	void String::resize(int newsize) 
	{
		if ((newsize < length() + 1) == false 
			&& (newsize != this->m_capacity))
		{
			char* temp = nullptr;
			temp = new char[newsize];
			strcpy(temp, this->m_pString);
			delete[] this->m_pString;
			this->m_capacity = newsize;
			this->m_pString = new char[this->m_capacity];
			strcpy(this->m_pString, temp);
		}
	}
                                    
  
    //////////////////////////////////////////////////////
    //
    // String::operator=(const String& other)
    // 
    // Assignment operator
    // copy string "other" to this object
    //   
    // 
    String& String::operator=(const String& other)
    {
		resize(other.length() + 1);
		strcpy(this->m_pString, other.m_pString);
		return *this;
    }


    //////////////////////////////////////////////////////
    //
    // String::~String
    // 
    // destructor
    // 
    // clean up the internal string buffer  
    // 
    String::~String()
    {
		delete[] this->m_pString;
    }

    //////////////////////////////////////////////////////
    //
    // String::length()
    // 
    // return the length of the string
    // 
    // 
    int String::length() const
    {
		return strlen(this->m_pString);
    }


    //////////////////////////////////////////////////////
    //
    // String::operator const char*() const
    // 
    // convert the String to a char*
    // 
    // 
    String::operator const char *() const
    {
		return (const char*)this->m_pString;
    }


    //////////////////////////////////////////////////////
    //
    // String::empty()
    // 
    // 
    // returns true if the string is empty
    // i.e. either the first char is \0, or 
    // length is 0.
    bool String::empty() const
    {
		if (length() == 0)
			return true;
		return false;
    }
    
    //////////////////////////////////////////////////////
    //
    // String::operator bool()
    // 
    // same as empty(), just wrapped in an operator
    // 
    //     
    String::operator bool() const
    {
		if (length() == 0)
			return false;
		return true;
    }
     
     
    //////////////////////////////////////////////////////
    //
    // String::operator==(const String& s2) const
    // 
    // returns true if *this == s2.
    // You can use the strcmp function to check if 
    // two strings are equal, or write your own
    // treating the string as a char-array
    //      
	bool String::operator==(const String& s2) const
	{
		if (strcmp(*this, s2) == 0)
			return true;
		return false;
	}
    
    
    //////////////////////////////////////////////////////
    //
    // String::operator+=(const String& s2)
    // 
    // Concatenates s2 to the end of *this
    //
    // implements *this = (*this + s2)
    // return *this
    // 
    // 
	String& String::operator+=(const String& s2)
	{
		int len = strlen(this->m_pString) + strlen(s2.m_pString) + 2;
		resize(len);
		strcat(this->m_pString, s2.m_pString);
		return *this;
	}
    
    
    
    //////////////////////////////////////////////////////
    //
    // String::operator+(const String& s2) const
    // 
    // implements the operator (*this + s2)
    // returns the expression
    // DOES NOT MODIFY *this
    // 
    // 
	String String::operator+(const String& s2) const
	{
		int len = strlen(this->m_pString) + strlen(s2.m_pString) + 2;
		char* str;
		str = new char[len];
		strcpy(str, this->m_pString);
		strcat(str, s2.m_pString);
		str[len] = '\0';
		return str;
	}
    
    //////////////////////////////////////////////////////
    //
    // String::operator+=(char c)
    // 
    // Adds a single char c to the end of the string in *this
    // Grows the string buffer if necessary.
    //  
	String& String::operator+= (char c)
	{
		resize(strlen(this->m_pString) + 2);
		strncat(this->m_pString, &c, 1);
		return *this;
	}
    

    
    //////////////////////////////////////////////////////
    //
    // String::substr
    // 
    // Returns a substring of the current string. In case of error
    // return an empty String() object instead.
    // 
    // return the string slice starting at index, at most len characters
    // 
    // both index and len have to lie inside the string. If they do not, then 
    // that is an error
    // 
    String String::substr(int index, int len) const{
		char* temp;
		temp = new char[len + 1];
		int tempIndex = 0;
		if (index < len && index > 0 && len < length() + 1){
			for (int counter = index; counter <= len; counter++){
				temp[tempIndex] = this->m_pString[counter];
				tempIndex++;
			}				
		}
		else
			temp = nullptr;
		return temp;
    }

    //////////////////////////////////////////////////////
    //
    // operator<<
    // 
    // Print the string to the output stream
    // 
    // clean up the internal string buffer  
    // 
	std::ostream& operator<<(std::ostream& ostream, const String &s)
	{
		ostream << (const char*)s;
		return ostream;
	}

    //////////////////////////////////////////////////////
    //
    // operator>>
    // 
    // Input a string from an input stream into the String s
    // 
    // Note: the input can be ANY length in character. You will need to 
    // read it one char at a time. 
    // 
    std::istream& operator>>(std::istream& istream, String &s)
    {
        s = "";
        char tempC = 0;
        do
        {
            tempC = istream.get();
            if (tempC != '\n')
            {
                s += tempC;
            }
            else
                break;
        } while(1);
        return istream;
    }

  
}