#include "Fixed.hpp"

Fixed::Fixed() : _decimals(0)
{
}

Fixed::Fixed(const int number)
{
	this->_decimals = number;
	this->_decimals <<= this->_bits;
}

Fixed::Fixed(const float number)
{
	this->_decimals = roundf(256.0 * number);
}

Fixed::Fixed(Fixed const &instance)
{
	*this = instance;
}

Fixed &	Fixed::operator=(Fixed const &rhs)
{
	this->_decimals = rhs.getRawBits();
	return (*this);
}


Fixed &	Fixed::operator++(void)
{
	_decimals++;
	return(*this);	
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);
	operator++();
	return (copy);
}

Fixed &	Fixed::operator--(void)
{
	_decimals--;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);
	operator--();
	return (copy);
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

bool	Fixed::operator<(const Fixed &rhs)
{
	return (_decimals < rhs._decimals);;
}

bool	Fixed::operator>(const Fixed &rhs)
{
	return (_decimals > rhs._decimals);
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	return (_decimals >= rhs._decimals);
}

bool	Fixed::operator<=(const Fixed &rhs)
{
	return (_decimals <= rhs._decimals);
}

bool	Fixed::operator==(const Fixed &rhs)
{
	return (_decimals == rhs._decimals);
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	return (_decimals != rhs._decimals);
}

const Fixed &	Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs._decimals < rhs._decimals)
		return lhs;
	else
		return rhs;
}

const Fixed &	Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
		if (lhs._decimals < rhs._decimals)
		return rhs;
	else
		return lhs;
}

Fixed &	Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return lhs;
	else
		return rhs;
}

Fixed &	Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return lhs;
	else
		return rhs;
}

int	Fixed::getRawBits( void ) const
{
	return (this->_decimals);;
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
}

std::ostream & operator<<(std::ostream & o, const Fixed & rhs)
{
	o << rhs.toFloat();
	return (o);
}