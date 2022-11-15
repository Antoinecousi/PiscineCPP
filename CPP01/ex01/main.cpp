#include "Zombie.hpp"

#include <iostream>

int		main()
{
	Zombie *a = zombieHorde(16, "Georges");
	for (int i = 0; i < 16; i++)
	{
		
		a[i].announce();
	}
	delete []a;
}