/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:29 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:17:38 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() //: type("Cat")
{
	type = "Cat";
	std::cout << "Default constructor of CAT called: " << type << std::endl;
}

Cat::Cat(const std::string &name) //: type(name)
{
	type = name;
	std::cout << "String constructor of CAT called: " << name << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor of CAT called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

Cat::Cat(const Cat& other) : Animal()
{
	std::cout << "Copy constructor of CAT called" << std::endl;
	type = other.type;
}

Cat &Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void Cat::makeSound()
{
	std::cout << "CAT SOUND!" << std::endl;
}