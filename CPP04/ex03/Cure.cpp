#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Cure::Cure(std::string type) : AMateria(type)
{
	// std::cout << "Cure \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Cure::Cure(Cure const &instance)
{
	*this = instance;
}

Cure::~Cure(void)
{
	// std::cout << "Cure DESTRUCTOR" << std::endl;
}

Cure &	Cure::operator=(Cure const &rhs)
{
	if (this == &rhs)
		return (*this);
	_type = rhs._type;
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	AMateria *cloning = new Cure(*this);
	// std::cout << "Je viens de cloner " << cloning->getType() << std::endl;
	return (cloning);
}


void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}