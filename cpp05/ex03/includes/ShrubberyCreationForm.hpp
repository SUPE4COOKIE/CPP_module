#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	~ShrubberyCreationForm();
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &shrubberyCreationForm);

	void execute(Bureaucrat const & executor) const;
};
# endif
