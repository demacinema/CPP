/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:32:48 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/12 00:07:09 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
							Brain();
		virtual				~Brain();
		
							Brain(const Brain& other);
		Brain&				operator=(const Brain& other);
		
		// std::string			getType() const;
		// void				setType(const std::string& type);
		
	// private:
		std::string			ideas[100];
};
# endif