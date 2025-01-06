#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data quarantedeux;
	Data quarantetrois;

	quarantedeux.i = 42;
	quarantedeux.c = '*';

	quarantetrois.i = 43;
	quarantetrois.c = '+';

	uintptr_t a = Serializer::serialize(&quarantedeux);
	std::cout << "quarante deux : " << a << std::endl;

	uintptr_t b = Serializer::serialize(&quarantetrois);
	std::cout << "quarante trois : " << b << std::endl;

	Data *c = Serializer::deserialize(a);
	std::cout << "quarante deux : " << c->i << " " << c->c << std::endl;

	Data *d = Serializer::deserialize(b);
	std::cout << "quarante trois : " << d->i << " " << d->c << std::endl;	
}