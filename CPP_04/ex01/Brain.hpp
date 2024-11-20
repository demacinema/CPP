/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:38:17 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:38:18 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	std::string ideas[100];

	Brain();
	~Brain();

	Brain(const Brain& copy_const);
	Brain& operator=(const Brain& assign_op);
};


#endif