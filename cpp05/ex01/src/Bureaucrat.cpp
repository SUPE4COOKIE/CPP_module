#include "Bureaucrat.hpp"

std::runtime_error Bureaucrat::_gradeTooHighException = std::runtime_error("Grade is too high");
std::runtime_error Bureaucrat::_gradeTooLowException = std::runtime_error("Grade is too low");

Bureaucrat::Bureaucrat() : _name("No Name"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::_gradeTooHighException;
	else if (grade > 150)
		throw Bureaucrat::_gradeTooLowException;
	_grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) {*this = bureaucrat;}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	this->_name = bureaucrat.getName();
	this->_grade = bureaucrat.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

std::string Bureaucrat::getName() const { return _name; }
unsigned int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade(unsigned int amount)
{
	if (this->_grade <= amount)
		throw Bureaucrat::_gradeTooHighException;
	this->_grade -= amount;
}
void Bureaucrat::decrementGrade(unsigned int amount)
{
	if (this->_grade + amount > 150)
		throw Bureaucrat::_gradeTooLowException;
	this->_grade += amount;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}
Bureaucrat::~Bureaucrat() {}