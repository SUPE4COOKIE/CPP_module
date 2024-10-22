#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain), _sound("*Meow*") {std::cout << "Cat Default constructor called for " << GREEN << _type << RESET << std::endl;}
Cat::Cat(const Cat &ref) : Animal("Cat"), _sound("*Meow*")
{
	*this = ref;
	std::cout << "Cat Copy constructor called for " << YELLOW << _type << RESET << std::endl;
}
Cat &Cat::operator=(const Cat &ref)
{
	_type = ref._type;
	_sound = ref._sound;
	_brain = new Brain(*ref._brain);
	std::cout << "Cat Assignment operator called for " << BLUE << _type << RESET << std::endl;
	return (*this);
}
Cat::~Cat() 
{
	std::cout << "Cat Destructor called for " << RED << _type << RESET << std::endl;
	delete _brain;
}

void Cat::makeSound() const {std::cout << _sound << std::endl;}
void Cat::setSound(std::string sound) {_sound = sound;}
std::string Cat::getType() const {return (_type);}