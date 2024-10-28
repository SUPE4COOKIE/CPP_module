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

void replaceSubstring(std::string &str, const std::string &s1, const std::string &s2) {
	size_t pos = str.find(s1);
	while (pos != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos = str.find(s1, pos + s2.length());
	}
}

void file_rewrite(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string line;
	std::string file_content;

	while (std::getline(infile, line))
		file_content += line + "\n";
	replaceSubstring(file_content, s1, s2);
	outfile << file_content;
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