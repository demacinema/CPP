/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:08:23 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/09 01:19:19 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() //: _type("WrongCat")
{
	_type = "WrongCat";
	std::cout << "Default constructor of WRONGCAT called: " << _type << std::endl;
}

WrongCat::WrongCat(const std::string &name) //: _type(name)
{
	_type = name;
	std::cout << "String constructor of WRONGCAT called: " << name << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Destructor of WRONGCAT called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
	std::cout << "Copy constructor of WRONGCAT called" << std::endl;
	_type = other._type;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Hello from Wrong Cat assignment operator" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WRONGCAT SOUND!" << std::endl;
}