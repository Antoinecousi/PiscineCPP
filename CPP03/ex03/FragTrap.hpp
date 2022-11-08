# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &instance);
		FragTrap &operator=(FragTrap const &rhs);
		void	highFivesGuys(void);
		void	attack(const std::string &target);
		~FragTrap(void);
};