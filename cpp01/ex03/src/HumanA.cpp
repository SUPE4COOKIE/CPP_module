#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->WeaponA.GetType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &passed_weapon)
	: name(name), WeaponA(passed_weapon) {}
HumanA::~HumanA() {}
void HumanA::SetWeapon(Weapon &passed_weapon) {this->WeaponA = passed_weapon;}