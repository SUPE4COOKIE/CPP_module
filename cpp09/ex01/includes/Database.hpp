#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <iostream>
#include <ctime>
#include <map>

class Database
{
private:
	std::map<time_t, double> data;

	time_t dateToTimestamp(const std::string date);

public:
	Database();
	~Database();
	
	void addPrice(const std::string &date, const double &price);
	double getPrice(const std::string &date);
	void printData();
};

#endif
