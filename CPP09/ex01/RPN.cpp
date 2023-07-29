#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(std::string input)
{
	int		i = 0;
	int		result;
	int		a;
	int		b;

	while (input[i])
	{
		while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\r' || input[i] == '\v' || input[i] == '\f')
			i++;
		if (input[i] >= '0' && input[i] <= '9')
			_calculator.push(&input[i++]);
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if (_calculator.size() < 2)
			{
				std::cout << "Error" << std::endl;
				return ;
			}
			a = std::stoi(_calculator.top());
			_calculator.pop();
			b = std::stoi(_calculator.top());
			_calculator.pop();
			if (input[i] == '+')
				result = b + a;
			else if (input[i] == '-')
				result = b - a;
			else if (input[i] == '*')
				result = b * a;
			else if (input[i] == '/')
			{
				if (a == 0)
				{
					std::cout << "Error: cannot divide by '0'" << std::endl;
					return ;
				}
				result = b / a;
			}
			_calculator.push(std::to_string(result));
			i++;
		}
		if (!(input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\r' ||
				input[i] == '\v' || input[i] == '\f' || input[i] == '\0'))
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if (_calculator.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	std::cout << _calculator.top() << std::endl;
}

RPN::RPN(RPN const &instance)
{
}

RPN::~RPN(void)
{
	while (!_calculator.empty())
	{
		_calculator.pop();
	}
}

RPN &	RPN::operator=(RPN const &rhs)
{
	_calculator = rhs._calculator;
	return (*this);
}