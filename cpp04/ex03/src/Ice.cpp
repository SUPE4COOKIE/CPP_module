#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice &) {}
Ice::~Ice() {}
Ice &Ice::operator=(const Ice &) {return *this;}
Ice *Ice::clone() const {return new Ice(*this);}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}