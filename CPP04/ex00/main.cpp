#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	// ------------------------------------- //
	// --------- PARTIE DU SUJET ----------- //
	// ------------------------------------- //

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n\n\n TEST WRONG \n\n\n\n";
	// ------------------------------------- //
	// --------- PARTIE DE WRONG ----------- //
	// ------------------------------------- //

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();
	const WrongCat* wrongCatCat = new WrongCat();
	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound(); //will output the animal sound!
	wrongMeta->makeSound();
	wrongCatCat->makeSound();

	delete wrongMeta;
	delete wrongI;
	delete wrongCatCat;
	// return (1);
}