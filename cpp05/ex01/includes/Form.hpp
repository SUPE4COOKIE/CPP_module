#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <stdexcept>

class Bureaucrat;
class Form
{
private:
	const std::string _name;
	bool _is_signed;
	const unsigned int _sign_grade;
	const unsigned int _exec_grade;
	static std::runtime_error _gradeTooHighException;
	static std::runtime_error _gradeTooLowException;
public:
	Form();
	Form(std::string name, unsigned int sign_grade, unsigned int exec_grade);
	Form(Form const &form);
	Form &operator=(Form const &form);
	~Form();

	const std::string getName() const;
	bool getSignedStatus() const;
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;

	void beSigned(Bureaucrat &bureaucrat);
};
std::ostream &operator<<(std::ostream &os, Form const &form);

#endif