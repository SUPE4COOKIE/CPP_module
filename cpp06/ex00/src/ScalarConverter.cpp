#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &sc) { *this = sc; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc) { (void)sc; return *this; }
ScalarConverter::~ScalarConverter() {}

char convertChar(double num)
{
	if (num < 32 || num > 126)
		throw std::invalid_argument("impossible");
	return static_cast<char>(num);
}

int convertInt(double num)
{
	if (num < INT_MIN || num > INT_MAX)
		throw std::invalid_argument("impossible");
	return static_cast<int>(num);
}

float convertFloat(double num)
{
	
}

void cantConvert()
{
	std::cout << std::endl << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

double convertDouble(std::string str)
{
	double result;
	char *endptr;
	result = std::strtod(str.c_str(), &endptr);
	if (errno == ERANGE)
		throw std::invalid_argument("impossible");
	else if (errno == EINVAL || *endptr != 0) // will finish at f if float ?
		throw std::invalid_argument("impossible");
	return result;
}

void printConversion(double num)
{
	std::cout << "char: ";
	try
	{
		std::cout << convertChar(num) << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		std::cout << convertInt(num) << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		std::cout << convertFloat(num) << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		std::cout << convertDouble(num) << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convert(std::string str)
{
	double num;
	try
	{
		num = convertDouble(str);
	}
	catch (std::invalid_argument &e)
	{
		return cantConvert();
	}
	printConversion(num);
}