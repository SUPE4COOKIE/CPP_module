#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &s) { *this = s; }
Serializer &Serializer::operator=(const Serializer &s) {(void)s; return *this;}

uintptr_t Serializer::serialize(void *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}