#include "Brain.hpp"

Brain::Brain(void)
{
}

{
	*this = instance;
}

Brain::~Brain(void)
{
	
}

Brain &	Brain::operator=(Brain const &rhs)
{
	if (this == &rhs)
		return (*this);
	for(int i = 0; i < 100; i++)
		ideas[i] = rhs.ideas[i];
	return (*this);	
}

std::string & Brain::operator[](int i) 
{
	return ideas[i];
}

void	Brain::insert_idea(int i, std::string str)
{
	if (i < 0 || i > 99)	
	{
		std::cout << "'i' should be in between 0 and 99. try again \n";
		return;
	}
	else
		ideas[i] = str;
}

std::string	Brain::get_idea()
{
	return *ideas;
}