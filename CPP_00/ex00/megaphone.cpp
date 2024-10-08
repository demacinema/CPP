/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:38:33 by demrodri          #+#    #+#             */
/*   Updated: 2024/09/24 01:07:12 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	j = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (j < argc)
		{
			i = 0;
			while (argv[j][i])
			{
				std::cout << (char)std::toupper(argv[j][i]);
				i++;
			}
			j++;
		}
	}
	std::cout << std::endl;
	return (0);
}