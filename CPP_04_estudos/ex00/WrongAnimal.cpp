/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:08:15 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:17:53 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() //: type("WrongAnimal")
{
	type = "WrongAnimal";
	std::cout << "Default constructor of WRONGANIMAL called: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &name) //: type(name)
{
	type = name;
	std::cout << "String constructor of WRONGANIMAL called: " << name << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WRONGANIMAL called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : Animal()
{
	std::cout << "Copy constructor of WRONGANIMAL called" << std::endl;
	type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void WrongAnimal::makeSound()
{
	std::cout << "WRONGANIMAL SOUND!" << std::endl;
}