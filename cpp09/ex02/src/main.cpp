#include <iostream>
#include <stack>

bool is_valid(char c)
{
	return (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == ' ';
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return 1;
	}

	std::stack <int> stack;

	for (size_t i = 0; argv[1][i]; i++)
	{
		if (!is_valid(argv[1][i]))
		{
			std::cerr << "Error: invalid character '" << argv[1][i] << "'" << std::endl;
			return 1;
		}
		if (argv[1][i] == ' ')
			continue;
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			stack.push(argv[1][i] - '0');
			continue;
		}
		if (stack.size() < 2)
		{
			std::cerr << "Error: not enough operands" << std::endl;
			return 1;
		}
		int b = stack.top();
		stack.pop();
		int a = stack.top();
		stack.pop();
		if (argv[1][i] == '+')
			stack.push(a + b);
		else if (argv[1][i] == '-')
			stack.push(a - b);
		else if (argv[1][i] == '*')
			stack.push(a * b);
		else if (argv[1][i] == '/')
		{
			if (b == 0)
			{
				std::cerr << "Error: division by zero" << std::endl;
				return 1;
			}
			stack.push(a / b);
		}
		else
		{
			std::cerr << "Error: invalid character '" << argv[1][i] << "'" << std::endl;
			return 1;
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error: not enough operators" << std::endl;
		return 1;
	}
	std::cout << stack.top() << std::endl;
}