#include "Fixed.hpp"

Fixed::Fixed() : _decimals(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	this->_decimals = number;
	this->_decimals <<= this->_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	this->_decimals = roundf(256.0 * number);
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &instance)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

std::ostream & operator<<(std::ostream & o, const Fixed & rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed &	Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_decimals = rhs.getRawBits();	
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_decimals);
}

void	Fixed::setRawBits( int const raw ) 
{
	this->_decimals = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_decimals / (float)(256));
}

int	Fixed::toInt(void) const
{
	return (_decimals >> 8);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}