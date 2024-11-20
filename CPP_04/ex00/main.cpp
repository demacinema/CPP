/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:24 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:37:25 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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