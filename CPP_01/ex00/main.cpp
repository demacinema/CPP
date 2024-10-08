/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:20:17 by demrodri          #+#    #+#             */
/*   Updated: 2024/10/09 22:23:04 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "CONSTRUCTORS" << std::endl;
	Zombie	zombie1;
	zombie1.announce();
	
	Zombie zombie2 ("Parameterized Constructor Zombie");
	zombie2.announce();
	std::cout << std::endl;

	std::cout << "STACK" << std::endl;
	randomChump("Stack Zombie");
	std::cout << std::endl;
	
	std::cout << "HEAP" << std::endl;
	Zombie	*heapZ;

	heapZ = newZombie("Heap Zombie");
	heapZ->announce();
	delete(heapZ);
	std::cout << std::endl;

	return (0);
}
