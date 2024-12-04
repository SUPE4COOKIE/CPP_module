#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(time(0));
	Bureaucrat b1("Bureaucrat 1", 1);
	Bureaucrat b2("Bureaucrat 2", 150);
	Bureaucrat b3("Bureaucrat 3", 10);
	Intern intern;
	AForm *s1;
	AForm *r1;
	AForm *p1;

	s1 = intern.makeForm("shrubbery creation", "home");
	r1 = intern.makeForm("robotomy request", "salut");
	p1 = intern.makeForm("presidential pardon", "coucou");

	b1.executeForm(*s1);
	b1.signForm(*s1);
	b2.executeForm(*s1);
	b3.executeForm(*s1);
	std::cout << std::endl;
	b3.signForm(*r1);
	b1.executeForm(*r1);
	b1.executeForm(*r1);
	b1.executeForm(*r1);
	std::cout << std::endl;
	b1.signForm(*p1);
	b1.executeForm(*p1);

	delete s1;
	delete r1;
	delete p1;
	return 0;
}