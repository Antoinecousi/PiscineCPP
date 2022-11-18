#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "wrong Animal is created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string	 type) : _type(type)
{
		std::cout << "A WrongAnimal is created, its a " << type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &instance)
{
	*this = instance;
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