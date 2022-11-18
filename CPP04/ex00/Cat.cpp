#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat \"" << _type << " \" CONSTRUCTOR" << std::endl;
}

Cat::Cat(Cat const &instance)
{
	*this = instance;
}

Cat::~Cat(void)
{
	std::cout << "Animal \"" << _type << " \" DESTRUCTOR" << std::endl;
}

Cat &	Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}