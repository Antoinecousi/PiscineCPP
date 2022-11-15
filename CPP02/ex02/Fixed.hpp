#ifndef FIXED_HPP
# define FIXED_HPP
#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(Fixed const &instance);
		Fixed &operator=(Fixed const &rhs);

		Fixed &operator++(void);
		Fixed	operator++(int);
		Fixed &operator--(void);
		Fixed 	operator--(int);

		Fixed	operator*(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);
		
		bool	operator<(const Fixed &rhs);
		bool	operator>(const Fixed &rhs);
		bool	operator>=(const Fixed &rhs);
		bool	operator<=(const Fixed &rhs);
		bool	operator==(const Fixed &rhs);
		bool	operator!=(const Fixed &rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
		
		static	const Fixed &min(const Fixed &lhs, const Fixed &rhs);
		static	const Fixed &max(const Fixed &lhs, const Fixed &rhs);

		static	Fixed &min(Fixed &lhs, Fixed &rhs);

		int		decimals();
		static	Fixed &max(Fixed &lhs, Fixed &rhs);

		~Fixed(void);

	private:
		int					_decimals;
		const static int	_bits = 8;

};
std::ostream &operator<<(std::ostream &o, const Fixed &rhs);

#endif