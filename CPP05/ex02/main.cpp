#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <time.h>
#include <sys/time.h>
#include <chrono>

int main(void)
{
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
}