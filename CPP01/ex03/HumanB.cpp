#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(0)
{

}

void	HumanB::attack() const
{
	std::cout << this->_name;
	if (!this->_weapon)
		std::cout << " doesn't have a weapon." << std::endl;
	else
		std::cout << " attacks with his " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
