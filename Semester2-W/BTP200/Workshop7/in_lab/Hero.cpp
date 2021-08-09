#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;


//////////////////////////////////////////////
// Default constructor
//
Hero::Hero ()
{
	m_health = 0;
	m_maximumHealth = 0;
	m_name[0] = '\0';
	m_attack = 0;
}

// Constructor 
Hero::Hero (const char name[], unsigned maximumHealth, unsigned attack)
{
	m_attack = unsigned(attack);
	m_maximumHealth = unsigned(maximumHealth);
	strcpy(m_name, name);
	m_health = unsigned(maximumHealth);
}

// Hero::display function
void Hero::display (ostream & out) const 
{
	if (m_name[0] != '\0')
		out << m_name;
}

// return true if the Hero object is uninitialized
bool Hero::isEmpty () const 
{
	if (m_attack == 0 && m_maximumHealth == 0 && m_health == 0 && m_name[0] == '\0')
	{
		return true;
	}
	return false;
}

// sets the Hero object's health back to full
void Hero::respawn() 
{
	m_health = m_maximumHealth;
}




