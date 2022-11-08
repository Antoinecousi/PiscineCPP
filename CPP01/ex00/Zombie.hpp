#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

#include <string>

class Zombie {
	private :
		std::string m_zombieName;

	public :

		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce ( void ) const;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif