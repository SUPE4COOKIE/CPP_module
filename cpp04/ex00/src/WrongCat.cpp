#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {std::cout << "WrongCat Default constructor called for " << GREEN << _type << RESET << std::endl;}
WrongCat::WrongCat(const WrongCat &ref) 
{
	*this = ref;
	std::cout << "WrongCat Copy constructor called for " << YELLOW << _type << RESET << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &ref)
{
	_type = ref._type;
	std::cout << "WrongCat Assignment operator called for " << BLUE << _type << RESET << std::endl;
	return (*this);
}
WrongCat::~WrongCat() {std::cout << "WrongCat Destructor called for " << RED << _type << RESET << std::endl;}

void WrongCat::makeSound() const {std::cout << "*Wrong Meow*" << std::endl;}
std::string WrongCat::getType() const {return (_type);}