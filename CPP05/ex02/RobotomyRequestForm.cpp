#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequest_form", 45, 72), _target("Random Target")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequest_form", 45, 72), _target(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &instance)
{
	
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	
}