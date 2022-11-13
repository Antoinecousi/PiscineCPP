#ifndef FORM_HPP
# define FORM_HPP
#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
	public:
		Form(void);
		Form(std::string name, int grade_exec, int grade_sign);
		Form(Form const &instance);
		~Form(void);

		Form &operator=(Form const &rhs);
		void	beSigned(Bureaucrat &rhs);
		int			get_grade_sign() const ;
		int			get_grade_exec() const ;
		std::string	get_name() const ;
		std::string	get_signed() const ;


	private:
		std::string	_name;
		bool				_signature;
		int					_grade_sign;
		int					_grade_exec;
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("The grade is too high");
			}
	};
	
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("The grade is too low");
			}
	};
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif