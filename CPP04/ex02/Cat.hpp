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
		virtual ~Cat(void);

	private:
		Brain* _Vocer;

};

#endif