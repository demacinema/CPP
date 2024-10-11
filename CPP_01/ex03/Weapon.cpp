/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:11:36 by demacinema        #+#    #+#             */
/*   Updated: 2024/10/11 16:27:40 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type) : _type(type){}

Weapon::~Weapon(){}

std::string const &Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
