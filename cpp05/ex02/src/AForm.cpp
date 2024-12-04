#include "AForm.hpp"
#include "Bureaucrat.hpp"

std::runtime_error AForm::_gradeTooHighException = std::runtime_error("Grade is too high");
std::runtime_error AForm::_gradeTooLowException = std::runtime_error("Grade is too low");
std::runtime_error AForm::_formNotSignedException = std::runtime_error("Form is not signed");

AForm::AForm() : _name("No Name"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}
AForm::AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade)
	: _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::_gradeTooHighException;
	else if (sign_grade > 150 || exec_grade > 150)
		throw AForm::_gradeTooLowException;
}

AForm::AForm(AForm const &form) 
	: _name(form.getName()), _is_signed(form.getSignedStatus()), _sign_grade(form.getSignGrade()), _exec_grade(form.getExecGrade()){}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw AForm::_gradeTooLowException;
	this->_is_signed = true;
}

AForm &AForm::operator=(AForm const &form) 
{
	this->_is_signed = form.getSignedStatus();
	return *this;
}

const std::string AForm::getName() const { return _name; }
bool AForm::getSignedStatus() const { return _is_signed; }
unsigned int AForm::getSignGrade() const { return _sign_grade; }
unsigned int AForm::getExecGrade() const { return _exec_grade; }
void AForm::setSignedStatus(bool status) { _is_signed = status; }
std::runtime_error AForm::getGradeTooHighException() { return _gradeTooHighException; }
std::runtime_error AForm::getGradeTooLowException() { return _gradeTooLowException; }
std::runtime_error AForm::getFormNotSignedException() { return _formNotSignedException; }
std::ostream &operator<<(std::ostream &os, AForm const &form)
{
	os << form.getName() << " is " << (form.getSignedStatus() ? "" : "not ") << "signed" << std::endl;
	os << "Sign grade: " << form.getSignGrade() << std::endl;
	os << "Execution grade: " << form.getExecGrade() << std::endl;
	return os;
}

AForm::~AForm() {}