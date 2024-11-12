#include "Form.hpp"

std::runtime_error Form::_gradeTooHighException = std::runtime_error("Grade is too high");
std::runtime_error Form::_gradeTooLowException = std::runtime_error("Grade is too low");

Form::Form() : _name("No Name"), _sign_grade(150), _exec_grade(150) {}
Form::Form(std::string name, unsigned int sign_grade, unsigned int exec_grade)
	: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::_gradeTooHighException;
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::_gradeTooLowException;
}
Form::Form(Form const &form) 
	: _name(form.getName()), _sign_grade(form.getSignGrade()), _exec_grade(form.getExecGrade()) {}