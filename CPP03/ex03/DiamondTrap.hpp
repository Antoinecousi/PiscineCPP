#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &instance);
		DiamondTrap &operator=(DiamondTrap const &rhs);
		void		whoAmi(void);
		using 		ScavTrap::attack;
		~DiamondTrap(void);

	private:
		std::string _name;

};

#endif