#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string p_name);
		~Weapon(void);
		const		std::string &getType();
		void		setType(std::string p_name);

	private:
		std::string _type;
};

#endif