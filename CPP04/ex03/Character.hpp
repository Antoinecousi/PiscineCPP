#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		Character(Character const &instance);
		Character &operator=(Character const &rhs);
		~Character(void);
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		virtual std::string const & getName() const;

	private:
		AMateria	*_slots[4];
		AMateria	**_trash;
		int			_trash_count;
		std::string	_name;
		int			_slot_count;
};

#endif