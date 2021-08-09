#include <iostream>
#include <cstring>


#include "SuperHero.h"


SuperHero::SuperHero() : Hero()
{
	m_superPowerAttack = 0;
	m_superPowerDefend = 0;
}
        
        
SuperHero::SuperHero( const char* name, unsigned maximumHealth, unsigned attack,
                unsigned superPowerAttack, unsigned superPowerDefend
        )  : Hero(name, maximumHealth, attack)
{ 
	Hero(name, maximumHealth, attack);
	this->m_superPowerAttack = unsigned(superPowerAttack);
	this->m_superPowerDefend = unsigned(superPowerDefend);	
}

unsigned SuperHero::getAttack() const
{
	return m_superPowerAttack; 
}


