/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:20:31 by demrodri          #+#    #+#             */
/*   Updated: 2024/10/10 20:50:10 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//default constructor function - initialize "_name" with default value
Zombie::Zombie(void) : _name("Default Constructor Zombie"){}

//parameterized constructor function - initialize "_name" with value from var name
Zombie::Zombie(std::string name) : _name(name){}

//destructor function - confirms destruction
Zombie::~Zombie(void)
{
	std::cout << _name << " is DESTROYED!" << std::endl;
}

//annouce function
void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
