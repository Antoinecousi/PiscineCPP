#ifndef FIXED_HPP
# define FIXED_HPP
#include <string>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &instance);
		Fixed &operator=(Fixed const &rhs);
		~Fixed(void);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_decimals;
		const static int	_bits = 8;

};

#endif