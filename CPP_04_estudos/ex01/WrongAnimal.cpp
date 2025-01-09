/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:08:15 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/09 01:20:45 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() //: _type("WrongAnimal")
{
	_type = "WrongAnimal";
	std::cout << "Default constructor of WRONGANIMAL called: " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &name) //: _type(name)
{
	_type = name;
	std::cout << "String constructor of WRONGANIMAL called: " << name << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Destructor of WRONGANIMAL called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) //: WrongAnimal()
{
	std::cout << "Copy constructor of WRONGANIMAL called" << std::endl;
	_type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void WrongAnimal::setType(std::string type)
{
	_type = type;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WRONGANIMAL SOUND!" << std::endl;
}