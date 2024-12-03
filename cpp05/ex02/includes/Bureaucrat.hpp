#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Bureaucrat
{
private:
	std::string _name;
	unsigned int _grade;
	static std::runtime_error _gradeTooHighException;
	static std::runtime_error _gradeTooLowException;
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const &bureaucrat);
	Bureaucrat &operator=(Bureaucrat const &bureaucrat);
	~Bureaucrat();

	std::string getName() const;
	unsigned int getGrade() const;

	void incrementGrade(unsigned int amount);
	void decrementGrade(unsigned int amount);

	void signForm(AForm &form);
	void executeForm(AForm const &form) const;
};
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);
#endif