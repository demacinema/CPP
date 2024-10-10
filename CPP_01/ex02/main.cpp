/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:55:54 by demacinema        #+#    #+#             */
/*   Updated: 2024/10/10 22:10:53 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "MEMORY ADRESS OF STRING VAR: " << &str << std::endl;
	std::cout << "MEMORY ADRESS OF STRING PTR: " << stringPTR << std::endl;
	std::cout << "MEMORY ADRESS OF STRING REF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "VALUE OF STRING VAR: " << str << std::endl;
	std::cout << "VALUE OF STRING PTR: " << *stringPTR << std::endl;
	std::cout << "VALUE OF STRING REF: " << stringREF << std::endl;

	return (0);
}
