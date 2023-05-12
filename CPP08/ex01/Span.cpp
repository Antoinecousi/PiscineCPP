#include "Span.hpp"

Span::Span() : _max(0)
{
}

Span::Span(unsigned int nb) : _max(nb)
{
}

Span::Span(Span const &instance)
{
	*this = instance;	
}

Span::~Span(void)
{
	
}

Span &	Span::operator=(Span const &rhs)
{
	if (&rhs == this)
		return *this;
	_max = rhs.get_max();
	std::vector<int> copied = rhs.get_vect_int();
	_vect_int = copied;
	std::copy(copied.begin(), copied.end(), _vect_int.begin());
	return *this;
}

void	Span::addNumber(int add)
{
	try
	{
		if (_vect_int.size() == _max)
			throw NoSpace();
		else
			_vect_int.push_back(add);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int	Span::shortestSpan()
{
	if (_vect_int.size() < 2 )
		throw WrongSize();

	unsigned int		tmp = 4294967295;
	Span	copy;

	copy = *this;
	std::sort(copy._vect_int.begin(), copy._vect_int.end());
	std::vector<int>::iterator start = copy._vect_int.begin();
	for (; start < copy._vect_int.end() - 1 ; start++)
	{
		int	diff = ((*(start + 1) - *start) * (*(start + 1) > *start)) + ((*start - *(start + 1) ) * (*start > *(start + 1)));
		if (tmp > diff)
			tmp = diff;
	}
	return (tmp);
}

int	Span::longestSpan()
{
	if (_vect_int.size() < 2 )
		throw WrongSize();
	Span	copy;

	copy = *this;
	std::sort(copy._vect_int.begin(), copy._vect_int.end());
	std::vector<int>::iterator start = copy._vect_int.begin();
	std::vector<int>::iterator end = copy._vect_int.end() - 1;
	return (*end - *start);
}

unsigned int		Span::get_max(void) const
{
	return _max;
}

std::vector<int>	Span::get_vect_int(void) const
{
	return _vect_int;
}

std::ostream	&	operator<<(std::ostream & o, Span & rhs)
{
	std::vector<int> copy = rhs.get_vect_int();
	std::vector<int>::iterator	start = copy.begin();
	for (; start != copy.end() ; start++)
		o << *start << " ";
	return o;
}