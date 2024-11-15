#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat John("John", 150);
	std::cout << John;
	Bureaucrat Bob("Bob", 1);
	std::cout << Bob << std::endl;
	Form useless_form("Useless Form", 150, 150);
	std::cout << useless_form << std::endl;
	Form important_form("Important Form", 1, 1);
	std::cout << important_form << std::endl;
	John.signForm(important_form);
	std::cout << std::endl << important_form << std::endl;
	Bob.signForm(important_form);
	std::cout << std::endl << important_form << std::endl;
	return 0;
}