#ifndef ICE_HPP
# define ICE_HPP
#include "AMateria.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(std::string type);
		Ice(Ice const &instance);
		Ice &operator=(Ice const &rhs);
		virtual AMateria* clone() const;
		void	use(ICharacter& target);
		~Ice(void);

};

#endif