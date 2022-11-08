#include "Zombie.hpp"

#include <iostream>

int		main()
{
	Zombie b("Arnold");
	Zombie *c;
	c = newZombie("Shwarzenegger");

	randomChump("Le chien");
	b.announce();
	c->announce();
	delete(c);
	Zombie a("Steve Jobs");
	std::cout << "Steve & Arnold are on the stack, they'll die at the end of the main scope" << std::endl;
	a.announce();
}