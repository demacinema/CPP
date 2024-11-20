/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:36:15 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:36:16 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : Claptrap()
{
	setEp(50);
	setAd(20);
	std::cout << "ScavTrap Default constructor called " << getName() << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : Claptrap(name)
{
	setEp(50);
	setAd(20);
	std::cout << "ScavTrap constructor called " << getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called " << getName() << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode." << std::endl;
}
