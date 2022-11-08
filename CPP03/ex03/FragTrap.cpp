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

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << _name << " attack " << target << ", causing " << _attackDamage << " points of damage" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << _name << " doesn't have the guts to attack." << std::endl;
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
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "*needily* : Can you give me high fives ?????" << std::endl;
}