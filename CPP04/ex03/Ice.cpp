#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Ice::Ice(std::string type) : AMateria(type)
{
	// std::cout << "Ice \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Ice::Ice(Ice const &instance)
{
	*this = instance;
}

Ice::~Ice(void)
{
	// std::cout << "Ice \"" << _type << "\" DESTRUCOR" << std::endl;
}

Ice &	Ice::operator=(Ice const &rhs)
{
	if (this == &rhs)
		return (*this);
	_type = rhs._type;
	return (*this);
}

AMateria*	Ice::clone() const
{
	AMateria *cloning = new Ice(*this);
	// std::cout << "Je viens de cloner " << cloning->getType() << std::endl;
	return (cloning);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}