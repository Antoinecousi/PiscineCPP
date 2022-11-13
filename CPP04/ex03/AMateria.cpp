#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria CONSTRUCTOR" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	
}

AMateria::AMateria(AMateria const &instance)
{
	
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria DESTRUCTOR" << std::endl;
}

void	AMateria::use(ICharacter& target)
{
	
}

AMateria &	AMateria::operator=(AMateria const &rhs)
{
	
}