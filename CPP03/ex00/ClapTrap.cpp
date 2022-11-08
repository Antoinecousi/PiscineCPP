#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _attackDamage(0), _energyPoints(10), _hitPoints(10)
{
	std::cout << "A ClapTrap named " << _name << " has APPEARED" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _attackDamage(0), _energyPoints(10), _hitPoints(10)
{
	std::cout << "A ClapTrap named " << _name << " has APPEARED" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &instance)
{
	*this = instance;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << _name << " has DISAPPEARED" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const &rhs)
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage !" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap" << _name << " doesn't have the guts to attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " take " << amount << " damage !" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ( _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " regenerate " << amount << " hit points !" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
	}
	else
		std::cout << "ClapTrap" << _name << " doesn't have enough energy to heal himself." << std::endl;
}