#ifndef HUMANA_HPP
# define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"
class HumanA
{
private:
	std::string name;
	Weapon &WeaponA;
public:
	void attack(void);
	void SetWeapon(Weapon &passed_weapon);
	HumanA(std::string name, Weapon &passed_weapon);
	~HumanA();
};

#endif