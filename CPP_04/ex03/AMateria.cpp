/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:40:52 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:40:53 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type_(type)
{
	std::cout << "\033[32mHello from AMateria constructor\033[0m" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "\033[31mBye from AMateria destructor\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria &copy_const)
{
    std::cout << "\033[32mHello from AMateria copy constructor\033[0m" << std::endl;
    *this = copy_const;
}

AMateria &AMateria::operator=(const AMateria &assign_op)
{
    std::cout << "\033[32mHello from AMateria assignation operator\033[0m" << std::endl;
    if (this != &assign_op)
    {
        this->_type_ = assign_op._type_;
    }
    return (*this);
}

std::string const &AMateria::getType() const
{
    return (this->_type_);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "\033[32m* No use of this  " << target.getName() << " *\033[0m" << std::endl;
}