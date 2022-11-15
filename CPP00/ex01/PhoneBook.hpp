/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:53 by acousini          #+#    #+#             */
/*   Updated: 2022/11/14 15:19:06 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {

private:
    Contact _contacts[8];
	int		_count;
	int		_reader;

public:
    PhoneBook();
    ~PhoneBook();

	void	getContact();
	void	addContact(Contact c);
	void	List(void);
	int		Count(void);
};

#endif
