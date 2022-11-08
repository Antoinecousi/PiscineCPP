/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:53 by acousini          #+#    #+#             */
/*   Updated: 2022/08/10 18:43:59 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {

private:
    Contact contacts[8];
	int		count;
	int		reader;

public:
    PhoneBook();
    ~PhoneBook();

	void	getContact();
	void	addContact(Contact c);
	void	List(void);
	int		Count(void);
};

#endif
