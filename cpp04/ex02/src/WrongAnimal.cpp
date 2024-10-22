#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("No Type") {std::cout << "Wrong Animal Default constructor called for " << GREEN << _type << RESET << std::endl;}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {std::cout << "Wrong Animal Default constructor called for " << GREEN << _type << RESET << std::endl;}
WrongAnimal::WrongAnimal(const WrongAnimal &ref) : _type(ref._type) {std::cout << "Wrong Animal Copy constructor called for " << YELLOW << _type << RESET << std::endl;}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref)
{
	_type = ref._type;
	std::cout << "Wrong Animal Assignment operator called for " << BLUE << _type << RESET << std::endl;
	return (*this);
}
WrongAnimal::~WrongAnimal() {std::cout << "Wrong Animal Destructor called for " << RED << _type << RESET << std::endl;}

void WrongAnimal::makeSound() const {std::cout << "*Wrong Animal Sound*" << std::endl;}
std::string WrongAnimal::getType() const {return (_type);}