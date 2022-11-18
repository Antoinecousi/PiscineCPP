#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon_form", 5, 25), _target("Random Target")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardon_form", 5, 25), _target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance)
{
	*this = instance;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if ( this != &rhs )
	{
		if (rhs.get_signed() == "yes")
			this->setSigned();
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (get_signed() == "no")
		throw IsNotSigned();
	if (executor.getGrade() > this->get_grade_exec())
		throw GradeTooHighException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}