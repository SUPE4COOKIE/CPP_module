#ifndef HUMANB_HPP
# define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"
class HumanB
{
private:
	std::string name;
	Weapon *WeaponB;
public:
	void attack(void);
	void setWeapon(Weapon &passed_weapon);
	HumanB(std::string name);
	~HumanB();
};

#endif