#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

class NoOccurenceFound : public std::exception
{
	const char * what() const throw ()
	{
		return ("No Occurence Found");
	};
};

template<typename T>
typename T::iterator	easyfind(T containerInt, int searched)
{
	typename T::iterator occurence = std::find(containerInt.begin(), containerInt.end(), searched);
	if (occurence == containerInt.end())
		throw NoOccurenceFound();
	else
		return occurence;
}


#endif