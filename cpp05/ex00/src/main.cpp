#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat John("John", 150);
	std::cout << John;
	Bureaucrat Bob("Bob", 1);
	std::cout << Bob;
	try
	{
		Bureaucrat Michel("Michel", 175);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Joe("Joe", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Sam("Sam", 150);
		Sam.decrementGrade(1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Mike("Mike", 1);
		Mike.incrementGrade(1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}