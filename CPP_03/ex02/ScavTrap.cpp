/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:35:25 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/04 15:40:28 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setEp(50);
	setAd(20);
	std::cout << "ScavTrap Default constructor called " << getName() << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	setEp(50);
	setAd(20);
	std::cout << "ScavTrap constructor called " << getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called " << getName() << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	// std::cout << target << "SCAVATTACK" << std::endl;
	if (getEp() > 0 && getHp() > 0)
	{
		std::cout << getName() <<" SCAVattacks " << target << " for " << getAd() << " points of damage!" << std::endl;
		setEp(getEp() - 1);
	}
	else if (getEp() == 0 && getHp() > 0)
		std::cout << "no SCAVenergy left for this action!" << std::endl;
	else
		std::cout << getName() << "is SCAVdead D:" << std::endl;
	
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode." << std::endl;
}
