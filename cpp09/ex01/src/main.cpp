// parse dates and store them as unix timestamps
// in a map<time_t, double>
// parse the input file and convert the date to a unix timestamp
// get the closest unix timestamp from the map and multiply the value

#define INPUT_FILE "data.csv"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Database.hpp"

double convertDouble(std::string str)
{
	double result;
	char *endptr;

	result = std::strtod(str.c_str(), &endptr);
	if (errno == ERANGE)
		throw std::invalid_argument("invalid value");
	else if (errno == EINVAL || (*endptr != 0))
		throw std::invalid_argument("invalid value");
	return result;
}

bool check_date(std::pair<std::string, std::string> p)
{
	for (size_t i = 0; i < p.first.size(); i++)
	{
		if ((p.first[i] < '0' || p.first[i] > '9') && p.first[i] != '-')
		{
			return false;
		}
	}
	return true;
}

void parseInputFile(Database &db)
{
	std::ifstream file(INPUT_FILE);
	std::string line;
	std::pair<std::string, std::string> date_exchange_rate;
	char date_order;

	std::getline(file, line, ',');
	if (line == "date")
	{
		std::getline(file, line, '\n');
		if (line != "exchange_rate")
			throw std::runtime_error("invalid file format");
		date_order = 0;
	}
	else if (line == "exchange_rate")
	{
		std::getline(file, line, '\n');
		if (line != "date")
			throw std::runtime_error("invalid file format");
		date_order = 1;
	}
	else
		throw std::runtime_error("invalid file format");

	while (std::getline(file, line, ','))
	{
		if (date_order == 0)
		{
			date_exchange_rate.first = line;
			std::getline(file, line, '\n');
			date_exchange_rate.second = line;
		}
		else
		{
			date_exchange_rate.second = line;
			std::getline(file, line, '\n');
			date_exchange_rate.first = line;
		}
		if (!check_date(date_exchange_rate))
		{
			std::cout << date_exchange_rate.first << std::endl;
			throw std::runtime_error("invalid date format");
		}
		db.addPrice(date_exchange_rate.first, convertDouble(date_exchange_rate.second));
	}
	file.close();
}
int main()
{
	Database db;
	try
	{
		parseInputFile(db);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	db.printData();
	return 0;
}