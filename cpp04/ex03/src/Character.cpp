#include "Character.hpp"

Character::Character() : _name("No name")
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(const Character &ref) {*this = ref;}

Character &Character::operator=(const Character &ref)
{
	this->_name = ref._name;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = ref._materias[i];
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	for (size_t i = 0; i < this->_groundItems.getSize(); i++)
		delete this->_groundItems[i];
}

std::string const &Character::getName() const { return this->_name; }

void Character::equip(AMateria *mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = mat;
			std::cout << this->_name << " equiped " << mat->getType() << std::endl;
			return;
		}
	}
	this->_groundItems.add(mat);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_materias[idx] == NULL)
	{
		std::cout << this->_name << " no materia at index " << idx << std::endl;
		return;
	}
	std::cout << this->_name << " unequiped " << this->_materias[idx]->getType() << std::endl;
	this->_groundItems.add(this->_materias[idx]);
	this->_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || this->_materias[idx] == NULL)
	{
		std::cout << target.getName() << " no materia at index " << idx << std::endl;
		return;
	}
	this->_materias[idx]->use(target);
}

AMateria *Character::getMateria(int idx)
{
	if (idx < 0 || idx > 3)
		return NULL;
	return this->_materias[idx];
}