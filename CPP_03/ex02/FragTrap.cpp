/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:35:51 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:35:52 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : Claptrap()
{
	setEp(100);
	setAd(30);
	std::cout << "FragTrap Default constructor called " << getName() << std::endl;
}

FragTrap::FragTrap(const std::string &name) : Claptrap(name)
{
	setEp(100);
	setAd(30);
	std::cout << "FragTrap constructor called " << getName() << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called " << getName() << std::endl;
}

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << getName() << " : give it to me up here! *Holds up Arm*" << std::endl;
}