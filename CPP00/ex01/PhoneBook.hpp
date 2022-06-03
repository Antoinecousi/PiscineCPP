/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:53 by acousini          #+#    #+#             */
/*   Updated: 2022/06/03 17:15:30 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

class PhoneBook {
    
private:

    
public:
    Contact contacts[8];

    PhoneBook( void );
    ~PhoneBook( void );

    void    addContact( void );
    int     searchContact( void );
};

#endif
