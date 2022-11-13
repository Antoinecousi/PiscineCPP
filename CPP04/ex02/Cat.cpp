#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "I don't like Cats :(" << std::endl;
	_Vocer = new Brain;
}

Cat::Cat(Cat const &instance)
{
	
}

Cat::~Cat(void)
{
	std::cout << "Delete du chat" << std::endl;
	delete _Vocer;
}

Cat &	Cat::operator=(Cat const &rhs)
{
	
}

void	Cat::makeSound() const
{
	std::cout << "MMMMMMMMMMiaou" << std::endl;
}