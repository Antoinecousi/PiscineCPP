#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal \"" << _type << " \" CONSTRUCTOR" << std::endl;
}

WrongAnimal::WrongAnimal(std::string	 type) : _type(type)
{
	std::cout << "WrongAnimal \"" << _type << " \" CONSTRUCTOR" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &instance)
{
	std::cout << "WrongAnimal \"" << _type << " \" DESTRUCTOR" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal deleted..." << std::endl;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*????* *????* *????* *????* *????* *????* *????* *????* *????* *????* " << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}