#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

#include <string>
#include <iostream>

class Zombie {
	private :
		std::string m_zombieName;

	public :

		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	setZombieName( std::string name );
		void	announce ( void ) const;

};

Zombie*	zombieHorde( int N, std::string name );
Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif