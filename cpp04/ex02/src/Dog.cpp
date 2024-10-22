#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain), _sound("*Woof*") {std::cout << "Dog Default constructor called for " << GREEN << _type << RESET << std::endl;}
Dog::Dog(const Dog &ref) : Animal("Dog"), _sound("*Woof*")
{
	*this = ref;
	std::cout << "Dog Copy constructor called for " << YELLOW << _type << RESET << std::endl;
}
Dog &Dog::operator=(const Dog &ref)
{
	_type = ref._type;
	_sound = ref._sound;
	_brain = new Brain(*ref._brain);
	std::cout << "Dog Assignment operator called for " << BLUE << _type << RESET << std::endl;
	return (*this);
}
Dog::~Dog()
{
	std::cout << "Dog Destructor called for " << RED << _type << RESET << std::endl;
	delete _brain;
}

void Dog::setSound(std::string sound) {_sound = sound;}
void Dog::makeSound() const {std::cout << _sound << std::endl;}
std::string Dog::getType() const {return (_type);}