#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <iostream>
#include <ctime>
#include <map>

class Database
{
private:
	
public:
	time_t oldest_value;
	time_t newest_value;
	Database();
	~Database();
	std::map<time_t, double> data;
};

Database::Database()
{
}

Database::~Database()
{
}

#endif