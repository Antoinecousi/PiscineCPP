#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include "Form.hpp"
#include <string>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat		(void);
		Bureaucrat		(std::string name, int grade);
		Bureaucrat		(Bureaucrat const &instance);
		~Bureaucrat		(void);

		Bureaucrat 		&operator=(Bureaucrat const &rhs);

		void			increaseGrade();
		void			decreaseGrade();
		std::string		getName() const; 
		int			 	getGrade() const;
		void			signForm(Form &formulaire);

	private:
		int					_grade;
		const std::string	_name;
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

std::ostream 	& operator<<(std::ostream & o, Bureaucrat const &rhs);

#endif