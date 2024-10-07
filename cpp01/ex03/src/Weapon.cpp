#include "Weapon.hpp"

const std::string& Weapon::GetType() {return (this->type);}
void Weapon::setType(std::string type) {this->type = type;}
Weapon::Weapon(std::string name) : type(name) {}
Weapon::~Weapon() {}