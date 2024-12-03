#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm) : AForm(shrubberyCreationForm.getName(), shrubberyCreationForm.getSignGrade(),
	shrubberyCreationForm.getExecGrade()), _target(shrubberyCreationForm._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrubberyCreationForm)
{
	this->setSignedStatus(shrubberyCreationForm.getSignedStatus());
	this->_target = shrubberyCreationForm._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::getGradeTooLowException();
	if (!this->getSignedStatus())
		throw AForm::getFormNotSignedException();
	std::ofstream file(this->_target + "_shrubbery");
	if (!file.is_open())
		throw std::runtime_error("File could not be opened");
	file << "               ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&%%%%&%&&%,@@@@@/@@@@@@,8888\\\\88/8o" << std::endl;
	file << "   ,%&\\\\%&&%&&%,@@@\\\\@@@/@@@88\\\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\\\@@/ /@@@88888\\\\88888'" << std::endl;
	file << "   %&&%/ %&%%%%&&@@\\\\ V /@@' `88\\\\8 `/88'" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\\\ '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << " \\\\\\\\/ .\\\\_//_/__/  ,\\\\_//__\\\\\\\\/.  \\\\_//__/" << std::endl;
	file.close();
}