#include "Iter.hpp"
#include <array>

class TestTemplate
{
private:
	int		_i;
public:
	TestTemplate();
	TestTemplate(int i);
	TestTemplate	operator=(const TestTemplate & rhs);
	int		get(void);
	~TestTemplate();
};

TestTemplate::TestTemplate(int i)
{
	_i = i;
}

TestTemplate::~TestTemplate(){}

int		TestTemplate::get()
{
	return (_i);
}

std::ostream & operator<<(std::ostream & o, TestTemplate & rhs)
{
	o << rhs.get();
	return o;
}

template<typename T>
void	print_data(T & array_i)
{
	std::cout << array_i << std::endl;
}

int		main()
{
	int				tint[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	std::string		strs[10] = {"neuf", "huit" , "sept", "six", "cinq", "quatre", "trois", "deux", "un", "zero"};
	TestTemplate	ClassTest[5]= {TestTemplate(9), TestTemplate(99), TestTemplate(5), TestTemplate(2), TestTemplate(4)};
	std::cout << "\t\t TEST FOR INTS \t\t\t\t" << std::endl;
	iter<int>(tint, 10, print_data);
	std::cout << "\t\t TEST FOR STRINGS \t\t\t\t" << std::endl;
	iter<std::string>(strs, 10, print_data);
	std::cout << "\t\t TEST FOR CLASSES \t\t\t\t" << std::endl;
	iter<TestTemplate>(ClassTest, 5, print_data);
}
