#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {std::cout << "Dog Default constructor called for " << GREEN << _type << RESET << std::endl;}
Dog::Dog(const Dog &ref) : Animal("Dog")
{
	*this = ref;
	std::cout << "Dog Copy constructor called for " << YELLOW << _type << RESET << std::endl;
}
Dog &Dog::operator=(const Dog &ref)
{
	_type = ref._type;
	std::cout << "Dog Assignment operator called for " << BLUE << _type << RESET << std::endl;
	return (*this);
}
Dog::~Dog() {std::cout << "Dog Destructor called for " << RED << _type << RESET << std::endl;}

void Dog::makeSound() const {std::cout << "*Woof*" << std::endl;}
std::string Dog::getType() const {return (_type);}