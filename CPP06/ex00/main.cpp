#include <cctype>
#include <string>
#include <iostream>
#include <cmath>


void	cout_char(std::string arg, std::string cast)
{
	int i = std::atoi(arg.c_str());

	std::cout << "char: ";
	if (arg == "nanf" || arg == "nan" || arg == "-inff" || arg == "+inff" || arg == "-inf" || arg == "+inf")
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (cast == "char")
		std::cout << "'" << arg << "'" << std::endl;
	else if (isprint(i))
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "non displayable" << std::endl;
}

void	cout_int(std::string arg, std::string cast)
{
	std::cout << "int: ";
	if (arg == "nanf" || arg == "nan" || arg == "-inff" || arg == "+inff" || arg == "-inf" || arg == "+inf")
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(atof(arg.c_str())) << std::endl;
}

void	cout_float(std::string arg, std::string cast)
{
	std::cout << "float: ";
	std::cout << static_cast<float>(atof(arg.c_str()));
	if (!fmod(atof(arg.c_str()), static_cast<float>(1))) // FMOD
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
}

void	cout_double(std::string arg, std::string cast)
{
	std::cout << "double : " << atof(arg.c_str());
	if (!fmod(atof(arg.c_str()), static_cast<float>(1)))
		std::cout << ".0";
	std::cout << std::endl;
}

void	convert(std::string arg, std::string cast)
{
	cout_char(arg, cast);
	cout_int(arg, cast);
	cout_float(arg, cast);
	cout_double(arg, cast);
}

bool	check_char(std::string str)
{
	if (str.size() != 1)
		return false;
	if (!std::isprint(str[0]))
	{
		std::cerr << "Non displayable character" << std::endl;
		return false;
	}
	if (std::isdigit(str[0]))
		return false;
	return true;
}

bool	check_int(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i != 0)
			return false;
		if (!isdigit(str[i]) && str[i] != '-')
			return false;
	}
	return true;
}

bool	check_float(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	int point = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i != 0)
			return false;
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '.' && str[i] != 'f')
			return false;
		if (str[i] == '.' && ((i == 0 || static_cast<unsigned long>(i) == (str.size() - 2)) || \
		(!isdigit(str[i - 1]) || !isdigit(str[i + 1]))))
			return false;
		if (str[i] == '.')
			point++;
		if (point > 1)
			return false; 
		if (str[i] == 'f' && static_cast<unsigned long>(i) != (str.size() - 1))
			return false;
	}
	if (str.find("f", 0) == str.npos)
		return false;
	return true;
}

bool	check_double(std::string str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	int point = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i != 0)
			return false;
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') 
			return false;
		if (str[i] == '.')
			point++;
		if (point > 1)
			return false; 
	}
	return true;
}

bool	detect_type(std::string arg, std::string *cast)
{
	if (arg.empty())
	{
		std::cerr << "Empty string." << std::endl;
		return (false);
	}
	if (check_char(arg))
	{
		*cast = "char";
		return (true);
	}
	if (check_int(arg))
	{
		*cast = "int";
		return (true);
	}
	if (check_float(arg))
	{
		*cast = "float";
		return (true);
	}
	if (check_double(arg))
	{
		*cast = "double";
		return (true);
	}
	return (false);
}

int		main(int argc, char **av)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments\n";
		return (1);
	}
	std::string	cast;	

	if (!detect_type(std::string(av[1]), &cast))
	{
		std::cerr << "Unknown type." << std::endl;
		return 1;
	}
	convert(av[1], cast);
	return (0);
}