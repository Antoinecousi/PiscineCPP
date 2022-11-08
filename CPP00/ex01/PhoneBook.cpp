/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:52 by acousini          #+#    #+#             */
/*   Updated: 2022/08/10 18:48:46 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::~PhoneBook(void) {}

PhoneBook::PhoneBook()
{
	this->count = 0;
	this->reader = 0;
}

void	PhoneBook::addContact(Contact person)
{
	contacts[this->count] = person;
	this->count++;
	if (this->count == 8)
	{
		this->reader = 1;
		this->count = 0;
	}
}

void	Display(std::string str)
{
	if (str.size() > 10) {
		std::string print = str.substr(0, 9);
		std::cout << print << '.';
	}
	else
	{
		std::cout.fill(' ');
		std::cout.width(10);
		std::cout << std::right << str;
	}
	std::cout << '|';
}

void	PhoneBook::List()
{
	int		i;
	Contact	c;
	
	i = 0;
	if (this->count > 8)
		i = this->count - 8;
	Display("Index");
	Display("First Name");
	Display("Last Name");
	Display("Nickname");
	std::cout << std::endl;
	while (i < this->count || (this->reader == 1 && i < 8))
	{
		c = this->contacts[i];
		Display(std::to_string(i));
		Display(c.getValue(0));
		Display(c.getValue(1));
		Display(c.getValue(2));
		std::cout << '\n';
		i++;
	}
	std::cout.fill('-'); 
	std::cout.width(44);
	std::cout << '\n';
}

void	PhoneBook::getContact()
{
	std::string line = "";
	int result = -1;
	while (1)
	{
		if (this->count == 0 && this->reader == 0)
		{
			std::cout << "There is no contacts registered yet. Return to main menu" << std::endl;
			break;
		}
		std::cout << "Enter an index you want to display" << '\n';
		std::getline (std::cin, line);
		if (!std::cin.good())
			exit(0);
		result = std::atoi(line.c_str());
		if (result == 0 && line.compare("0") != 0)
		{
			std::cout << "Error: index must be a number" << std::endl;
			continue ;
		}
		if (this->reader == 0 && (result < 0 || result >= this->count))
			std::cout << "Index has to be between 0 and " << this->count - 1 << std::endl;
		else if (this->reader == 1 && (result < 0 || result > 7))
			std::cout << "Index has to be between 0 and 7" << std::endl;
		else
		{
			contacts[result].Display();
			break;
		}
	}
}