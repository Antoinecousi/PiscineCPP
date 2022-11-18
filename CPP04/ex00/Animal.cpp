#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal \"" << _type << " \" CONSTRUCTOR" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal \"" << _type << " \" CONSTRUCTOR" << std::endl;
}

Animal::Animal(Animal const &instance)
{
	*this = instance;
}

Animal::~Animal(void)
{
	std::cout << "Animal \"" << _type << " \" DESTRUCTOR" << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "  *????* *????* *????* *????* *????*   " << std::endl;
}

Animal &	Animal::operator=(Animal const &cp_target)
{
	this->_type = cp_target._type;
	return *this;
}