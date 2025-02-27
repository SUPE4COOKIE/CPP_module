#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string name);
	~Weapon();
	const std::string& GetType();
	void setType(std::string type);
};
#endif
