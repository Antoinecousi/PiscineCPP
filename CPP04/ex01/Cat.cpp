#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "I don't like Cats :(" << std::endl;
}

Cat::Cat(Cat const &instance)
{
	
}

Cat::~Cat(void)
{
	std::cout << "miaou iaou mi .... aou ...... *dies*" << std::endl;
}

Cat &	Cat::operator=(Cat const &rhs)
{
	
}

void	Cat::makeSound() const
{
	std::cout << "MMMMMMMMMMiaou" << std::endl;
}