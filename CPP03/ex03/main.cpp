#include "DiamondTrap.hpp"

int main(void) 
{

	ClapTrap Kiki;
	Kiki.attack("kekette");
	Kiki.takeDamage(100);
	Kiki.beRepaired(90);

	ScavTrap Totita("Marc Antoine");
	Totita.attack("Stephane le moine");
	Totita.guardGate();
	Totita.takeDamage(100);
	Totita.beRepaired(90);

	FragTrap Francoise("Francoise");
	Francoise.attack("Ambroise");
	Francoise.highFivesGuys();
	Francoise.takeDamage(100);
	Francoise.beRepaired(90);

	DiamondTrap Mondanite("Mondanite");
	Mondanite.highFivesGuys();
	Mondanite.guardGate();
	Mondanite.whoAmi();
	Mondanite.attack("Ambroise");
	Mondanite.takeDamage(100);
	Mondanite.beRepaired(90);
	
	return (0);
}