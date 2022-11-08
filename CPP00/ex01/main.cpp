/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:52 by acousini          #+#    #+#             */
/*   Updated: 2022/08/10 11:53:29 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int		main()
{
	PhoneBook repertoire;
	std::string line;
	while (1)
	{
		std::cout << "To start, write \"ADD\" \"SEARCH\" or \"EXIT\"" << std::endl;
		std::getline (std::cin,line);
		if (line.compare("ADD") == 0)
		{
			Contact c;
			c.Add();
			repertoire.addContact(c);
		}
		else if (line.compare("SEARCH") == 0)
		{
			repertoire.List();
			repertoire.getContact();
		}
		else if (line.compare("EXIT") == 0)
			exit(0);
		else
			std::cout << "Input doesn't match any of the 3 commands available" << std::endl;
	}
}