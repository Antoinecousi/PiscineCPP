#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &instance);
		WrongCat &operator=(WrongCat const &rhs);
		~WrongCat(void);
		void	makeSound() const;

	private:

};

#endif