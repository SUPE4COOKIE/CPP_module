#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure &ref) : AMateria(ref.getType()) {}
Cure::~Cure() {}
Cure &Cure::operator=(const Cure &ref)
{
	this->_type = ref.getType();
	return *this;
}
Cure *Cure::clone() const {return new Cure(*this);}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}