#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm) : AForm(presidentialPardonForm.getName(), presidentialPardonForm.getSignGrade(),
	presidentialPardonForm.getExecGrade()), _target(presidentialPardonForm._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
	this->setSignedStatus(presidentialPardonForm.getSignedStatus());
	this->_target = presidentialPardonForm._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::getGradeTooLowException();
	if (!this->getSignedStatus())
		throw AForm::getFormNotSignedException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
