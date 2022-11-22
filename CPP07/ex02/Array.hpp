#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>
#include <string>

template<typename T>
class Array
{
	public:
		Array(void) : _array(NULL)
		{
			_array = new T[1];
			_size = 1;
		};
		
		Array(unsigned int n) : _array(NULL)
		{
			_array =  new T[n];
			_size = n;		
		};
	
		Array(Array & rhs) : _array(NULL)
		{
			*this = rhs;
		};
		
		~Array(void)
		{
			delete [] _array;
		};

		Array & operator=(Array & src)	
		{
			if (_array)
				delete [] _array;
			_size = src.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src[i];
			return (*this);
		};

		T & operator[](unsigned int i)
		{
			if (i < 0 || i >= _size)
				throw SegfaultSaviour();
			return (_array[i]);
		};
	
		unsigned int size(void) const
		{
			return (_size);
		};

		class SegfaultSaviour : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("This address is not instancied");
			};
		};

	private:
		unsigned int	_size;
		T				*_array;

};

template<typename T>
std::ostream & operator<<(std::ostream & o, Array<T> & rhs)
{
	for (unsigned int i = 0; i < rhs.size(); i++)
		o << rhs[i] << " ";
	return o;
}

#endif