#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "I don't like WrongCats :(" << std::endl;
}


WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat deleted..." << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const &rhs)
{
	
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaouuuuuu" << std::endl;
}