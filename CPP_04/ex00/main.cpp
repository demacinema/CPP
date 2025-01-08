/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:24 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/09 00:41:05 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// std::cout << "--------------------------------------------" << std::endl;
// 	Animal animal;
// std::cout << "--------------------------------------------" << std::endl;
// 	Cat cat;
// 	Cat scat("Scat");
// std::cout << "--------------------------------------------" << std::endl;
// 	Dog dog;
// 	Dog sdog("Sdog");
// std::cout << "--------------------------------------------" << std::endl;
// 	animal.makeSound();
// 	cat.makeSound();
// 	dog.makeSound();
// std::cout << "--------------------------------------------" << std::endl;
// 	return (EXIT_SUCCESS);
// }

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal		*specie = new Animal();
	const Animal		*cat = new Cat();
	const Animal		*dog = new Dog();
	const WrongAnimal	*wrongspecie = new WrongAnimal();
	const WrongAnimal	*wrongCat = new WrongCat();
	
	std::cout << "Animal : " << specie->getType() << std::endl;
	specie->makeSound();
	std::cout << "Animal : " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << "Animal : " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "Wrong Animal : " << wrongspecie->getType() << std::endl;
	wrongspecie->makeSound();
	std::cout << "Wrong cat : " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	delete(dog);
	delete(cat);
	delete(wrongCat);
	delete(wrongspecie);
	delete(specie);
}