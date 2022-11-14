#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

int main(void)
{
	ShrubberyCreationForm lol;
	Bureaucrat Jean("jean", 1);
	Jean.signForm(lol);
	lol.execute(Jean);
}