#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
#include <iostream>
#include <exception>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <string>
#include <stack>
#include <list>
#include <iterator>


template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{
		}

		MutantStack(const MutantStack <T> & instance)
		{
			*this = instance;
		}

		MutantStack <T> &operator=(MutantStack const &rhs)
		{
			if (&rhs == this)
				return *this;
			this->c = rhs.c;
			return (*this);
		}

		virtual ~MutantStack(void)
		{
		}

		// renvoie le retour de la fonction begin contenue dans c qui est un type "contener" dans stack qui renvoie un iterateur sur le container du debut qui sera interprete comme un iterateur sur stack
		typename std::stack<T>::container_type::iterator				begin()
		{
			return (this->c.begin());
		}

		typename std::stack<T>::container_type::iterator				end()
		{
			return (this->c.end());
		}

		typename std::stack<T>::container_type::const_iterator			begin() const
		{
			return (this->c.begin());
		}

		typename std::stack<T>::container_type::const_iterator			end() const
		{
			return (this->c.end());
		}

		typename std::stack<T>::container_type::reverse_iterator		rbegin()
		{
			return (this->c.rbegin());
		}

		typename std::stack<T>::container_type::reverse_iterator		rend()
		{
			return (this->c.rend());
		}

		typename std::stack<T>::container_type::const_reverse_iterator	rbegin() const
		{
			return (this->c.rbegin());
		}

		typename std::stack<T>::container_type::const_reverse_iterator	rend() const
		{
			return (this->c.rend());
		}
};

#endif