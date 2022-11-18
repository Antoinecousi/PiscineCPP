#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("lol");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "\n\n\n\n\n\n Second test \n\n\n\n\n\n\n";
	IMateriaSource *Factory;
	Factory = new MateriaSource();						// Factory instanciated to learn and create matiera. Can have 4 matieras max
	ICharacter *Mary = new Character("Mary");
	Factory->learnMateria(new Ice("Frost"));			// Factory learns Ice Matiera named Givre
	Factory->learnMateria(new Ice("Blizzard"));			// Factory learns Ice Matiera named Blizzard
	Factory->learnMateria(new Cure("Dressing"));		// Factory learns Cure Matiera named Dressing
	Factory->learnMateria(new Cure("Bandage"));			// Factory learns Cure Matiera named Bandage
	AMateria* Warehouse;								// Parent class of matiera, can be ice cure or other
	ICharacter *Philip = new Character("Philip");
	Warehouse = Factory->createMateria("Frost");
	Mary->equip(Warehouse);
	Warehouse = Factory->createMateria("Blizzard");
	Mary->equip(Warehouse);
	Warehouse = Factory->createMateria("Dressing");
	Mary->equip(Warehouse);
	Warehouse = Factory->createMateria("Bandage");
	Mary->equip(Warehouse);
	Mary->use(0, *Philip);
	Mary->use(1, *Philip);
	Mary->use(2, *Philip);
	Mary->use(3, *Philip);
	Mary->unequip(2);									//Unequiping the "Dressing" AMateria::cure
	Mary->use(2, *Philip);								// matiera index 2 replaced by 3
	Mary->use(3, *Philip);								// Cannot work 
	Mary->equip(new Ice("Snow"));
	Mary->use(3, *Philip);								// throw ice 
	Mary->equip(new Ice("Snow"));						// Cannot work
	Mary->unequip(0);
	Mary->unequip(0);
	Mary->unequip(0);
	Mary->unequip(0);
	Mary->unequip(0);
	Mary->use(3, *Philip);								// Cannot work
	Mary->use(4, *Philip);								// Cannot work 
	Mary->use(-1, *Philip);								// Cannot work 
	Mary->equip(new Ice("Snow"));
	Mary->use(0, *Philip);

	delete Mary;
	delete Factory;
	delete Philip;

	return 0;
}