#ifndef INTERN_HPP
# define INTERN_HPP
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include "Form.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &instance);
		Intern &operator=(Intern const &rhs);
		~Intern(void);
		Form 	*makeForm(std::string nameForm, std::string target);

		class FormInexistant : public std::exception
		{
			public :
				virtual const char *what() const throw(){
					return ("This form doesn't exist");
				}
		};

	private:	
		Form *			Presidential( std::string target );
		Form *			Robotomy( std::string target );
		Form *			Shrubbery( std::string target );

};

#endif