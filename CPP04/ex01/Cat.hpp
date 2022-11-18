#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		// Cat();
		Cat(Cat const &instance);
		Cat &operator=(Cat const &rhs);
		void	makeSound() const;
		~Cat(void);
		void insert_idea(int i, std::string str);
		Brain & get_idea(void);

	private:
		Brain* _Vocer;

};

#endif