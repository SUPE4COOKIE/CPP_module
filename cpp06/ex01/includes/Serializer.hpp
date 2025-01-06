#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &s);
	Serializer &operator=(const Serializer &s);
	~Serializer();
public:
	static uintptr_t serialize(void *ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif