/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:33:19 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:33:21 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;
	c = b;

	a.setRawBits(4);
	b.setRawBits(2);
	std::cout << a.getRawBits() << b.getRawBits() << c.getRawBits() << std::endl;
	return (0);
}
