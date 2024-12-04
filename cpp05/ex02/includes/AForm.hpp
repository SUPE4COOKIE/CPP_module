#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <stdexcept>

class Bureaucrat;
class AForm
{
private:
	const std::string _name;
	bool _is_signed;
	const unsigned int _sign_grade;
	const unsigned int _exec_grade;
	static std::runtime_error _gradeTooHighException;
	static std::runtime_error _gradeTooLowException;
	static std::runtime_error _formNotSignedException;
public:
	AForm();
	AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade);
	AForm(AForm const &form);
	AForm &operator=(AForm const &form);
	virtual ~AForm();

	const std::string getName() const;
	bool getSignedStatus() const;
	void setSignedStatus(bool status);
	static std::runtime_error getGradeTooHighException();
	static std::runtime_error getGradeTooLowException();
	static std::runtime_error getFormNotSignedException();
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;

	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif