#include "Form.hpp"
#include "Bureaucrat.hpp"

std::runtime_error Form::_gradeTooHighException = std::runtime_error("Grade is too high");
std::runtime_error Form::_gradeTooLowException = std::runtime_error("Grade is too low");

Form::Form() : _name("No Name"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}
Form::Form(std::string name, unsigned int sign_grade, unsigned int exec_grade)
	: _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::_gradeTooHighException;
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::_gradeTooLowException;
}

Form &Form::operator=(Form const &form) 
{
	this->_is_signed = form.getSignedStatus();
	return *this;
}
Form::Form(Form const &form) 
	: _name(form.getName()), _is_signed(form.getSignedStatus()), _sign_grade(form.getSignGrade()), _exec_grade(form.getExecGrade()){}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw Form::_gradeTooLowException;
	this->_is_signed = true;
}

const std::string Form::getName() const { return _name; }
bool Form::getSignedStatus() const { return _is_signed; }
unsigned int Form::getSignGrade() const { return _sign_grade; }
unsigned int Form::getExecGrade() const { return _exec_grade; }

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << form.getName() << " is " << (form.getSignedStatus() ? "" : "not ") << "signed" << std::endl;
	os << "Sign grade: " << form.getSignGrade() << std::endl;
	os << "Execution grade: " << form.getExecGrade() << std::endl;
	return os;
}

Form::~Form() {}