#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

int		check_errors(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "The program takes 3 parameters." << std::endl;
		return (1);
	}
	if (!std::string(argv[1]).compare("") || !std::string(argv[2]).compare("") || !std::string(argv[3]).compare(""))
	{
		std::cout << "String is empty." << std::endl;
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	std::string		tmp;
	std::fstream	file_to_open;
	std::fstream	file_to_create;
	size_t			pos = 0;

	if (check_errors(argc, argv))
		return (1);
	file_to_open.open(argv[1], std::ios::in);
	if (!file_to_open.is_open())
	{
		std::cerr << argv[1] << " doesn't exist on this folder." << std::endl;
		return (1);
	}
	std::string future_filename(argv[1]);
	future_filename += ".replace";
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	file_to_create.open(future_filename, std::ios::out);
	if (file_to_create.is_open())
	{
		while (!file_to_open.eof())
		{
			getline(file_to_open, tmp);
			pos = 0;
			while (pos < tmp.size())
			{
				pos = tmp.find(str1, pos);
				if (pos < tmp.size())
				{
					tmp.erase(pos, str1.size());
					tmp.insert(pos, str2);
					pos += str2.size();
				}
			}
			file_to_create << tmp;
			if (!file_to_open.eof())
				file_to_create << std::endl;
		}
		file_to_create.close();
		file_to_open.close();
	}
	else
	{
		file_to_open.close();
		std::cerr << "error creating this file." << argv[1] << std::endl;
		return (1);
	}
	return (0);
}