#include "Fixed.hpp"

Fixed::Fixed(const int number) : fixed_point_value(number * (1 << fractional_bits)) {std::cout << "Int constructor called" << std::endl;}
Fixed::Fixed() : fixed_point_value(0) {std::cout << "Default constructor called" << std::endl;}
Fixed::Fixed(const float number) : fixed_point_value(roundf(number * (1 << fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_point_value = fixed.fixed_point_value;
	return *this;
}
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point_value;
}

float Fixed::toFloat(void) const {return (float)fixed_point_value / (1 << fractional_bits);}
int Fixed::toInt(void) const {return fixed_point_value >> fractional_bits;}
void Fixed::setRawBits(int const raw) {fixed_point_value = raw;}
Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}