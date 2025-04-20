/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:36:03 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/04 15:46:34 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	try
	{
	std::cout << ">>>CREATING CLAP WITH STRING\n";
		ClapTrap Clap("CLAP");
		
		std::cout << Clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Clap.getHp() << std::endl;
		std::cout << "Ep  " << Clap.getEp() << std::endl;
		std::cout << "Ad  " << Clap.getAd() << std::endl;
	std::cin.get();

	std::cout << ">>>CREATING FRAG WITH STRING\n";
		FragTrap Frag("FRAG");

		std::cout << Frag.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Frag.getHp() << std::endl;
		std::cout << "Ep  " << Frag.getEp() << std::endl;
		std::cout << "Ad  " << Frag.getAd() << std::endl;
	std::cin.get();

	std::cout << ">>>HIGH 5!\n";
		Frag.highFiveGuys();
	std::cin.get();

	std::cout << ">>>FRAG ATTACK\n";
		Frag.attack(Clap.getName());
		Clap.takeDamage(Frag.getAd());
		std::cout << Clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Clap.getHp() << std::endl;
		std::cout << "Ep  " << Clap.getEp() << std::endl;
		std::cout << "Ad  " << Clap.getAd() << std::endl << std::endl;
		std::cout << Frag.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Frag.getHp() << std::endl;
		std::cout << "Ep  " << Frag.getEp() << std::endl;
		std::cout << "Ad  " << Frag.getAd() << std::endl;
	std::cin.get();

	std::cout << ">>>CLAP ATTACK\n";
		Clap.setAd(-2);
		Clap.attack(Frag.getName());
		Frag.takeDamage(Clap.getAd());
		std::cout << Clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Clap.getHp() << std::endl;
		std::cout << "Ep  " << Clap.getEp() << std::endl;
		std::cout << "Ad  " << Clap.getAd() << std::endl << std::endl;
		std::cout << Frag.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Frag.getHp() << std::endl;
		std::cout << "Ep  " << Frag.getEp() << std::endl;
		std::cout << "Ad  " << Frag.getAd() << std::endl;
	std::cin.get();

	std::cout << ">>>FRAG REPAIR\n";
		Frag.beRepaired(Clap.getAd());
		std::cout << Clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Clap.getHp() << std::endl;
		std::cout << "Ep  " << Clap.getEp() << std::endl;
		std::cout << "Ad  " << Clap.getAd() << std::endl << std::endl;
		std::cout << Frag.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Frag.getHp() << std::endl;
		std::cout << "Ep  " << Frag.getEp() << std::endl;
		std::cout << "Ad  " << Frag.getAd() << std::endl;
	std::cin.get();

	std::cout << ">>>CREATING SCAV WITH STRING\n";
		ScavTrap Scav("SCAV");

		std::cout << Scav.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Scav.getHp() << std::endl;
		std::cout << "Ep  " << Scav.getEp() << std::endl;
		std::cout << "Ad  " << Scav.getAd() << std::endl;
	std::cin.get();

	std::cout << ">>>GUARD GATE ON\n";
		Scav.guardGate();
	std::cin.get();

	std::cout << ">>>SCAV ATTACK\n";
		Scav.attack(Clap.getName());
		Clap.takeDamage(Scav.getAd());
		std::cout << Clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Clap.getHp() << std::endl;
		std::cout << "Ep  " << Clap.getEp() << std::endl;
		std::cout << "Ad  " << Clap.getAd() << std::endl << std::endl;
		std::cout << Scav.getName() << " stats" << std::endl;
		std::cout << "Hp  " << Scav.getHp() << std::endl;
		std::cout << "Ep  " << Scav.getEp() << std::endl;
		std::cout << "Ad  " << Scav.getAd() << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}

	return (0);
}