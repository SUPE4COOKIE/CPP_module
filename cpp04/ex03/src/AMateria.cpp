#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {}
AMateria::AMateria() : _type("No name") {}
AMateria::AMateria(const AMateria &ref) : _type(ref._type) {}
AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &ref)
{
	this->_type = ref._type;
	return *this;
}
std::string const &AMateria::getType() const { return this->_type; }