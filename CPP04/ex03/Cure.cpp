#include "Cure.hpp"

Cure::Cure(void) : _type("cure")
{
	std::cout << "Cure \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Cure::Cure(std::string type) : _type(type)
{
	std::cout << "Cure \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Cure::Cure(Cure const &instance)
{
	
}

Cure::~Cure(void)
{
	std::cout << "Cure DESTRUCTOR" << std::endl;
}

Cure &	Cure::operator=(Cure const &rhs)
{
	
}

AMateria*	Cure::clone(void) const
{
	
}
