#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <exception>
#include <cstdlib>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span(unsigned int nb);
		Span(Span const &instance);
		Span &operator=(Span const &rhs);
		~Span(void);

		template<typename I>
		void				addALotOfNumbers(I itstart, I itend, int min, int max);
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
void				addALotOfNumbers(I itstart, I itend)
{
	for ( ; itstart < itend ; itstart++)
	{
		if (_vect_int.size() == _max)
			throw SizeFull();
		else
			_vect_int.push_back(rand() % 1000 + 1);
	}
}


#endif