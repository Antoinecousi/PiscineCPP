/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:51 by acousini          #+#    #+#             */
/*   Updated: 2022/08/10 12:35:06 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

std::string Contact::fields[5] = {
		"First Name",
		"Last Name",
		"Nickname",
		"Phone Number",
		"Darkest secret"
};

std::string		Contact::getValue(int c)
{
	return this->_fields[c];
}

void		Contact::Display(void)
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "- " << this->fields[i] << ": "
				  << this->_fields[i] << std::endl;
	}
}

void	Contact::Add()
{
	int	i = 0;
	
	while (i < 5)
	{
		std::string line = "";
		std::cout << "Enter "  << Contact::fields[i] << " :" << std::endl;
		std::getline (std::cin, line);
		this->_fields[i] = line;
		i++;
	}
	std::cout << "contact added to phonebook." << std::endl;
}