/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:35:14 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:35:15 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	// Creating a ScavTrap
	Claptrap Clap("Nu-11");
	std::cout << Clap.getName() << " stats" << std::endl;
	std::cout << "Hp  " << Clap.getHp() << std::endl;
	std::cout << "Ep  " << Clap.getEp() << std::endl;
	std::cout << "Ad  " << Clap.getAd() << std::endl;
	std::cout << "--- Creating a ScavTrap ---" << std::endl;
	ScavTrap Scav("Wally");

	std::cout << Scav.getName() << " stats" << std::endl;
	std::cout << "Hp  " << Scav.getHp() << std::endl;
	std::cout << "Ep  " << Scav.getEp() << std::endl;
	std::cout << "Ad  " << Scav.getAd() << std::endl;
	Scav.guardGate();
	Scav.attack(Clap.getName());
	Clap.takeDamage(Scav.getAd());
	Clap.attack(Scav.getName());
	Scav.takeDamage(Clap.getAd());
	Scav.beRepaired(Clap.getAd());

	return (0);
}