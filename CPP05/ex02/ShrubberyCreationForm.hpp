#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include <string>
#include <fstream>
#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &instance);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
		virtual ~ShrubberyCreationForm(void);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;

};

#endif