#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>

# define WHITESPACE " \t\n\r\v\f"

class RPN
{
	public:
		RPN(void);
		RPN(std::string input);
		RPN(RPN const &instance);
		RPN &operator=(RPN const &rhs);
		~RPN(void);

	private:
		std::stack<std::string>		_calculator;

};

#endif