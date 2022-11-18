#include "Intern.hpp"

Intern::Intern(void)
{
	
}

Intern::Intern(Intern const &instance)
{
	
}

Intern::~Intern(void)
{
	
}

Intern &	Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

Form 	*	Intern::makeForm(std::string nameForm, std::string target)
{
	std::string		matched[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form			*(Intern::*function[3])(std::string target) = {&Intern::Robotomy, &Intern::Presidential, &Intern::Shrubbery};

	for (int i = 0 ; i < 3 ; i++)
	{
		if (nameForm == matched[i])
			return ((this->*function[i])(target));
	}
	std::cout << "This form doesn't exist." << std::endl;
	return (NULL);
}

Form *			Intern::Presidential( std::string target ){
	return (new PresidentialPardonForm(target));
}

Form *			Intern::Robotomy( std::string target ){
	return (new RobotomyRequestForm(target));
}

Form *			Intern::Shrubbery( std::string target ){
	return (new ShrubberyCreationForm(target));
}