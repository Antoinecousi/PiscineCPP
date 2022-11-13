#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "I like dogs :)" << std::endl;
	_Vocer = new Brain;
}

// Dog::Dog()
// {
	
// }

Dog::Dog(Dog const &instance)
{
	*this = instance;
}

Dog::~Dog(void)
{
	std::cout << "Delete du chien" << std::endl;
	delete _Vocer;
}

Dog &	Dog::operator=(Dog const &rhs)
{
	if (this == &rhs)
		return (*this);
	_type = rhs._type;
	*_Vocer = *rhs._Vocer;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Wouf wouf" << std::endl;
}

void	Dog::insert_idea(int i, std::string str)
{
	_Vocer->insert_idea(i, str);
}

Brain &	Dog::get_idea()
{
	return *_Vocer;
}