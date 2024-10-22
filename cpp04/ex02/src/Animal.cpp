#include "Animal.hpp"

Animal::Animal() : _type("No Type") {std::cout << "Animal Default constructor called for " << GREEN << _type << RESET << std::endl;}
Animal::Animal(std::string type) : _type(type) {std::cout << "Animal Default constructor called for " << GREEN << _type << RESET << std::endl;}
Animal::Animal(const Animal &ref) : _type(ref._type) {std::cout << "Animal Copy constructor called for " << YELLOW << _type << RESET << std::endl;}
Animal &Animal::operator=(const Animal &ref)
{
	_type = ref._type;
	std::cout << "Animal Assignment operator called for " << BLUE << _type << RESET << std::endl;
	return (*this);
}
Animal::~Animal() {std::cout << "Animal Destructor called for " << RED << _type << RESET << std::endl;}

void Animal::makeSound() const {std::cout << "*Animal Sound*" << std::endl;}
std::string Animal::getType() const {return (_type);}