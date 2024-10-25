#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice &ref) : AMateria(ref.getType()) {}
Ice::~Ice() {}
Ice &Ice::operator=(const Ice &ref)
{
	this->_type = ref.getType();
	return *this;
}
Ice *Ice::clone() const {return new Ice(*this);}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}