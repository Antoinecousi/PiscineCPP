#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : count(0)
{
	std::cout << "MateriaSource CONSTRUCTOR" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &instance)
{
	
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource DESTRUCTOR" << std::endl;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const &rhs)
{
	
}

void	MateriaSource::learnMateria(AMateria*Matiere)
{
	if (count > 3)	
	{
		std::cout << "This source cannot learn more Materia" << std::endl;
		delete Matiere;
	}
	else
	{
		this->_stocked[count] = Matiere;
		count++;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria *tmp;
	AMateria *newMateria;

	for(int i = count - 1; i >= 0; i--)
	{
		if (_stocked[i]->getType() == type)
		{
			for (int e = i; e < count; e++)
			{
				if (e + 1 < count)
				{
					tmp = _stocked[e];
					_stocked[e] = _stocked[e + 1];
					_stocked[e + 1] = tmp; 
				}
			}
			tmp = _stocked[count - 1];
			newMateria = tmp->clone();
			delete tmp;
			count--;
			return newMateria;
		}
	}
}