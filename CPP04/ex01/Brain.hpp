#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>
#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain();
		Brain(Brain const &instance);
		Brain &operator=(Brain const &rhs);
		~Brain(void);

	private:
		std::string ideas[100];
};

#endif