#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &instance);
		Animal &operator=(Animal const &cp_target);
		~Animal(void);

		std::string getType() const;
		virtual void	makeSound() const;

	protected:
		std::string _type;
};

#endif