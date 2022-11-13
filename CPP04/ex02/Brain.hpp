#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>
#include <iostream>

class Brain
{
	public:
		Brain(void);
		// Brain();
		Brain(Brain const &instance);
		Brain &operator=(Brain const &rhs);
		virtual ~Brain(void);
		std::string	& operator[](int);
		void	insert_idea(int i, std::string str);
		 std::string	get_idea();

	private:
		std::string ideas[100];
};

#endif