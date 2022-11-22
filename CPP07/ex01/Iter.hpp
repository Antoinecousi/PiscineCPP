#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>
#include <string>

template<typename T>
void	iter(T *array, int size, void (*fct)(T & array_i))
{
	for (int i = 0 ; i < size ; i++)
		(*fct)(array[i]);
}

template<typename T>
void	iter(T const *array, int size, void (*fct)(T const & array_i))
{
	for (int i = 0 ; i < size ; i++)
		(*fct)(array[i]);
}

#endif