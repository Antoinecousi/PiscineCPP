#include "Character.hpp"

Character::Character(void) : _name("NoName"), _trash(NULL), _trash_count(0)
{
	std::cout << "Character " << _name << " CONSTRUCTOR" << std::endl;
}

Character::Character(std::string name) : _name(name), _trash(NULL), _trash_count(0)
{
	std::cout << "Character " << _name << " CONSTRUCTOR" << std::endl;
}

Character::Character(Character const &instance)
{
	*this = instance;
}

Character::~Character(void)
{
	std::cout << "Character DESTRUCTOR" << std::endl;
	for (int i = 0; i < _slot_count; i++)
		delete _slots[i];
	for (int i = 0; i < _trash_count; i++)
		delete _trash[i];
	delete *_trash;
}

Character &	Character::operator=(Character const &rhs)
{
	if (this == &rhs)
		return (*this);
	_slot_count = rhs._slot_count;
	for(int i = 0; i < 4; i++)
		*_slots[i] = *rhs._slots[i];
	_name = rhs._name;
	return (*this);
}

std::string const & Character::getName(void) const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (_slot_count == 4 && !m)
	{
		std::cout << _name << "'s inventory is full!" << std::endl;
		return;
	}
	puts("lol");
	_slots[_slot_count] = m->clone();
	puts("lol");
	_slot_count++;
}

void Character::unequip(int idx) 
{
	AMateria *tmp;
	AMateria **trash_;

	if (idx >= _slot_count || idx >= 4 || idx < 0)
	{
		std::cout << "This slot is already empty or index is invalid" << std::endl;
		return;
	}
	while(idx + 1 < _slot_count)
	{
		tmp = _slots[idx];
		_slots[idx] = _slots[idx + 1];
		_slots[idx + 1] = tmp;
		idx++;
	}
	trash_ = new AMateria*[_trash_count + 1];
	for(int i = 0; i < _trash_count; i++)
		trash_[i] = _trash[i]; 
	trash_[_trash_count] = _slots[idx];
	delete [] _trash;
	_trash = trash_;
	_trash_count++;

	_slots[idx] = NULL;
	_slot_count = idx;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < _slot_count)
		_slots[idx]->use(target);
	else
		std::cout << "The inventory's index required is unset..." << std::endl;
}