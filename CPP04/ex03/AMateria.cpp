#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Unknown Type")
{
	// std::cout << _type << " AMateria CONSTRUCTOR" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << _type << " AMateria CONSTRUCTOR" << std::endl;
}

AMateria::AMateria(AMateria const &instance)
{
	*this = instance;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria DESTRUCTOR" << std::endl;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* shoots a materia at " << target.getName() << " *" << std::endl;
}

AMateria &	AMateria::operator=(AMateria const &rhs)
{
	if (this == &rhs)
		return (*this);
	_type = rhs._type;
	return (*this);
}

std::string	AMateria::getType()
{
	return (_type);
}