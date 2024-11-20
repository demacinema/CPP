/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:41:24 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:41:25 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "\033[32mHello from Ice constructor\033[0m" << std::endl;
}

Ice::~Ice()
{
    std::cout << "\033[31mBye from Ice destructor\033[0m" << std::endl;
}

Ice::Ice(const Ice &copy_const) : AMateria(copy_const)
{
    std::cout << "\033[32mHello from Ice copy constructor\033[0m" << std::endl;
}

Ice &Ice::operator=(const Ice &assign_op)
{
    std::cout << "\033[32mHello from Ice assignation operator\033[0m" << std::endl;
    AMateria::operator=(assign_op);
    return (*this);
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "\033[33m* shoots an ice bolt at " << target.getName() << " *\033[0m" << std::endl;
}