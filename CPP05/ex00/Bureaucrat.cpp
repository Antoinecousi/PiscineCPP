#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _grade(150) , _name("Unknown")
{
	std::cout << _name << " bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << _name << " bureaucrat constructor" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &instance)
{
	*this = instance;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << _name << " bureaucrat destructor" << std::endl;	
}

Bureaucrat 		&	Bureaucrat::operator=(Bureaucrat const &rhs)
{
	
}

std::ostream 	& operator<<(std::ostream & o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

void	Bureaucrat::increaseGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	_grade++;
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int			Bureaucrat::getGrade() const
{
	return _grade;
}

void		Bureaucrat::signForm(Form &formulaire)
{
	try
	{
		formulaire->beSigned(this);
		std::cout << _name << " signed " << formulaire->getName();
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << formulaire->getName() << " because " << e.what() << std::endl;
	}
	
}