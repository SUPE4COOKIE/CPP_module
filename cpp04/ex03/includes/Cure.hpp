#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
class Cure : public AMateria
{
private:
	std::string _type;
public:
	Cure();
	~Cure();
	Cure(const Cure &);
	Cure &operator=(const Cure &);

	Cure *clone() const;
	void use(ICharacter &target);
};

#endif