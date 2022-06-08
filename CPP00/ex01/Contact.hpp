/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:44 by acousini          #+#    #+#             */
/*   Updated: 2022/06/07 17:32:23 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP


# include <iostream>
# include <string>

class Contact {

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phone;
    std::string secret;
    
public:

    Contact( void );
    ~Contact( void );
};

#endif
