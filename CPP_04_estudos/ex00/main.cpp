/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:16 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:16:37 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
std::cout << "--------------------------------------------" << std::endl;
	Animal animal;
std::cout << "--------------------------------------------" << std::endl;
	Cat cat("Cat");
std::cout << "--------------------------------------------" << std::endl;
	Dog dog("Dog");
std::cout << "--------------------------------------------" << std::endl;
	animal.makeSound();
	cat.makeSound();
	dog.makeSound();
std::cout << "--------------------------------------------" << std::endl;
	return (EXIT_SUCCESS);
}