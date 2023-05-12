#include "PmergeMe.hpp"	

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	int i = 1;
	int j = 0;

	while (i < argc)
	{
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '+')
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			if (argv[i][j] == '+' && argv[i][j + 1] == '+') // check segfault
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			j++;
		}
		i++;
	}
	PmergeMe pmergeMe(argv + 1);
	return (0);
}