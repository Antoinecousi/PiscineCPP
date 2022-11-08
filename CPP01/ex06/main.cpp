#include "Harl.hpp"

int		main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments. \nYou can use DEBUG/INFO/WARNING/ERROR or any other string" << std::endl;
		return (1);
	}
	Harl	monsieurHarl;
	monsieurHarl.complain(argv[1]);
}