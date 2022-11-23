#include "EasyFind.hpp"
#include <map>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

int main(void)
{
	{
	std::vector<int>	tab(42, 0);
	
	for (int i = 0; i < 30 ; i++)
		tab[i] = rand() % 42 + 1;
	for (int i = 0; i < 30 ; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
		try 
		{
			std::cout << *(::easyfind(tab, 1)) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		try 
		{
			std::cout << *(::easyfind(tab, 10)) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		try 
		{
			std::cout << *(::easyfind(tab, 20)) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::vector<float>	tab(42, 0);
	
	for (float i = 0; i < 30 ; i++)
		tab[i] = rand() % 42 + 1;
	for (float i = 0; i < 30 ; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
		try 
		{
			std::cout << *(::easyfind(tab, 1)) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		try 
		{
			std::cout << *(::easyfind(tab, 10)) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		try 
		{
			std::cout << *(::easyfind(tab, 20)) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	return (0);
}
