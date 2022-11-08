#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << _name << " is now a ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << _name << " is now a ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &instance)
{
	*this = instance;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const &rhs)
{
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	_name = rhs._name;
	std::cout << "ScavTrap overload operator constructor" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap entered \"gate keeper mod\"" << std::endl;
}