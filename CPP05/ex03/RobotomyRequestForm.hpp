#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include <string>
#include <iostream>
#include <sys/time.h>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &instance);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
		virtual ~RobotomyRequestForm(void);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif