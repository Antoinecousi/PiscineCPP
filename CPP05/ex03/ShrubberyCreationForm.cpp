#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery_Form", 137, 145), _target("Random Target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery_Form", 137, 145), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &instance)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if ( this != &rhs )
	{
		if (rhs.get_signed() == "yes")
			this->setSigned();
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (get_signed() == "no")
		throw IsNotSigned();
	if (executor.getGrade() > this->get_grade_exec())
		throw GradeTooHighException();
	std::ofstream ofs((_target + "_shrubbery") , std::ofstream::trunc);
	ofs << "         &&& &&  & &&  "<< std::endl <<
"      && &\/&\|& ()|/ @, && "<< std::endl <<
"      &\/(/&/&||/& /_/)_&/_& "<< std::endl <<
"   &() &\/&|()|/&\/ '% & () "<< std::endl <<
"  &_\_&&_\ |& |&&/&__%_/_& && "<< std::endl <<
"&&   && & &| &| /& & % ()& /&& "<< std::endl <<
" ()&_---()&\&\|&&-&&--%---()~ "<< std::endl <<
"     &&     \||| "<< std::endl <<
"             ||| "<< std::endl <<
"             ||| "<< std::endl <<
"             ||| "<< std::endl <<
"       , -=-~  .-^- _"<< std::endl;
	ofs.close();
}