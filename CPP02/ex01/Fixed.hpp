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
		~Fixed(void);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_decimals;
		const static int	_bits = 8;

};
std::ostream & operator<<(std::ostream & o, const Fixed & rhs);

#endif