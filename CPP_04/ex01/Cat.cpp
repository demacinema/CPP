/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:38:26 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:38:27 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    setType("Cat");
    std::cout << "Hello from Cat Constructor" << std::endl;
    _brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Bye from Cat Destructor" << std::endl;
    if (_brain)
        delete _brain;
}

Cat::Cat(const Cat& copy_const) : Animal(copy_const)
{
    std::cout << "Hello from Cat copy  Constructor" << std::endl;
    *this = copy_const;
}

Cat& Cat::operator=(const Cat& assign_op)
{
    std::cout << "Hello from Cat assignment operator" << std::endl;
    if (this != &assign_op)
    {
        _type_ = assign_op._type_;
        _brain = new Brain(*assign_op._brain);
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meo" << std::endl;
}