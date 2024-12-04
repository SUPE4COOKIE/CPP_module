#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(time(0));
	Bureaucrat b1("Bureaucrat 1", 1);
	Bureaucrat b2("Bureaucrat 2", 150);
	Bureaucrat b3("Bureaucrat 3", 10);
	ShrubberyCreationForm s1("home");
	RobotomyRequestForm r1("salut");
	PresidentialPardonForm p1("coucou");

	std::cout << s1 << std::endl;
	b1.executeForm(s1);
	b1.signForm(s1);
	b2.executeForm(s1);
	b3.executeForm(s1);
	std::cout << std::endl;
	b3.signForm(r1);
	b1.executeForm(r1);
	b1.executeForm(r1);
	b1.executeForm(r1);
	std::cout << std::endl;
	b1.signForm(p1);
	b1.executeForm(p1);
	return 0;
}