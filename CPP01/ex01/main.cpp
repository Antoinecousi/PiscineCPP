#include "Zombie.hpp"

#include <iostream>

int		main()
{
	Zombie *a = zombieHorde(16, "Georges");
	delete []a;
}