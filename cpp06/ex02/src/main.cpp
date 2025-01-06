#include "Base.hpp"

int main()
{
	Base b;
	srand(time(NULL));
	Base *letter = b.generate();
	b.identify(letter);

	Base &letterref = *letter;
	b.identify(letterref);
	delete letter;
	return 0;
}