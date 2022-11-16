#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure \"" << _type << "\" CONSTRUCTOR" << std::endl;
}

Cure::Cure(std::string type) : AMateria(type)
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
	(void) rhs;
	return *this;
}

AMateria*	Cure::clone(void) const
{
	AMateria *real = new Cure(*this);
	return (real);
}


void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}