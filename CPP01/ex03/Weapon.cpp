#include "Weapon.hpp"

Weapon::Weapon()
{
	this->_type = "random attack club";
	return ; 
}

Weapon::Weapon(std::string p_name)
{
	this->_type = p_name;
}


std::string const &	Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(std::string p_name)
{
	this->_type = p_name;
}


Weapon::~Weapon(void)
{
	
}