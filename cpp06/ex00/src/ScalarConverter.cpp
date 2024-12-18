#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &sc) { *this = sc; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc) { (void)sc; return *this; }
ScalarConverter::~ScalarConverter() {}
bool isNan(double num) { return num != num; }
bool isInf(double num) { return (num == std::numeric_limits<double>::infinity() || num == -std::numeric_limits<double>::infinity()); }
bool isChar(std::string c) { return (c.length() == 1 && !isdigit(c[0])); }
char convertChar(double num)
{
	if (isNan(num) || isInf(num))
		throw std::invalid_argument("impossible");
	if (num < 32 || num > 126)
		throw std::invalid_argument("Non displayable");
	return static_cast<char>(num);
}

int convertInt(double num)
{
	if ((num < INT_MIN || num > INT_MAX) || isNan(num) || isInf(num))
		throw std::invalid_argument("impossible");
	return static_cast<int>(num);
}

float convertFloat(double num)
{
	return static_cast<float>(num);
}

void cantConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

double convertDouble(std::string str)
{
	double result;
	char *endptr;

	if (isChar(str))
		return static_cast<double>(str[0]);
	result = std::strtod(str.c_str(), &endptr);
	if (errno == ERANGE)
		throw std::invalid_argument("impossible");
	else if (errno == EINVAL || (*endptr != 0 && !(*endptr == 'f' && *(endptr + 1) == 0)))
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
		std::cout << e.what() << std::endl;
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
		if (num == static_cast<int>(num))
			std::cout <<  convertFloat(num) << ".0f" << std::endl;
		else
			std::cout << convertFloat(num) << "f" << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		if (num == static_cast<int>(num))
			std::cout << num << ".0" << std::endl;
		else
			std::cout << num << std::endl;
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