#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _atk;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &);

	std::string GetName() const;
	unsigned int GetHp() const;
	unsigned int GetEp() const;
	unsigned int GetAtk() const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif