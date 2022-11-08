#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		// Dog();
		Dog(Dog const &instance);
		Dog &operator=(Dog const &rhs);
		~Dog(void);
		void	makeSound() const ;

	private:
		Brain* Vocer;
};

#endif