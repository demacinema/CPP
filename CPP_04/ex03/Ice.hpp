/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:41:30 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:41:31 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{

public:
	Ice();
	~Ice();

	Ice(const Ice& copy_const);
	Ice& operator=(const Ice& assign_op);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif