#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(8388608);
	std::cout << c << std::endl;
	c.setRawBits(roundf(2.5 * 256));
	std::cout << c << std::endl;
	Fixed d(2);
	std::cout << c / d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << (c >= d) << std::endl;
	return 0;
}