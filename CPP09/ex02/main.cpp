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
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '+')
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			if ((argv[i][j] == '+' && j > 0) || (argv[i][j] == '+' && (argv[i][j+1] < '0' || argv[i][j+1] > '9')))
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			if (std::atoi(argv[i]) < 1 || std::atol(argv[i]) > 2147483647)
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