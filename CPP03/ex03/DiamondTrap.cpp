#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), _name("default")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::setAtk();

	std::cout << "A DiamondTrap named " << _name << " as appeared." << std::endl;
	std::cout << "Hit Points : " << _hitPoints << std::endl;
	std::cout << "Energy Points : " << _energyPoints << std::endl;
	std::cout << "Attack Damage : " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::setAtk();

	std::cout << "A DiamondTrap named " << _name << " as appeared." << std::endl;
	std::cout << "Hit Points : " << _hitPoints << std::endl;
	std::cout << "Energy Points : " << _energyPoints << std::endl;
	std::cout << "Attack Damage : " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &instance)
{
	*this = instance;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "A DiamondTrap has died." << std::endl;
}

void	DiamondTrap::whoAmi(void)
{
	std::cout << "DiamondTrap is :" << _name << " and also " << ClapTrap::_name << " it's the ClapTrap name" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if ( this != &rhs )
	{
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}
