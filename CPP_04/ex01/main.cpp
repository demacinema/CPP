/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:38:49 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:38:50 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n----another one---" << std::endl;

	Dog basic;
	{
	Dog tmp = basic;
	}

	std::cout << "\n--my example" << std::endl;
	Animal *animal[4];
	for (int i = 0; i < 2; i++)
		animal[i] = new Cat();
	for (int i = 2; i < 4; i++)
		animal[i] = new Dog();
	for (int i = 0; i < 4; i++)
		animal[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animal[i];
}