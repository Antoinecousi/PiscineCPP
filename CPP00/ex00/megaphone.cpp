/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:19 by acousini          #+#    #+#             */
/*   Updated: 2022/11/14 15:10:11 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(int ac, char **av)
{
	int		i(1);
	int		j;
	char	c;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			c = std::toupper(av[i][j++]);
			std::cout << c;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
