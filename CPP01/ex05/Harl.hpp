#ifndef HARL_HPP
# define HARL_HPP
#include <string>
#include <iostream>

class Harl
{
	typedef void	(Harl::*fct)(void);

	public:
		Harl(void);
		Harl(Harl const &instance);
		~Harl(void);

		void	complain( std::string level );

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

};

#endif