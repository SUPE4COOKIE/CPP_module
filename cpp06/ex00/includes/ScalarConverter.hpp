#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <climits>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &sc);
	ScalarConverter &operator=(const ScalarConverter &sc);
	~ScalarConverter();
public:
	static void convert(std::string str);
};

char convertChar(double num);
int convertInt(double num);
float convertFloat(double num);
void cantConvert();
void printConversion(double num);
bool isNan(double num);
bool isInf(double num);
#endif
