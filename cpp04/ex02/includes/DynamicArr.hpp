#ifndef DYNAMIC_ARR
# define DYNAMIC_ARR
# include <iostream>
# include "AMateria.hpp"
class DynamicArr
{
private:
	AMateria *_materias[];

public:
	DynamicArr();
	~DynamicArr();
};

#endif