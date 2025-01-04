/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:34:50 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/04 15:25:13 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{	
	try
	{
	std::cout << ">>>CREATION OF CLAP AND TRAP\n";
		ClapTrap clap = ClapTrap();
		ClapTrap Trap = ClapTrap("TRAP");
		
		std::cout << clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << clap.getHp() << std::endl;
		std::cout << "Ep  " << clap.getEp() << std::endl;
		std::cout << "Ad  " << clap.getAd() << std::endl << std::endl;
		
		std::cout << Trap.getName() <<" stats" << std::endl;
		std::cout << "Hp  " << Trap.getHp() << std::endl;
		std::cout << "Ep  " << Trap.getEp() << std::endl;
		std::cout << "Ad  " << Trap.getAd() << std::endl << std::endl;
	std::cin.get();

	std::cout << ">>>CLAP ATTACKS TRAP WITH INITIAL VALUES\n";
		clap.attack(Trap.getName());
		Trap.takeDamage(clap.getAd());

		std::cout << clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << clap.getHp() << std::endl;
		std::cout << "Ep  " << clap.getEp() << std::endl;
		std::cout << "Ad  " << clap.getAd() << std::endl << std::endl;
		
		std::cout << Trap.getName() <<" stats" << std::endl;
		std::cout << "Hp  " << Trap.getHp() << std::endl;
		std::cout << "Ep  " << Trap.getEp() << std::endl;
		std::cout << "Ad  " << Trap.getAd() << std::endl << std::endl;
	std::cin.get();

	std::cout << ">>>CLAP ATTACKS TRAP WITH setAd\n";
		clap.setAd(100);
		clap.attack(Trap.getName());
		Trap.takeDamage(clap.getAd());

		std::cout << clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << clap.getHp() << std::endl;
		std::cout << "Ep  " << clap.getEp() << std::endl;
		std::cout << "Ad  " << clap.getAd() << std::endl << std::endl;
		
		std::cout << Trap.getName() <<" stats" << std::endl;
		std::cout << "Hp  " << Trap.getHp() << std::endl;
		std::cout << "Ep  " << Trap.getEp() << std::endl;
		std::cout << "Ad  " << Trap.getAd() << std::endl << std::endl;
	std::cin.get();

	std::cout << ">>>TRAP TRIES TO BE REPAIRED, CLAP TAKE DAMAGE\n";
		Trap.beRepaired(42);
		clap.takeDamage(5);
		std::cout << clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << clap.getHp() << std::endl;
		std::cout << "Ep  " << clap.getEp() << std::endl;
		std::cout << "Ad  " << clap.getAd() << std::endl << std::endl;
		
		std::cout << Trap.getName() <<" stats" << std::endl;
		std::cout << "Hp  " << Trap.getHp() << std::endl;
		std::cout << "Ep  " << Trap.getEp() << std::endl;
		std::cout << "Ad  " << Trap.getAd() << std::endl << std::endl;
	std::cin.get();

	std::cout << ">>>CLAP IS REPAIRED, CLAP SETS TO 0 EP\n";
		clap.beRepaired(5);
		clap.setEp(0);
		std::cout << clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << clap.getHp() << std::endl;
		std::cout << "Ep  " << clap.getEp() << std::endl;
		std::cout << "Ad  " << clap.getAd() << std::endl << std::endl;
		
		std::cout << Trap.getName() <<" stats" << std::endl;
		std::cout << "Hp  " << Trap.getHp() << std::endl;
		std::cout << "Ep  " << Trap.getEp() << std::endl;
		std::cout << "Ad  " << Trap.getAd() << std::endl << std::endl;
	std::cin.get();

	std::cout << ">>>CLAP TRIES TO ATTACK TRACK\n";
		clap.attack(Trap.getName());
		std::cout << clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << clap.getHp() << std::endl;
		std::cout << "Ep  " << clap.getEp() << std::endl;
		std::cout << "Ad  " << clap.getAd() << std::endl << std::endl;
		
		std::cout << Trap.getName() <<" stats" << std::endl;
		std::cout << "Hp  " << Trap.getHp() << std::endl;
		std::cout << "Ep  " << Trap.getEp() << std::endl;
		std::cout << "Ad  " << Trap.getAd() << std::endl << std::endl;
	std::cin.get();

	std::cout << ">>>TRAP TRIES TO ATTACK CLAP\n";
		Trap.attack(clap.getName());
		std::cout << clap.getName() << " stats" << std::endl;
		std::cout << "Hp  " << clap.getHp() << std::endl;
		std::cout << "Ep  " << clap.getEp() << std::endl;
		std::cout << "Ad  " << clap.getAd() << std::endl << std::endl;
		
		std::cout << Trap.getName() <<" stats" << std::endl;
		std::cout << "Hp  " << Trap.getHp() << std::endl;
		std::cout << "Ep  " << Trap.getEp() << std::endl;
		std::cout << "Ad  " << Trap.getAd() << std::endl << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	
	return (0);
}