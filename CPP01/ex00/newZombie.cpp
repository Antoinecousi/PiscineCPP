#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
	Zombie *grrr;
	grrr = new Zombie(name);
	return (grrr);
}