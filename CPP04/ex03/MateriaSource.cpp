#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _count(0)
{
	// std::cout << "MateriaSource CONSTRUCTOR" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &instance)
{
	
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource DESTRUCTOR" << std::endl;
	for (int i = 0; i < this->_count; i++)
		delete _stocked[i];
}

MateriaSource &	MateriaSource::operator=(MateriaSource const &rhs)
{
	(void)rhs;
	return *this;
}

void	MateriaSource::learnMateria(AMateria*Matiere)
{
	if (_count > 3)
	{
		std::cout << "This source cannot learn more Materia" << std::endl;
		delete Matiere;
	}
	else
	{
		this->_stocked[_count] = Matiere;
		// std::cout << "Formule de la matiere " << this->_stocked[_count]->getType() << " learned at index " << _count << std::endl;
		_count++;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria *tmp;
	AMateria *newMateria;

	for(int i = _count - 1; i >= 0; i--)
	{
		if (_stocked[i]->getType() == type)
		{
			for (int e = i; e < _count; e++)
			{
				if (e + 1 < _count)
				{
					tmp = _stocked[e];
					_stocked[e] = _stocked[e + 1];
					_stocked[e + 1] = tmp; 
				}
			}
			tmp = _stocked[_count - 1];
			newMateria = tmp->clone();
			delete tmp;
			_count--;
			// std::cout << newMateria->getType() << " is created at stocked number " << _count << std::endl;
			return newMateria;
		}
	}
	// std::cout << type << " isn't a Materia." << std::endl;
	return (NULL);
}