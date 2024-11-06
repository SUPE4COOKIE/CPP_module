#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("No Name"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

std::string Bureaucrat::getName() const { return _name; }
unsigned int Bureaucrat::getGrade() const { return _grade; }

void incrementGrade(unsigned int amount)
{
	if (_grade - amount < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= amount;
}
Bureaucrat::~Bureaucrat() {}