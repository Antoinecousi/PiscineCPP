#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string p_name);
		~Weapon(void);
		std::string const &getType() const ;
		void		setType(std::string p_name);

	private:
		std::string _type;
};

#endif