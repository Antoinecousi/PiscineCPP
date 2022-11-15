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
	Zombie a("Steve Jobs");
	a.announce();
	delete(c);
	std::cout << "Steve & Arnold are on the stack, they'll die at the end of the main scope" << std::endl;
}