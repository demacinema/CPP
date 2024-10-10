/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:54:21 by demrodri          #+#    #+#             */
/*   Updated: 2024/10/10 20:50:19 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "CONSTRUCTORS" << std::endl;
	Zombie	zombie1;
	zombie1.announce();
	
	Zombie zombie2 ("Parameterized Constructor Zombie");
	zombie2.announce();
	std::cout << std::endl;

	std::cout << "ZOMBIE HORDE" << std::endl;
	Zombie		*horde;
	int			nbZombies;
	int			i;
	
	std::string	name = "zombie";
	nbZombies = 10;
	i = 0;
	
	horde = zombieHorde(nbZombies, name);

	while (i < nbZombies)
	{
		horde[i].announce();
		i++;
	}
	
	delete[] horde; //for freeing the array of objects (created with new[])
	std::cout << nbZombies << " ZOMBIES DESTROYED!" << std::endl;

	return (0);
}
