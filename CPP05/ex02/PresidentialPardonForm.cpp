#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon_form", 5, 25), _target("Random Target")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardon_form", 5, 25), _target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	
}