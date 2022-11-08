#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "I like dogs :)" << std::endl;
}

// Dog::Dog()
// {
	
// }

Dog::Dog(Dog const &instance)
{
	
}

Dog::~Dog(void)
{
	std::cout << "KAI KAI KAI *dies*" << std::endl;
}

Dog &	Dog::operator=(Dog const &rhs)
{
	
}

void	Dog::makeSound() const
{
	std::cout << "Wouf wouf" << std::endl;
}