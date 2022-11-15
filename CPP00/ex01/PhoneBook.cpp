/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:52 by acousini          #+#    #+#             */
/*   Updated: 2022/11/14 15:19:40 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::~PhoneBook(void) {}

PhoneBook::PhoneBook()
{
	_count = 0;
	_reader = 0;
}

void	PhoneBook::addContact(Contact person)
{
	_contacts[_count] = person;
	_count++;
	if (_count == 8)
	{
		_reader = 1;
		_count = 0;
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
	if (_count > 8)
		i = _count - 8;
	Display("Index");
	Display("First Name");
	Display("Last Name");
	Display("Nickname");
	std::cout << std::endl;
	while (i < _count || (_reader == 1 && i < 8))
	{
		c = _contacts[i];
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
		if (_count == 0 && _reader == 0)
		{
			std::cout << "There is no _contacts registered yet. Return to main menu" << std::endl;
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
		if (_reader == 0 && (result < 0 || result >= _count))
			std::cout << "Index has to be between 0 and " << _count - 1 << std::endl;
		else if (_reader == 1 && (result < 0 || result > 7))
			std::cout << "Index has to be between 0 and 7" << std::endl;
		else
		{
			_contacts[result].Display();
			break;
		}
	}
}