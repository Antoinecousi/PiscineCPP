#include "Weapon.hpp"

Weapon::Weapon(std::string p_name)
{
	this->_type = p_name;
}

Weapon::~Weapon(void)
{
	
}

const std::string &	Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string p_name)
{
	this->_type = p_name;
}
