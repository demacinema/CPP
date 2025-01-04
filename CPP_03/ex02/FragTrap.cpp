/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:35:51 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/04 15:40:46 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	setEp(100);
	setAd(30);
	std::cout << "FragTrap Default constructor called " << getName() << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
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
	std::cout << "FragTrap " << getName() << ": HIGH FIVE ME MOTHAF**ER!" << std::endl;
}