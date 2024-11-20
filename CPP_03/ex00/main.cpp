/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:34:50 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:34:51 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	Claptrap clap = Claptrap();
	Claptrap Trap = Claptrap("Nu-11");
	
	std::cout << clap.getName() << " stats" << std::endl;
	std::cout << "Hp  " << clap.getHp() << std::endl;
	std::cout << "Ep  " << clap.getEp() << std::endl;
	std::cout << "Ad  " << clap.getAd() << std::endl;
	std::cout << Trap.getName() <<" stats" << std::endl;
	std::cout << "Hp  " << Trap.getHp() << std::endl;
	std::cout << "Ep  " << Trap.getEp() << std::endl;
	std::cout << "Ad  " << Trap.getAd() << std::endl;
	
	clap.attack(Trap.getName());
	Trap.takeDamage(clap.getAd());
	clap.setAd(100);
	clap.attack(Trap.getName());
	Trap.takeDamage(clap.getAd());
	Trap.beRepaired(42);
	clap.takeDamage(5);
	clap.beRepaired(5);
	clap.setEp(0);
	clap.attack(Trap.getName());
	Trap.attack(clap.getName());
	return (0);
}