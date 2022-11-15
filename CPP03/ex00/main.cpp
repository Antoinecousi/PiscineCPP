#include "ClapTrap.hpp"

int main(void) 
{

	ClapTrap	Mary;

	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.attack("kekette");
	Mary.beRepaired(90);

	ClapTrap	John("John");
	John.attack("Patrick");
	John.attack("Patrick");
	John.attack("Patrick");
	John.takeDamage(9);
	John.attack("Patrick");
	John.beRepaired(19);
	John.attack("Patrick");
	John.takeDamage(9);
	John.attack("Patrick");
	John.takeDamage(9);
	John.attack("Patrick");
	John.takeDamage(9);
	John.attack("Patrick");
	John.beRepaired(14);

	return (0);
}