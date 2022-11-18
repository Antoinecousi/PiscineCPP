#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat CONSTRUCTOR" << std::endl;
	_Vocer = new Brain;
}

Cat::Cat(Cat const &instance)
{
	*this = instance;
}

Cat::~Cat(void)
{
	std::cout << "Delete du chat" << std::endl;
	delete _Vocer;
}

Cat &	Cat::operator=(Cat const &rhs)
{
	if (this == &rhs)
		return (*this);
	_type = rhs._type;
	*_Vocer = *rhs._Vocer;
	return *this;
}	

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

void	Cat::insert_idea(int i, std::string str)
{
	_Vocer->insert_idea(i, str);
}

Brain &	Cat::get_idea()
{
	return *_Vocer;
}