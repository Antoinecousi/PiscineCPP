#include "BitcoinExchange.hpp"

bool isFile(const std::string& name)
{
    struct stat buffer;   
    return (stat(name.c_str(), &buffer) == 0 && !S_ISDIR(buffer.st_mode)); 
}

int	main(int ac, char **argv)
{

	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	std::ifstream	file(argv[1]);
	std::string		line;
	std::string		*str;
	BitcoinExchange	*btc;

	if (!isFile(argv[1]))
	{
		std::cout << "Error: could not open file!" << std::endl;
		return (1);
	}

	if (file.is_open())
	{
		btc = new BitcoinExchange(file);
		file.close();
		delete(btc);
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	return (0);
}