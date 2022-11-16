#ifndef CURE_HPP
# define CURE_HPP
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(std::string type);
		Cure(Cure const &instance);
		Cure &operator=(Cure const &rhs);
		~Cure(void);
		void	use(ICharacter& target);
		AMateria* clone(void) const;

	private:
		std::string	_type;
};

#endif