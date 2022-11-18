#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat \"" << _type << " \" CONSTRUCTOR" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat \"" << _type << " \" DESTRUCTOR " << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaouuuuuu" << std::endl;
}

WrongCat::WrongCat(WrongCat const &instance)
{
	*this = instance;
}