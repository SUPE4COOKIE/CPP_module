#include <ctime>
#include <iostream>
#include "Account.hpp"

//int	Account::getNbAccounts(void) {return _nbAccounts;}
//int	Account::getTotalAmount(void) {return _totalAmount;}
//int	Account::getNbDeposits(void) {return _totalNbDeposits;}
//int	Account::getNbWithdrawals(void) {return _totalNbWithdrawals;}

Account::Account(int deposit)
{
	this->_amount = deposit;
}

Account::~Account(void)
{

}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts";
	
}
void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm *local = std::localtime(&t);
	char mbstr[50];

	if (std::strftime(mbstr, 50, "%Y%m%d_%H%M%S", local))
		std::cout << "[" << mbstr << "]" << " ";
}