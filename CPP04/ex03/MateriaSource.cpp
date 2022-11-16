#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _count(0)
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
		std::cout << "Matiere posee au count " << _count << std::endl;
		std::cout << this->_stocked[_count]->getType() << std::endl;
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
			return newMateria;
		}
	}
	std::cout << type << " isn't a Materia." << std::endl;
	return (NULL);
}