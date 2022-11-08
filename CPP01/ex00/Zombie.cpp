#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie (){
	std::cout << "A new zombie has raised from the ground. He's shouting : AGROU AGROU!!!" << std::endl;
}

Zombie::Zombie (std::string name) : m_zombieName(name) {
	std::cout << m_zombieName << " has raised from the ground. He's shouting : AGROU AGROU!!!" << std::endl ;
}

Zombie::~Zombie ( void ){
	std::cout << m_zombieName << " died    :'(" << std::endl ;
}

void	Zombie::announce(void) const {
	std::cout << this->m_zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}