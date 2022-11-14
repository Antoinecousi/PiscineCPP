#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "\n\n\n\n\n\n";
	{
		try
		{
			Form f("Form", -1, 344);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form f("Form2", -1, 14);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	
	Bureaucrat Britney("Britney", 50);
	Form	f("formulaire", 49, 50);
	Form	visa("visa", 49, 49);
	std::cout << Britney << std::endl;

	std::cout << f << std::endl;
	Britney.signForm(f);
	std::cout << f << std::endl;
	

	std::cout << visa << std::endl;
	Britney.signForm(visa);
	std::cout << visa << std::endl;


	std::cout << "\n\n\n\n\n\n";
	return (0);
}