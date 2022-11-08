#include "Zombie.hpp"
#include <sstream>

Zombie*	zombieHorde( int N, std::string name ){
	Zombie	*z = new Zombie[N];
	name += "_";
	std::string copy = name;

	for (int i = 0; i < N; i++)
	{
		z[i].setZombieName(name += std::to_string(i + 1));
		z[i].announce();
		name = copy;
	}
	return z;
}