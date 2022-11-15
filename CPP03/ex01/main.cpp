#include "ScavTrap.hpp"

int main(void) 
{

	ClapTrap kiki;
	kiki.attack("kekette");
	kiki.takeDamage(100);
	kiki.beRepaired(90);

	ScavTrap aMojito;
	aMojito.attack("brindille");
	aMojito.takeDamage(100);
	aMojito.beRepaired(90);

	ScavTrap totita("Marc Antoine");
	totita.attack("Stephane le moine");
	totita.guardGate();
	totita.takeDamage(100);
	totita.beRepaired(90);
	return (0);
}