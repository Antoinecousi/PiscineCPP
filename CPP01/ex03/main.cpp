#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon	club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	Weapon	club2 = Weapon("axe");
	HumanB jim("Jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("Bob le dinosaure");
	jim.attack();
	
	return 0;
}