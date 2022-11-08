#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	public:
		HumanA(std::string name, Weapon weapon);
		void	attack();

	private:
		Weapon		_weapon;
		std::string	_name;
};

#endif