#include "DynamicArr.hpp"

DynamicArr::DynamicArr() : _materias(new AMateria*[2]), _size(0), _capacity(0) {}
DynamicArr::~DynamicArr()
{
	for (size_t i = 0; i < this->_size; i++)
		delete this->_materias[i];
	delete[] this->_materias;
}
void DynamicArr::resize()
{
	AMateria **tmp = new AMateria*[this->_capacity * 2];
	for (size_t i = 0; i < this->_size; i++)
		tmp[i] = this->_materias[i];
	delete[] this->_materias;
	this->_materias = tmp;
	this->_capacity *= 2;
}

void DynamicArr::add(AMateria *m)
{
	if (this->_size == this->_capacity)
		this->resize();
	this->_materias[this->_size++] = m;
}
const DynamicArr &DynamicArr::operator=(const DynamicArr &ref)
{
	this->_size = ref._size;
	this->_capacity = ref._capacity;
	this->_materias = new AMateria*[this->_capacity];
	for (size_t i = 0; i < this->_size; i++)
		this->_materias[i] = ref._materias[i];
	return *this;
}

const AMateria *DynamicArr::operator[](size_t idx) const
{
	if (idx < 0 || idx >= this->_size)
		return NULL;
	return this->_materias[idx];
}