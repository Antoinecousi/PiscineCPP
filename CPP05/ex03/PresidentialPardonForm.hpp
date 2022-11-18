#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include <string>
#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &instance);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
		virtual ~PresidentialPardonForm(void);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif