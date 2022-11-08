/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:26:44 by acousini          #+#    #+#             */
/*   Updated: 2022/08/10 10:50:20 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP


# include <iostream>
# include <string>

class Contact 
{

    
public:

    Contact( void );
    ~Contact( void );
	void			Add(void);
	void			Display(void);
	std::string		getValue(int c);
	void			setValue(int index, std::string value);
	static int		findIndex(std::string key);
	
	
private:
	static std::string	fields[5];
	std::string	_fields[5];
};

#endif
