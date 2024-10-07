#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
private:
	int fixed_point_value;
	static const int fractional_bits = 8;
public:
	Fixed(int number);
	Fixed();
	Fixed(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
};

#endif