/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:16 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/12 17:42:10 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal animal = new dog(); //can't make that becuase of abstract class

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

// int main()
// {

// 	std::cout << "\n----FIRST CREATION AND DELETION---" << std::endl;
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	std::cout << "\n----SECOND CREATION - NO DELETION---" << std::endl;

// 	Dog basic;
	
// std::cin.get();
// 	{
// 	Dog tmp = basic;
// 	}//insert a scope to be destroyed after leaving it

// 	std::cout << "\n--ARRAY OF ANIMALS" << std::endl;
// 	Animal *animal[4];
// 	for (int i = 0; i < 2; i++)
// 		animal[i] = new Cat();
// 	for (int i = 2; i < 4; i++)
// 		animal[i] = new Dog();
// 	for (int i = 0; i < 4; i++)
// 		animal[i]->makeSound();
// 	for (int i = 0; i < 4; i++)
// 		delete animal[i];
// }

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

// #include "Cat.hpp"
// #include "Dog.hpp"
// #include "WrongCat.hpp"
// #include "WrongAnimal.hpp"

// int main()
// {
// 	const Animal		*animal = new Animal();
// std::cin.get();
// 	const Animal		*cat = new Cat();
// std::cin.get();
// 	const Animal		*dog = new Dog();
// std::cin.get();
// 	const WrongAnimal	*wronganimal = new WrongAnimal();
// std::cin.get();
// 	const WrongAnimal	*wrongCat = new WrongCat();
// std::cin.get();
	
// 	std::cout << "Animal : " << animal->getType() << std::endl;
// 	animal->makeSound();
// std::cin.get();
// 	std::cout << "Animal : " << cat->getType() << std::endl;
// 	cat->makeSound();
// std::cin.get();
// 	std::cout << "Animal : " << dog->getType() << std::endl;
// 	dog->makeSound();
// std::cin.get();
// 	std::cout << "Wrong Animal : " << wronganimal->getType() << std::endl;
// 	wronganimal->makeSound();
// std::cin.get();
// 	std::cout << "Wrong cat : " << wrongCat->getType() << std::endl;
// 	wrongCat->makeSound();
// std::cin.get();
// 	delete(dog);
// std::cin.get();
// 	delete(cat);
// std::cin.get();
// 	delete(wrongCat);
// std::cin.get();
// 	delete(wronganimal);
// std::cin.get();
// 	delete(animal);
// }