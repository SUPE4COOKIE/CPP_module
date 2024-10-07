#include "HumanB.hpp"

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->WeaponB->GetType() << std::endl;
}
void HumanB::setWeapon(Weapon &passed_weapon) {this->WeaponB = &passed_weapon;}
HumanB::HumanB(std::string name) : name(name), WeaponB(NULL) {}
HumanB::~HumanB() {}