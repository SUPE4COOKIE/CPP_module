#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	~PresidentialPardonForm();
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &PresidentialPardonForm);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &PresidentialPardonForm);

	void execute(Bureaucrat const & executor) const;
};
# endif