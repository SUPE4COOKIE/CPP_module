#ifndef DYNAMICARR_HPP
# define DYNAMICARR_HPP
# include "AMateria.hpp"
class DynamicArr
{
private:
	AMateria	**_materias;
	size_t		_size;
	size_t		_capacity;
	void		resize();
public:
	DynamicArr();
	~DynamicArr();
	const DynamicArr &operator=(const DynamicArr &ref);
	const AMateria *operator[](size_t idx) const;
	void add(AMateria *m);
	size_t getSize() const;
};

#endif