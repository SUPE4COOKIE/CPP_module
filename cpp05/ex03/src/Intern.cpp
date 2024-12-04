#include "Intern.hpp"

std::string Intern::formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
Intern::Intern() {}
Intern::Intern(Intern const &Intern) {*this = Intern;}
Intern &Intern::operator=(Intern const &Intern)
{
	(void)Intern;
	return *this;
}
Intern::~Intern() {}
AForm *Intern::makeForm(std::string formName, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			if (i == 0)
				return new ShrubberyCreationForm(target);
			else if (i == 1)
				return new RobotomyRequestForm(target);
			else if (i == 2)
				return new PresidentialPardonForm(target);
		}
	}
	std::cerr << "Intern couldn't create non existent form" << std::endl;
	return NULL;
}