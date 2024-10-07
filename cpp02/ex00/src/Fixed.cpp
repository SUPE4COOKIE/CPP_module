#include "Fixed.hpp"

Fixed::Fixed(int number) : fixed_point_value(number) {}
Fixed::Fixed() : fixed_point_value(0) {std::cout << "Default constructor called" << std::endl;}
Fixed::Fixed(const Fixed &fixed) : fixed_point_value(fixed.fixed_point_value) {std::cout << "Copy constructor called" << std::endl;}
Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_point_value = fixed.fixed_point_value;
	return *this;
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point_value;
}

void Fixed::setRawBits(int const raw) {fixed_point_value = raw;}
Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}