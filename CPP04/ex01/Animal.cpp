#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "An unknown animal as appeared" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "A " << type << " as appeared. ";
}

Animal::Animal(Animal const &instance)
{
	
}

Animal::~Animal(void)
{
	std::cout << "Delete de l'Animal" << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "*????* *????* *????* *????* *????* *????* *????*" << std::endl;
}

Animal &	Animal::operator=(Animal const &cp_target)
{
	this->_type = cp_target._type;
	return *this;
}