#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
class Fixed
{
private:
	int fixed_point_value;
	static const int fractional_bits = 8;
public:
	Fixed(const int number);
	Fixed(const float number);
	Fixed();
	Fixed(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
};
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif