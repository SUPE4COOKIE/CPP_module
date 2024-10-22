#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "ICharacter.hpp"
class Ice
{
private:
	std::string _type;
public:
	Ice();
	~Ice();
	Ice(const Ice &);
	Ice &operator=(const Ice &);
	Ice *clone() const;
	void use(ICharacter &target);
};
#endif
