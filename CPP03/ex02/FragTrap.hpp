# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &instance);
		FragTrap &operator=(FragTrap const &rhs);
		void	highFivesGuys(void);
		~FragTrap(void);
};