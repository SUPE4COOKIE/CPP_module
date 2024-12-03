#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	~RobotomyRequestForm();
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &RobotomyRequestForm);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &RobotomyRequestForm);

	void execute(Bureaucrat const & executor) const;
};
# endif