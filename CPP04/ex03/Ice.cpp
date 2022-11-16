#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Ice::Ice(std::string type) : AMateria(type)
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
	(void)rhs;
	return *this;
}

AMateria*	Ice::clone() const
{
	AMateria *real = new Ice(*this);
	return (real);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}