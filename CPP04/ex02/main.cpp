#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	int		i = 0;

	const Animal* j[10];
	while (i < 5)
		j[i++] = new Dog;
	while (i < 10)
		j[i++] = new Cat;
	i = 0;

	std::cout << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
		j[i]->makeSound();

	Dog *a = new Dog();
	Dog *b = new Dog();
	Cat *c = new Cat();
	Cat *d = new Cat();

	std::string str = "coucou";
	a->insert_idea(2, str);
	*b = *a;
	c->insert_idea(2, str);
	*d = *c;
	std::cout << &a->get_idea() << "      " << a->get_idea()[2] << std::endl;
	std::cout << &b->get_idea() << "      " << b->get_idea()[2] << std::endl;
	std::cout << &c->get_idea() << "      " << c->get_idea()[3] << std::endl;
	std::cout << &d->get_idea() << "      " << d->get_idea()[3] << std::endl;
	i = 0;
	delete a;
	delete b;
	delete c;
	delete d;
	while (i < 10)
		delete j[i++];
}