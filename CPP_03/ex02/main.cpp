/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:36:03 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:36:04 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	Claptrap Clap("Nu-11");
	std::cout << Clap.getName() << " stats" << std::endl;
	std::cout << "Hp  " << Clap.getHp() << std::endl;
	std::cout << "Ep  " << Clap.getEp() << std::endl;
	std::cout << "Ad  " << Clap.getAd() << std::endl;
	std::cout << "--- Creating a FragTrap ---" << std::endl;
	FragTrap Frag("Wally");

	std::cout << Frag.getName() << " stats" << std::endl;
	std::cout << "Hp  " << Frag.getHp() << std::endl;
	std::cout << "Ep  " << Frag.getEp() << std::endl;
	std::cout << "Ad  " << Frag.getAd() << std::endl;
	Frag.highFiveGuys();
	Frag.attack(Clap.getName());
	Clap.takeDamage(Frag.getAd());
	Clap.attack(Frag.getName());
	Frag.takeDamage(Clap.getAd());
	Frag.beRepaired(Clap.getAd());

	return (0);
}