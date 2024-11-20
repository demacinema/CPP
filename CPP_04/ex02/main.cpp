/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:40:13 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:40:14 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	//Animal animal = new dog(); //can't make that becuase of abstract class

	Dog *d = new Dog();
	Cat *c = new Cat();

	std::cout << "Dog : ";
	d->makeSound();

	std::cout << "Cat : ";
	c->makeSound();

	delete(d);
	delete(c);

	Dog German_shepherd;
	std::cout << "German Shepherd : ";
	Animal *dog_breed = &German_shepherd;
	dog_breed->makeSound(); // check leaks
}