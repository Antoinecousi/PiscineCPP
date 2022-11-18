#ifndef FORM_HPP
# define FORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, int grade_exec, int grade_sign);
		Form(Form const &instance);
		virtual ~Form(void);

		Form &		operator=(Form const &rhs);
		void		beSigned(Bureaucrat &rhs);
		int			get_grade_sign() const ;
		int			get_grade_exec() const ;
		std::string	get_name() const ;
		std::string	get_signed() const ;
		void		setSigned(void);

		virtual void	execute(Bureaucrat const & executor) const = 0;
  
	class GradeTooHighException: public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Form grade is too high");
		}
	};
	
	class GradeTooLowException: public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Form grade is too low");
		}
	};
	class IsNotSigned: public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Form is not signed");
		}
	};
	private:
		std::string			_name;
		bool				_signature;
		int					_grade_sign;
		int					_grade_exec;

	
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif