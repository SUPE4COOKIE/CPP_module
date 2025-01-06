#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {}
Base::~Base() {}
Base::Base(const Base &copy) { *this = copy; }
Base &Base::operator=(const Base &copy) { (void)copy; return *this; }

Base *Base::generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
	case (0):
		return new A;
	case (1):
		return new B;
	default:
		return new C;
	}
}

void Base::identify(Base *p)
{
	try
	{
		if (dynamic_cast<A*>(p))
			std::cout << "class is of type A" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "class is of type B" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "class is of type C" << std::endl;
		else
			std::cout << "class is of unknown type" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}
void Base::identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "class is of type A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "class is of type B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "class is of type C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
	}
}