#include "Form.hpp"

Form::Form(void) : _name("default"), _grade_exec(150), _grade_sign(150), _signature(false)
{
	std::cout << "Form \"" << _name << "\" CONSTRUCTOR" << std::endl;
}

Form::Form(std::string name, int grade_exec, int grade_sign) : _name(name),
				_grade_exec(grade_exec), _grade_sign(grade_sign), _signature(false)
{
	if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form \"" << _name << "\" CONSTRUCTOR" << std::endl;
}

Form::Form(Form const &instance)
{
	*this = instance;
}

Form::~Form(void)
{
	std::cout << "Form \"" << _name << "\" DESTRUCTOR" << std::endl;
}

Form &	Form::operator=(Form const &rhs)
{
	this->_grade_exec = rhs._grade_exec;
	this->_grade_sign = rhs._grade_sign;
	this->_signature = rhs._signature;
	this->_name = rhs._name;
	return (*this);
}

void	Form::beSigned(Bureaucrat &rhs)
{
	if (rhs.getGrade() > this->get_grade_sign())
		throw Form::GradeTooHighException();
	else
		this->_signature = true;
}

int		Form::get_grade_sign() const
{
	return _grade_sign;
}

int		Form::get_grade_exec() const
{
	return _grade_exec;
}

std::string		Form::get_name() const
{
	return _name;
}

std::string		Form::get_signed() const
{
	if (_signature == false)
		return ("no");
	else
		return "yes";
}

std::ostream	&	operator<<(std::ostream &o, Form const &rhs)
{
	o << std::endl << rhs.get_name() << " form. Exec = " << rhs.get_grade_exec() << " Sign = " << rhs.get_grade_sign() << " is signed : " << rhs.get_signed() << std::endl;
	return (o);
}