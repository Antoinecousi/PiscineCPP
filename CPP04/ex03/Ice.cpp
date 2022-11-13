#include "Ice.hpp"

Ice::Ice(void) : _type("ice")
{
	std::cout << "Ice \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Ice::Ice(std::string type) : _type(type)
{
	std::cout << "Ice \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Ice::Ice(Ice const &instance)
{
	
}

Ice::~Ice(void)
{
	std::cout << "Ice \"" << _type << "\" DESTRUCOR" << std::endl;
}

Ice &	Ice::operator=(Ice const &rhs)
{
	
}

AMateria*	Ice::clone() const
{
	
}