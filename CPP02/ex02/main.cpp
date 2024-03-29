#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed 		a;
	Fixed 		c (127);
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a.decimals() << a << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << --a << a.decimals() << std::endl << std::endl;
	std::cout << ++a << a.decimals() << std::endl << std::endl;
	std::cout << ++a << a.decimals() << std::endl << std::endl;
	std::cout << ++a << a.decimals() << std::endl << std::endl;
	std::cout << ++a << a.decimals() << std::endl << std::endl;
	std::cout << ++a << a.decimals() << std::endl << std::endl;
	std::cout << ++a << a.decimals() << std::endl << std::endl;
	std::cout << ++a << a.decimals() << std::endl << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}