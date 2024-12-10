#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>

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
double convertDouble(double num);
void cantConvert();
void printConversion(double num);
#endif
