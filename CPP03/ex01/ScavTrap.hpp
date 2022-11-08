# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &instance);
		ScavTrap &operator=(ScavTrap const &rhs);
		void	guardGate(void);
		~ScavTrap(void);
};