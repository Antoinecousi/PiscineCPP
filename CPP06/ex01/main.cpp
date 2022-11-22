#include <string>
#include <iostream>

struct Data
{
	int		age;
	std::string	taille;
};

Data		*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

int			main()
{
	Data *Bob;
	uintptr_t ptr_serialized;

	Bob = new Data();
	Bob->age = 14;
	Bob->taille = "169cm";
	std::cout << "  normalize " << &Bob << "Age : " << Bob->age << " taille :" << Bob->taille << std::endl;
	ptr_serialized = serialize(Bob);
	std::cout << "  serialize " << &ptr_serialized << std::endl;
	Bob = deserialize(ptr_serialized);
	std::cout << "deserialize " << &Bob << "Age : " << Bob->age << " taille :" << Bob->taille << std::endl;
	delete Bob;
}