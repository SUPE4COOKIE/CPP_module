#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat
{
private:
	std::string _name;
	unsigned int _grade;
	std::string _gradeTooHighException;
	std::string _gradeTooLowException;
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	~Bureaucrat();

	std::string getName() const;
	unsigned int getGrade() const;

	void incrementGrade(unsigned int amount);
	void decrementGrade(unsigned int amount);
};
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);
#endif