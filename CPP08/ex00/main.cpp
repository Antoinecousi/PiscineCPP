#include "EasyFind.hpp"
#include <map>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

int main(void)
{
	{
	srand(1);
	std::vector<int>	tab(42, 0);
	
	for (int i = 0; i < 30 ; i++)
		tab[i] = rand() % 42 + 1;
	for (int i = 0; i < 30 ; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
		try 
		{
			std::cout << *(::easyfind(tab, 42)) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
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
			std::cout << *(::easyfind(tab, 41)) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
	srand(3);
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
	}
	{
	srand(10);
	std::list<int>	tab;
	int i = 0;
	int j = 0;
	for (; i < 30 ; i++)
		tab.push_back(rand() % 55 + 1);
	std::list<int>::iterator start = tab.begin();
	std::list<int>::iterator end = tab.end();
	std::cout << "I is = " << i << std::endl;
	for (; start != end ; start++)
	{
		std::cout << *start << " ";
		j++;
	}
	std::cout << std::endl;
	std::cout << "J is = " << j << std::endl;
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

	return (0);
}
