#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <exception>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/time.h>

class NoSpace : public std::exception
{
	public :
		const char * what() const throw()
		{
			return "Vector has no space left";
		}
};

class WrongSize : public std::exception
{
	public :
		const char * what() const throw()
		{
			return "Vector doesn't have a convenient size";
		}
};

class Span
{
	public:
		Span();
		Span(unsigned int nb);
		Span(Span const &instance);
		Span &operator=(Span const &rhs);
		~Span(void);

		template<typename I>
		void				addALotOfNumbers(I itstart, I itend);
		void				addNumber(int add);
		int					shortestSpan();
		int					longestSpan();

		unsigned int		get_max() const;
		std::vector<int>	get_vect_int() const;		

	private:
		std::vector<int>	_vect_int;
		unsigned int		_max;
};

std::ostream	&operator<<(std::ostream & o, Span & rhs);

template<typename I>
void				Span::addALotOfNumbers(I itstart, I itend)
{
	struct timeval	now;

	gettimeofday(&now, NULL);;
	srand(now.tv_usec);
	for ( ; itstart < itend ; itstart++)
	{
		if (_vect_int.size() == _max)
			throw NoSpace();
		else
			_vect_int.push_back(rand() % 150053 + 1);
	}
}

#endif