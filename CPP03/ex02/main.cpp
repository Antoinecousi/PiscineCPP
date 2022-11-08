#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) 
{

	ClapTrap kiki;
	kiki.attack("kekette");
	kiki.takeDamage(100);
	kiki.beRepaired(90);

	ScavTrap totita("Marc Antoine");
	totita.attack("Stephane le moine");
	totita.takeDamage(100);
	totita.beRepaired(90);

	FragTrap Francoise("Francoise");
	totita.attack("Ambroise");
	totita.takeDamage(100);
	totita.beRepaired(90);
	
	return (0);
}