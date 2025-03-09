#include "Database.hpp"

time_t Database::dateToTimestamp(const std::string date)
{
	struct tm tm;
	strptime(date.c_str(), "%Y-%m-%d", &tm);
	return mktime(&tm);
}

void Database::addPrice(const std::string &date, const double &price)
{
	time_t timestamp = dateToTimestamp(date);

	//if (data.find(timestamp) != data.end())
	//	throw std::runtime_error("duplicate date found");
	data[timestamp] = price;
}

void Database::printData()
{
	for (std::map<time_t, double>::iterator it = data.begin(); it != data.end(); it++)
	{
		std::cout << ctime(&it->first) << " -> " << it->second << std::endl;
	}
}
Database::Database()
{
}

Database::~Database()
{
}