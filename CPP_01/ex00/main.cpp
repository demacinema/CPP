/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:20:17 by demrodri          #+#    #+#             */
/*   Updated: 2024/10/09 00:48:08 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	std::cout << "STACK" << std::endl;
	Zombie	zombie1("Foo");
	Zombie	zombie2("Foo2");
	Zombie	zombie3;

	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	randomChump("randomChumpZ");

	std::cout << std::endl;
	std::cout << "HEAP" << std::endl;
	Zombie	*heapZ;

	heapZ = newZombie("HeapFoo");
	heapZ->announce();
	delete(heapZ);

	return (0);
}