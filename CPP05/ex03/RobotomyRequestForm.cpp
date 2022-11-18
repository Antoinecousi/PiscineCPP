#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequest_form", 45, 72), _target("Random Target")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequest_form", 45, 72), _target(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &instance)
{
	*this = instance;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if ( this != &rhs )
	{
		if (rhs.get_signed() == "yes")
			this->setSigned();
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	if (get_signed() == "no")
		throw IsNotSigned();
	if (executor.getGrade() > this->get_grade_exec())
		throw GradeTooHighException();
	std::cout << "BzZZzzZZZzzZzZzZzzzZzzZzZZZzzZzZZzZzZzZzZZZZZZzzzzZZZZZ" << std::endl;
	if (tp.tv_usec % 2 == 0)
	{
		std::cout << this->_target << " has been robotomized." << std::endl;
	}
	else
		std::cout << "Operation failed." << std::endl;
}