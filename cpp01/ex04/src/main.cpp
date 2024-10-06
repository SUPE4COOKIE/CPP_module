#include <iostream>
#include <string>
#include <fstream>

int check_error(int ac, std::string infile_name)
{
	if (ac != 4)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return 1;
	}
	if (infile_name.empty())
	{
		std::cerr << "string to replace cannot be empty" << std::endl;
		return 1;
	}
	return 0;
}

std::string replace_line(std::string line, std::string s1, std::string s2)
{
	size_t start;
	size_t end = 0;
	std::string replaced_line;

	while ((start = line.find(s1, end)) != std::string::npos)
	{
		replaced_line += line.substr(end, start - end) + s2;
		end = start + s1.length();
	}
	replaced_line += line.substr(end);
	return replaced_line;
}

void file_rewrite(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string line;

	while (std::getline(infile, line))
	{
		outfile << replace_line(line, s1, s2) << "\n";
	}
}

int main(int ac, char **av)
{
	std::string infile_name = av[1];

	if (check_error(ac, infile_name))
		return 1;
	std::ifstream infile(av[1]);
	if (!infile)
	{
		std::cerr << "could not open file" << std::endl;
		return 1;
	}
	std::ofstream outfile((infile_name + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "could not open file" << std::endl;
		return 1;
	}
	file_rewrite(infile, outfile, av[2], av[3]);
	infile.close();
	outfile.close();
	return 0;
}