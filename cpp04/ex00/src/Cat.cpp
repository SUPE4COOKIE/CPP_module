#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {std::cout << "Cat Default constructor called for " << GREEN << _type << RESET << std::endl;}
Cat::Cat(const Cat &ref) : Animal("Cat")
{
	*this = ref;
	std::cout << "Cat Copy constructor called for " << YELLOW << _type << RESET << std::endl;
}
Cat &Cat::operator=(const Cat &ref)
{
	_type = ref._type;
	std::cout << "Cat Assignment operator called for " << BLUE << _type << RESET << std::endl;
	return (*this);
}
Cat::~Cat() {std::cout << "Cat Destructor called for " << RED << _type << RESET << std::endl;}

void Cat::makeSound() const {std::cout << "*Meow*" << std::endl;}
std::string Cat::getType() const {return (_type);}