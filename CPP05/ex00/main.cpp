#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat John;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat William("William", 145);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat Peter("Peter", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}	
		try
		{
			Bureaucrat Christian("Christian", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat Johnny("Johnny", 5);
			std::cout << Johnny << std::endl;
			for (int i = 0; i < 8; i++)
			{
				Johnny.increaseGrade();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat Mary("Mary", 145);
			for (int i = 0; i < 3; i++)
			{
				Mary.decreaseGrade();
			}
			std::cout << Mary << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}