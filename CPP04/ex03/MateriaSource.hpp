#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		// MateriaSource(** replace parameters **);
		MateriaSource(MateriaSource const &instance);
		MateriaSource &operator=(MateriaSource const &rhs);
		~MateriaSource();
		void learnMateria(AMateria*Matiere);
		AMateria* createMateria(std::string const & type);

	protected:
		AMatiera*	_stocked[4];
		int			count;
};

#endif