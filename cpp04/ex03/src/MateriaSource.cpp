#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
};
MateriaSource::MateriaSource(const MateriaSource &ref)
{*this = ref;}
MateriaSource &MateriaSource::operator=(const MateriaSource &ref)
{
	this->_materias[0] = ref._materias[0];
	this->_materias[1] = ref._materias[1];
	this->_materias[2] = ref._materias[2];
	this->_materias[3] = ref._materias[3];
	return *this;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
};
void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = materia;
			break;
		}
	}
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	}
	return NULL;
}
