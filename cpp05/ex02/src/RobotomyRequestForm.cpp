#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm) : AForm(robotomyRequestForm.getName(), robotomyRequestForm.getSignGrade(),
	robotomyRequestForm.getExecGrade()), _target(robotomyRequestForm._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
	this->setSignedStatus(robotomyRequestForm.getSignedStatus());
	this->_target = robotomyRequestForm._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::getGradeTooLowException();
	if (!this->getSignedStatus())
		throw AForm::getFormNotSignedException();
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomy has failed" << std::endl;
}