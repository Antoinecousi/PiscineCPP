#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog \"" << _type << " \" CONSTRUCTOR" << std::endl;
}

Dog::Dog(Dog const &instance)
{
	*this = instance;
}

Dog::~Dog(void)
{
	std::cout << "Dog \"" << _type << " \" DESTRUCTOR" << std::endl;
}

Dog &	Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf wouf" << std::endl;
}