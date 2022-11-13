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
		std::string &operator[](int);
		virtual ~Dog(void);
		void	makeSound() const ;
		void insert_idea(int i, std::string str);
		Brain & get_idea(void);

	private:
		Brain* _Vocer;
};

#endif