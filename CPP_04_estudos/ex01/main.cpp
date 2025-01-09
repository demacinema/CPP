/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:16 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/09 01:17:08 by demacinema       ###   ########.fr       */
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
#include "WrongAnimal.hpp"

int main()
{
	const Animal		*animal = new Animal();
std::cin.get();
	const Animal		*cat = new Cat();
std::cin.get();
	const Animal		*dog = new Dog();
std::cin.get();
	const WrongAnimal	*wronganimal = new WrongAnimal();
std::cin.get();
	const WrongAnimal	*wrongCat = new WrongCat();
std::cin.get();
	
	std::cout << "Animal : " << animal->getType() << std::endl;
	animal->makeSound();
std::cin.get();
	std::cout << "Animal : " << cat->getType() << std::endl;
	cat->makeSound();
std::cin.get();
	std::cout << "Animal : " << dog->getType() << std::endl;
	dog->makeSound();
std::cin.get();
	std::cout << "Wrong Animal : " << wronganimal->getType() << std::endl;
	wronganimal->makeSound();
std::cin.get();
	std::cout << "Wrong cat : " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
std::cin.get();
	delete(dog);
std::cin.get();
	delete(cat);
std::cin.get();
	delete(wrongCat);
std::cin.get();
	delete(wronganimal);
std::cin.get();
	delete(animal);
}