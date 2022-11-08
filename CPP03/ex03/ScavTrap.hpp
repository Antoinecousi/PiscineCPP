# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &instance);
		ScavTrap &operator=(ScavTrap const &rhs);
		void	guardGate(void);
		void	attack(const std::string& target);
		~ScavTrap(void);
};