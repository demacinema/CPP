/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:08:23 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:18:01 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() //: type("WrongCat")
{
	type = "WrongCat";
	std::cout << "Default constructor of WRONGCAT called: " << type << std::endl;
}

WrongCat::WrongCat(const std::string &name) //: type(name)
{
	type = name;
	std::cout << "String constructor of WRONGCAT called: " << name << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WRONGCAT called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : Animal()
{
	std::cout << "Copy constructor of WRONGCAT called" << std::endl;
	type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void WrongCat::makeSound()
{
	std::cout << "WRONGCAT SOUND!" << std::endl;
}