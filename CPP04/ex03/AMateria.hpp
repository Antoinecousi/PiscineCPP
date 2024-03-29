#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <string>
#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		AMateria(AMateria const &instance);
		AMateria &operator=(AMateria const &rhs);
		~AMateria(void);
		std::string	getType();

	protected:
		std::string _type;
};

#endif