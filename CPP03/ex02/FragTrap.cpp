#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << _name << " is now a FragTrap!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << _name << " is now a FragTrap!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &instance)
{
	*this = instance;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const &rhs)
{
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	_name = rhs._name;
	std::cout << "FragTrap overload operator constructor" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "*needily* : Can you give me high fives ?????" << std::endl;
}