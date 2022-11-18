#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include <time.h>
#include <sys/time.h>
#include <chrono>

int main(void)
{

	std::cout << "======== TEST 1 ========= \n\n\n\n\n\n" << std::endl;
	
 	struct timeval tp;

	gettimeofday(&tp, NULL);
	Form *Formulaires[3];
	Formulaires[0] = new ShrubberyCreationForm();
	Formulaires[1] = new RobotomyRequestForm();
	Formulaires[2] = new PresidentialPardonForm();
	Bureaucrat Jean("jean", 1);
	Jean.signForm(*Formulaires[0]);
	Jean.signForm(*Formulaires[1]);
	Jean.signForm(*Formulaires[2]);
	Jean.executeForm(*Formulaires[0]);
	Jean.executeForm(*Formulaires[1]);
	Jean.executeForm(*Formulaires[2]);
	for (int i = 0 ; i < 146 ; i++)
		Jean.decreaseGrade();
	Jean.executeForm(*Formulaires[0]);
	Jean.executeForm(*Formulaires[1]);
	Jean.executeForm(*Formulaires[2]);
	delete Formulaires[2];
	Formulaires[2] = new PresidentialPardonForm();
	Jean.executeForm(*Formulaires[2]);
	delete Formulaires[0];
	delete Formulaires[1];
	delete Formulaires[2];

	std::cout << "======== TEST 2 ========= \n\n\n\n\n\n" << std::endl;
	
	Intern Pierre;
	Form *scnd_formulaires[4];
	scnd_formulaires[0] = Pierre.makeForm("robotomy request", "Jardin");
	scnd_formulaires[1] = Pierre.makeForm("shrubbery creation", "Jardin");
	scnd_formulaires[2] = Pierre.makeForm("presidential pardon", "Jardin");
	scnd_formulaires[3] = Pierre.makeForm("ne marchera pas", "Jardin");
	Jean.executeForm(*scnd_formulaires[0]);
	Jean.executeForm(*scnd_formulaires[1]);
	Jean.executeForm(*scnd_formulaires[2]);
	delete scnd_formulaires[0];
	delete scnd_formulaires[1];
	delete scnd_formulaires[2];
	delete scnd_formulaires[3];
}