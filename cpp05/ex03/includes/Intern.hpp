#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
class Intern
{
private:
	static std::string formNames[3];
public:
	Intern();
	Intern(Intern const &Intern);
	Intern &operator=(Intern const &Intern);
	~Intern();

	AForm *makeForm(std::string formName, std::string target);
};

#endif