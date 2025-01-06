#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
public:
	Base();
	Base(const Base &copy);
	Base &operator=(const Base &copy);
	virtual ~Base();

	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

#endif