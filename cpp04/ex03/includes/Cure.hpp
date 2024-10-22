#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "ICharacter.hpp"
class Cure
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