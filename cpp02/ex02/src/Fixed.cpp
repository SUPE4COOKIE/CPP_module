#include "Fixed.hpp"

Fixed::Fixed(const int number) : fixed_point_value(number * (1 << fractional_bits)) {}
Fixed::Fixed() : fixed_point_value(0) {}
Fixed::Fixed(const float number) : fixed_point_value(roundf(number * (1 << fractional_bits))) {}
Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}
Fixed &Fixed::operator=(const Fixed &fixed)
{
	fixed_point_value = fixed.fixed_point_value;
	return *this;
}
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed &fixed) {return this->fixed_point_value > fixed.fixed_point_value;}
bool Fixed::operator<(const Fixed &fixed) {return this->fixed_point_value < fixed.fixed_point_value;}
bool Fixed::operator>=(const Fixed &fixed) {return this->fixed_point_value >= fixed.fixed_point_value;}
bool Fixed::operator<=(const Fixed &fixed) {return this->fixed_point_value <= fixed.fixed_point_value;}
bool Fixed::operator==(const Fixed &fixed) {return this->fixed_point_value == fixed.fixed_point_value;}
bool Fixed::operator!=(const Fixed &fixed) {return this->fixed_point_value != fixed.fixed_point_value;}
Fixed &Fixed::operator+(const Fixed &fixed)
{
	this->fixed_point_value += fixed.fixed_point_value;
	return *this;
}
Fixed &Fixed::operator-(const Fixed &fixed)
{
	this->fixed_point_value -= fixed.fixed_point_value;
	return *this;
}
Fixed &Fixed::operator*(const Fixed &fixed)
{
	this->fixed_point_value = (this->fixed_point_value * fixed.fixed_point_value) / (1 << fractional_bits);
	return *this;
}
Fixed &Fixed::operator/(const Fixed &fixed)
{
	this->fixed_point_value = (this->fixed_point_value * (1 << fractional_bits)) / fixed.fixed_point_value;
	return *this;
}
Fixed &Fixed::operator++()
{
	this->fixed_point_value++;
	return *this;
}
Fixed &Fixed::operator--()
{
	this->fixed_point_value--;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->fixed_point_value++;
	return tmp;

}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->fixed_point_value--;
	return tmp;
}
int Fixed::getRawBits(void) const {return fixed_point_value;}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
float Fixed::toFloat(void) const {return (float)fixed_point_value / (1 << fractional_bits);}
int Fixed::toInt(void) const {return fixed_point_value >> fractional_bits;}
void Fixed::setRawBits(int const raw) {fixed_point_value = raw;}
Fixed::~Fixed() {}