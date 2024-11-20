/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:40:57 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:40:58 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type_;

public:
	AMateria(std::string const & type);
	virtual ~AMateria();

	AMateria(const AMateria& copy_const);
	AMateria& operator=(const AMateria& assign_op);

	std::string const & getType() const; //should return the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif